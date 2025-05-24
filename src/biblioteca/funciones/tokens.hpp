#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s, char sep)
{
   int aux = length(s) > 1 ? 1 : 0;
   if (aux > 0)
   {
      for (int i = 0; i < length(s); i++)
      {
         if (s[i] == sep && s[i + 1] != '\0')
         {
            aux++;
         }
      }
   }
   return aux;
}

void addToken(string &s, char sep, string t)
{
   if (length(s) > 0)
   {
      s += sep + t;
   }
   else
   {
      s = t;
   }
}

string getTokenAt(string s, char sep, int i)
{
   string aux = "";
   int a = (i == 0) ? a = 0 : a = indexOfN(s, '|', i) + 1;
   int b = (i == (tokenCount(s, sep) - 1)) ? b = length(s) : b = indexOfN(s, '|', i + 1);
   for (int k = a; k < b; k++)
   {
      aux += s[k];
   }
   return aux;
}

void removeTokenAt(string &s, char sep, int i)
{
   string aux;
   int longString = tokenCount(s, sep);
   for (int k = 0; k < longString; k++)
   {
      if (k != i)
      {
         if (aux == "")
         {
            aux += getTokenAt(s, sep, k);
         }
         else
         {
            aux += sep + getTokenAt(s, sep, k);
         }
      }
   }
   s = aux;
}

void setTokenAt(string &s, char sep, string t, int i)
{
   string aux;
   int longString = tokenCount(s, sep);
   for (int k = 0; k < longString; k++)
   {
      if (k == i)
      {
          if (aux == "")
         {
            aux += t;
         }
         else
         {
            aux += sep + t;
         }
      }
      else
      {
         if (aux == "")
         {
            aux += getTokenAt(s, sep, k);
         }
         else
         {
            aux += sep + getTokenAt(s, sep, k);
         }
      }
   }
   s = aux;
}

int findToken(string s, char sep, string t)
{
   int sepCount = 0;
   cout << s[15] << endl;
   for (int i = 0; i < length(s); i++)
   {
      if(sep == s[i])
      {
         sepCount++;
      }
      if (s[i] == t[0])
      {
         string aux;
         for (int k = i; k < i + length(t); k++)
         {
            aux += s[k];
         }
         if (t == aux)
         {
            return sepCount;
         }
      }
   }
   return -1;
   
}

#endif
