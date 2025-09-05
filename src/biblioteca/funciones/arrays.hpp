#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T>
int add(T arr[], int &len, T e)
{
   arr[len] = e;
   len++;
   return len;
}

template <typename T>
void insert(T arr[], int &len, T e, int p)
{
   for (int i = len - 1; i > p; i--)
   {
      arr[i] = arr[i - 1];
   }
   arr[p] = e;
   len++;
}

template <typename T>
T remove(T arr[], int &len, int p)
{
   T eliminado = arr[p];
   for (int i = p; i < len - 1; i++)
   {
      arr[i] = arr[i + 1];
   }
   len--;
   return eliminado;
}

template <typename T, typename K>
int find(T arr[], int len, K k, int cmpTK(T, K))
{
   int aux = -1;
   for (int i = 0; i < len; i++)
   {
      if (cmpTK(arr[i], k) == 0)
      {
         aux = i;
         i = len;
      }
   }
   return aux;
}

template <typename T>
int orderedInsert(T arr[], int &len, T e, int cmpTT(T, T))
{
   int i = 0;

   while (i < len && cmpTT(e, arr[i]) >= 0)
   {
      i++;
   }

   for (int j = len; j > i; j--)
   {
      arr[j] = arr[j - 1];
   }

   arr[i] = e;
   len++;

   return i;
}

template <typename T>
void sort(T arr[], int len, int cmpTT(T, T))
{
   return;
}

#endif
