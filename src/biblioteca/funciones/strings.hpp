#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int length(string s)
{
   bool aux = false;
   int stringCant = 0;
   while (!aux)
   {
      if (s[stringCant] != '\0')
      {
         stringCant++;
      }
      else
      {
         aux = true;
      }
   }

   return stringCant;
}

int charCount(string s, char c)
{
   int strLongitud = length(s);
   int cantVeces = 0;
   for (int i = 0; i <= strLongitud - 1; i++)
   {
      if (s[i] == c)
      {
         cantVeces++;
      }
   }

   return cantVeces;
}

string substring(string s, int d, int h)
{
   string resultado;
   for (int i = d; i < h; i++)
   {
      resultado += s[i];
   }
   return resultado;
}

string substring(string s, int d) // ok
{
   string resultado;
   for (int i = d; i < length(s); i++)
   {
      resultado += s[i];
   }
   return resultado;
}

int indexOf(string s, char c) // ok
{
   for (int i = 0; i < length(s); ++i)
   {
      if (s[i] == c)
      {
         return i;
      }
   }
   return -1;
}

int indexOf(string s, char c, int offSet) // ok
{
   for (int i = offSet; i < length(s); ++i)
   {
      if (s[i] == c)
      {
         return i;
      }
   }
   return -1;
}

int indexOf(string s, string toSearch) // ok
{
   for (int i = 0; i < length(s); i++)
   {
      if (s[i] == toSearch[0])
      {
         string aux;
         for (int k = i; k < i + length(toSearch); k++)
         {
            aux += s[k];
         }
         if (toSearch == aux)
         {
            return i;
         }
      }
   }
   return -1;
}

int indexOf(string s, string toSearch, int offset) // ok
{
   for (int i = offset; i < length(s); i++)
   {
      if (s[i] == toSearch[0])
      {
         string aux;
         for (int k = i; k < i + length(toSearch); k++)
         {
            aux += s[k];
         }
         if (toSearch == aux)
         {
            return i;
         }
      }
   }
   return -1;
}

int lastIndexOf(string s, char c)
{
   for (int i = s.length() - 1; i >= 0; --i)
   {
      if (s[i] == c)
      {
         return i;
      }
   }
   return -1;
}

int indexOfN(string s, char c, int n)
{
   int aux = 0;
   for (int i = 0; i < length(s); i++)
   {
      if (s[i] == c)
      {
         aux++;
         if (aux == n)
         {
            return i;
         }
      }
   }
   return -1;
}

int charToInt(char c)
{
   if (c >= '0' && c <= '9')
   {
      return c - '0'; // '0' → 0, '1' → 1, ..., '9' → 9
   }
   else if (c >= 'A' && c <= 'Z')
   {
      return c - 'A' + 10; // 'A' → 10, ..., 'Z' → 35
   }
   else if (c >= 'a' && c <= 'z')
   {
      return c - 'a' + 10; // 'a' → 10, ..., 'z' → 35
   }
   else
   {
      return -1; // Caracter no válido
   }
}

char intToChar(int i)
{
   char aux = -1;
   if (0 <= i && i <= 9)
   {
      aux = '0' + i;
      return aux;
   }
   else if (10 <= i && i <= 35)
   {
      aux = 'A' + i - 10;
      return aux;
   }
   else
   {
      return aux;
   }
}

int getDigit(int n, int i)
{
   for (int j = 0; j < i; j++)
   {
      n /= 10;
   }
   return n % 10;
}

int digitCount(int n)
{
   int digNum;
   int aux = n;
   while (aux != 0)
   {
      aux /= 10;
      digNum++;
   }
   return digNum;
}

string intToString(int i)
{
   string resultadoStr;
   char resultadoChar;
   int max = digitCount(i);
   int digitPosition = 0;
   int aux = i;
   for (int j = 0; j < max; j++)
   {
      int digitMulti = 1;
      digitPosition = j + 1;
      while (digitPosition < max)
      {
         digitMulti *= 10;
         digitPosition++;
      }
      resultadoChar = intToChar(aux / digitMulti);
      aux = aux - ((aux / digitMulti) * digitMulti);
      resultadoStr += resultadoChar;
   }
   // 12345
   return resultadoStr;
}

int stringToInt(string s, int b) // ok
{
   int resultado = 0;
   for (int i = 0; i < length(s); ++i)
   {
      int valor = charToInt(s[i]);
      if (valor < 0 || valor >= b)
      {
         return -1;
      }
      resultado = resultado * b + valor;
   }

   return resultado;
}

int stringToInt(string s) // ok
{
   int resultado;
   for (int i = 0; i < length(s); i++)
   {
      int multi = 1;
      for (int j = i; j < length(s) - 1; j++)
      {
         multi *= 10;
      }

      resultado += (charToInt(s[i]) * multi);
   }
   return resultado;
}

string charToString(char c)
{
   string aux = " ";
   aux[0] = c;
   return aux;
}

char stringToChar(string s)
{
   char aux = s[0];
   return aux;
}

string stringToString(string s)
{
   return s;
}

string doubleToString(double d)
{
   double auxd = d;
   int aux = d;
   int aux2 = d;
   int multiPos = 1;
   int numAMover = 0;
   bool repDev = false;
   while (aux % 10 != 0 && repDev == false)
   {
      auxd = (auxd * 10);
      aux = auxd;
      if (aux % 10 == 0)
      {
         repDev = true;
      }
      else
      {
         aux = auxd;
         multiPos *= 10;
         numAMover++;
      }
   }
   string resultado = intToString(aux = d);
   if (numAMover >= 1)
   {
      resultado += '.';
      aux2 *= multiPos;
      aux = d * multiPos - aux2;
      resultado += intToString(aux);
   }
   return resultado;
}

double stringToDouble(string s)
{
   int m = 0;
   int numEntPos = 0;
   int multPos = 0;
   double multDecimal = 1;
   double resultado = 0;
   bool resulComa = false;
   string resultDecimStr = "";
   string strEnt = "";
   int strLen = length(s);
   while (resulComa != true && numEntPos < strLen)
   {
      if (s[m] == '.')
      {
         resulComa = true;
         numEntPos = m;
      }
      m++;
   }
   for (int i = 0; i < (numEntPos); i++)
   {
      strEnt += s[i];
   }
   resultado += stringToInt(strEnt);
   if (resulComa == true)
   {
      while ((strLen - (numEntPos + 1)) != multPos)
      {
         multDecimal *= 0.1;
         multPos++;
      }
      for (int j = numEntPos + 1; j <= strLen; j++)
      {
         resultDecimStr += s[j];
      }
      resultado = resultado + stringToInt(resultDecimStr) * multDecimal;
   }
   return resultado;
}

bool isEmpty(string s)
{

   if (length(s) == 0)
   {
      return true;
   }
   int espNum = 0;
   for (int i = 0; i <= length(s); i++)
   {
      if (s[i] == ' ')
      {
         espNum++;
      }
   }
   if (espNum == length(s))
   {
      return true;
   }
   else
   {
      return false;
   }

   return true;
}

bool startsWith(string s, string x)
{
   if (s[0] == x[0])
   {
      string aux;
      for (int k = 0; k < length(x); k++)
      {
         aux += s[k];
      }
      if (x == aux)
      {
         return true;
      }
   }
   return false;
}

bool endsWith(string s, string x)
{
   int longS = length(s);
   int longX = length(x);
   if (s[longS - 1] == x[longX - 1])
   {
      string aux;
      for (int k = (longS - longX); k < longS; k++)
      {
         aux += s[k];
      }
      if (x == aux)
      {
         return true;
      }
   }
   return false;
}

bool contains(string s, char c)
{
   for (int i = 0; i < length(s); i++)
   {
      if (s[i] == c)
      {
         return true;
      }
   }
   return false;
}

string replace(string s, char oldChar, char newChar)
{
   string resultado = s;
   for (int i = 0; i < length(s); i++)
   {
      if (s[i] == oldChar)
      {
         resultado[i] = newChar;
      }
   }
   return resultado;
}

string insertAt(string s, int pos, char c)
{
   string resultado = "";
   if (0 < pos && pos < length(s))
   {
      for (int i = 0; i < pos; i++)
      {
         resultado += s[i];
      }
      resultado += c;
      for (int i = pos; i < length(s); i++)
      {
         resultado += s[i];
      }
   }
   return resultado;
}

string removeAt(string s, int pos)
{
   string resultado = "";
   if (0 < pos && pos < length(s))
   {
      for (int i = 0; i < pos; i++)
      {
         resultado += s[i];
      }
      for (int i = pos + 1; i < length(s); i++)
      {
         resultado += s[i];
      }
   }
   return resultado;
}

string ltrim(string s)
{
   if (s[0] == ' ')
   {
      string aux;
      int espacioPos = 0;
      while (s[espacioPos] == ' ')
      {
         espacioPos++;
      }

      for (int i = espacioPos; i < length(s); i++)
      {
         aux += s[i];
      }
      return aux;
   }
   return s;
}

string rtrim(string s)
{
   int ultEsp = length(s) - 1;
   if (s[ultEsp] == ' ')
   {
      string aux;
      int espacioPos = 0;
      while (s[ultEsp - espacioPos] == ' ')
      {
         espacioPos++;
      }

      for (int i = 0; i <= ultEsp - espacioPos; i++)
      {
         aux += s[i];
      }
      return aux;
   }
   return s;
}

string trim(string s)
{
   string aux;
   aux = rtrim(s);
   aux = ltrim(aux);
   return aux;
}

string replicate(char c, int n)
{
   string aux;
   for (int i = 0; i < n; i++)
   {
      aux += c;
   }
   return aux;
}

string spaces(int n)
{
   string aux;
   for (int i = 0; i < n; i++)
   {
      aux += ' ';
   }
   return aux;
}

string lpad(string s, int n, char c)
{
   string aux;
   for (int i = 0; i < n - length(s); i++)
   {
      aux += c;
   }
   aux += s;
   return aux;
}

string rpad(string s, int n, char c)
{
   string aux;
   aux = s;
   for (int i = (length(s)); i < n; i++)
   {
      aux += c;
   }
   return aux;
}

string cpad(string s, int n, char c)
{
   int auxInt = (((n - length(s)) / 3) + 1);
   string aux;
   for (int i = 0; i < auxInt; i++)
   {
      aux += c;
   }
   aux += s;
   for (int i = (length(aux)); i < n; i++)
   {
      aux += c;
   }
   return aux;
}

bool isDigit(char c)
{
   int aux = c;
   if (48 <= aux && aux <= 57)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool isLetter(char c)
{
   int aux = c;
   if (65 <= aux && aux <= 90 || 97 <= aux && aux <= 122)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool isUpperCase(char c)
{
   int aux = c;
   if (65 <= aux && aux <= 90)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool isLowerCase(char c)
{
   int aux = c;
   if (97 <= aux && aux <= 122)
   {
      return true;
   }
   else
   {
      return false;
   }
}

char toUpperCase(char c)
{
   int aux = c;
   char auxC;
   if (97 <= aux && aux <= 122)
   {
      auxC = (aux - 32);
      return auxC;
   }
   return c;
}

char toLowerCase(char c)
{
   int aux = c;
   char auxC;
   if (65 <= aux && aux <= 90)
   {
      auxC = (aux + 32);
      return auxC;
   }
   return c;
}

string toUpperCase(string s)
{
   string aux;
   for (int i = 0; i < length(s); i++)
   {
      aux += toUpperCase(s[i]);
   }
   return aux;
}

string toLowerCase(string s)
{
   string aux;
   for (int i = 0; i < length(s); i++)
   {
      aux += toLowerCase(s[i]);
   }
   return aux;
}

int cmpString(string a, string b)
{
   if (a != b)
   {
      int strLargo = (length(a) < length(b)) ? length(a) : length(b);
      for (int i = 0; i < strLargo; i++)
      {
         if (a[i] < b[i])
         {
            return -1;
         }
         else if (a[i] > b[i])
         {
            return 1;
         }
      }
      if (length(a) > length(b))
      {
         return 1;
      }
      return -1;
   }
   return 0;
}

int cmpDouble(double a, double b)
{
   if (a != b)
   {
      if (a > b)
      {
         return 1;
      }
      return -1;
   }
   return 0;
}

#endif
