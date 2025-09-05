
#ifndef _MAIN
#define _MAIN

#include <iostream>
#include <windows.h>
#include <typeinfo>
#include <string>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/parte2/Array.hpp"
#include "biblioteca/tads/parte2/Map.hpp"
#include "biblioteca/tads/parte2/List.hpp"
#include "biblioteca/tads/parte2/Stack.hpp"
#include "biblioteca/tads/parte2/Queue.hpp"
#include "biblioteca/tads/parte1/Coll.hpp"
#include "biblioteca/tads/parte1/MultidimColl.hpp"
using namespace std;
template <typename T>
void probarColl()
{
   char aux;
   cin >> aux;
   Coll<T> c = coll<T>(aux);
   cout << c.sep << endl;
}

struct Persona
{
   int dni;
   string nom;
   Persona(int d, string n)
   {
      dni = d;
      nom = n;
   }
};

int cmpPersonaDNI(Persona p, int d)
{
   return p.dni - d;
}
int cmpInt(int a, int b) { return a - b; }

int main()
{
   int numEjer;
   cout << "Ingrese el ejercicio que quiera hacer" << endl;
   cin >> numEjer;
   switch (numEjer)
   {

   case 55:
   {
      string a[10]; // array
      int len = 0;  // longitud
      add<string>(a, len, "John");
      add<string>(a, len, "Paul");
      add<string>(a, len, "George");
      add<string>(a, len, "Ringo");
      // recorro y muestro
      for (int i = 0; i < len; i++)
      {
         cout << a[i] << endl;
      }

      break;
   }
   case 56:
   {
      // array y longitud
      string a[10];
      int len = 0;
      // agrego elementos
      insert<string>(a, len, "John", 0);
      insert<string>(a, len, "Paul", 0);
      insert<string>(a, len, "George", 0);
      insert<string>(a, len, "Ringo", 0);
      // recorro y muestro
      for (int i = 0; i < len; i++)
      {
         cout << a[i] << endl; // SALIDA: Ringo,George,Paul,John
      }
      break;
   }
   case 57:
   {

      // array y longitud
      string a[10];
      int len = 0;
      // agrego elementos
      add<string>(a, len, "John");
      add<string>(a, len, "Paul");
      add<string>(a, len, "George");
      add<string>(a, len, "Ringo");
      while (len > 0)
      {
         cout << remove<string>(a, len, 0) << endl;
      }
      break;
   }
   case 58:
   {
      int len = 3;
      Persona arr[] = {Persona(10, "Pablo"), Persona(20, "Pedro"), Persona(30, "Juan")};

      int pos = find<Persona, int>(arr, len, 20, cmpPersonaDNI);

      cout << pos << endl; // SALIDA: 1

      break;
   }
   case 59:
   {
      // funcion de comparacion

      int arr[10] = {1, 2, 3, 5, 6, 7, 8}; // array
      int len = 7;                         // longitud
      int pos = orderedInsert<int>(arr, len, 4, cmpInt);
      cout << pos << endl;
      break;
   }
   case 60:
   {
      int arr[] = {5, 4, 3, 2, 1}; // array
      int len = 5;                 // longitud
      // ordeno y muestro
      sort<int>(arr, len, cmpInt);
      for (int i = 0; i < len; i++)
      {
         cout << arr[i] << endl;
      }
      break;
   }

   case 61:
   {

      break;
   }

   default:

      break;
   }
   cin.ignore();
   cin.get();
}
#endif
