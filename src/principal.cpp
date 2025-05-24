
#ifndef _MAIN
#define _MAIN

#include <iostream>
#include <windows.h>
#include <typeinfo>
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

int main()
{
   int numEjer;
   cout << "Ingrese el ejercicio que quiera hacer" << endl;
   cin >> numEjer;
   switch (numEjer)
   {
   case 1:
   {
      string aux, s;
      int longitudStr, s1;
      cout << "Ingrese un string y le dira la longitud del string" << endl;
      getline(cin, aux);
      longitudStr = length(aux);
      s = "";
      s1 = length(s);
      cout << "La longitud del string es: " << longitudStr;
      cout << "La longitud del string es: " << s1;
      break;
   }
   case 2:
   {
      string aux;
      char letraAEncontrar;
      int vecesSale;
      cout << "Ingrese oracion" << endl;
      cin.ignore();
      getline(cin, aux);
      cout << "Ingrese letra" << endl;
      cin >> letraAEncontrar;

      vecesSale = charCount(aux, letraAEncontrar);
      cout << "Veces que sale: " << vecesSale << endl;
      break;
   }
   case 3:
   {
      string s = "Esto es una prueba";
      string x = substring(s, 2, length(s));
      cout << x << endl;
      break;
   }
   case 4:
   {
      string s = "Esto es una prueba";
      string x = substring(s, 2);
      cout << x << endl;
      break;
   }
   case 5:
   {
      string s = "Esto es una prueba";
      int p = indexOf(s, 'e');
      cout << p << endl;
      break;
   }
   case 6:
   {
      string s = "Esto es una prueba";
      int p = indexOf(s, 'e', 0);
      cout << p << endl; // muestra: 5
      p = indexOf(s, 'e', 12);
      cout << p << endl;
      break;
   }
   case 7:
   {
      string s = "Esto es una prueba";
      int p = indexOf(s, "una");
      cout << p << endl; // muestra: 8
      p = indexOf(s, "jamon");
      cout << p << endl; // muestra: algun valor negativo
      break;
   }
   case 8:
   {
      string s = "Esta funcion es la funcion mas dificil";
      int p = indexOf(s, "funcion", 0);
      cout << p << endl; // muestra: 5
      p = indexOf(s, "funcion", 13);
      cout << p << endl; // muestra: 19
      break;
   }
   case 9:
   {
      string s = "Esto es una prueba";
      int p = lastIndexOf(s, 'e');
      cout << p << endl;
      break;
   }
   case 10:
   {
      string s = "John|Paul|George|Ringo";
      int p = indexOfN(s, '|', 1);
      cout << p << endl; // muestra: 4
      p = indexOfN(s, '|', 2);
      cout << p << endl; // muestra: 9
      p = indexOfN(s, '|', 3);
      cout << p << endl; // muestra: 16
      p = indexOfN(s, '|', 4);
      cout << p << endl; // muestra: -1
      break;
   }
   case 11:
   {
      char c = '2';
      int n = charToInt(c); // retorna: 2
      cout << n << endl;
      c = 'D';
      n = charToInt(c); // retorna: 13
      cout << n << endl;
      break;
   }
   case 12:
   {
      int i = 2;
      char c = intToChar(i);
      cout << c << endl; // muestra: 2
      i = 13;
      c = intToChar(i);
      cout << c << endl; // muestra: D
      cout << "Tipo de variable: " << typeid(c).name() << endl;
      break;
   }
   case 13:
   {
      int n = 12345;
      int i = 0;
      int r = getDigit(n, i);
      cout << r << endl; // muestra: 5
      i = 1;
      r = getDigit(n, i);
      cout << r << endl; // muestra: 4
      break;
   }
   case 14:
   {
      int n = 12345;
      int i = digitCount(n);
      cout << i << endl; // muestra: 5
      break;
   }
   case 15:
   {
      int i = 12345;
      string s = intToString(i);
      cout << s << endl;
      break;
   }
   case 16:
   {
      string s = "10";
      int i = stringToInt(s, 10);
      cout << i << endl; // 10
      i = stringToInt(s, 2);
      cout << i << endl; // 2
      i = stringToInt(s, 16);
      cout << i << endl; // 16
      s = "12AB";
      i = stringToInt(s, 16);
      cout << i << endl; // 4779
      break;
   }
   case 17:
   {
      string s = "12345";
      int i = stringToInt(s);
      cout << i << endl; // muestra: 12345
      break;
   }
   case 18:
   {
      char c = 'A';
      string s = charToString(c);
      cout << s << endl;         // muestra: A
      cout << length(s) << endl; // muestra: 1
      c = ' ';
      s = charToString(c);
      cout << s << endl;         // muestra: [VACIO]
      cout << length(s) << endl; // muestra: 1
      break;
   }
   case 19:
   {
      string s = "A";
      char c = stringToChar(s);
      cout << c << endl;      // muestra: A
      cout << (int)c << endl; // muestra: 65
      s = " ";
      c = stringToChar(s);
      cout << c << endl;      // muestra: [VACIO]
      cout << (int)c << endl; // muestra: 32, ASCII de ' '
      break;
   }
   case 20:
   {
      string s = stringToString("Hola");
      cout << s << endl; // muestra: Hola
      break;
   }
   case 21:
   {
      double d = 123.4564;
      string s = doubleToString(d);
      cout << s << endl; // muestra: 123.4
      break;
   }
   case 22:
   {
      string s = "1234.56";
      double d = stringToDouble(s);
      cout << d << endl; // muestra: 123.4

      break;
   }
   case 23:
   {
      string s = "";
      cout << boolalpha;
      bool resultado = (bool)isEmpty(s);
      cout << resultado << endl; // true
      s = "Hola";
      resultado = (bool)isEmpty(s);
      cout << resultado << endl; // false
      s = " ";
      resultado = (bool)isEmpty(s);
      cout << resultado << endl; // false
      break;
   }
   case 24:
   {
      string s1 = "cursoDeAlgoritmos";
      string s2 = "curso";
      if (startsWith(s1, s2))
      {
         cout << s2 << " es prefijo de: " << s1 << endl;
      }
      else
      {
         cout << s2 << " NO es prefijo de: " << s1 << endl;
      }
      break;
   }
   case 25:
   {
      string s1 = "cursoDeAlgoritmos";
      string s2 = "Algoritmos";
      if (endsWith(s1, s2))
      {
         cout << s2 << " es sufijo de: " << s1 << endl;
      }
      else
      {
         cout << s2 << " NO es sufijo de: " << s1 << endl;
      }
      break;
   }
   case 26:
   {
      string s = "abcd";
      char c = 'b';
      if (contains(s, c))
      {
         cout << s << " contiene a: " << c << endl;
      }
      c = 'X';
      if (!contains(s, c))
      {
         cout << s << " NO contiene a: " << c << endl;
      }
      break;
   }
   case 27:
   {
      string s = "Esto es una prueba";
      string r = replace(s, 'e', 'X');
      cout << r << endl; // SALIDA: Esto Xs una pruXba
      break;
   }
   case 28:
   {
      string s = "Esto es una prueba";
      int pos = 6;
      char c = 'X';
      string r = insertAt(s, pos, c);
      cout << r << endl; // SALIDA: Esto eXs una prueba
      break;
   }
   case 29:
   {
      string s = "Esto es una prueba";
      int pos = 7;
      string r = removeAt(s, pos);
      cout << r << endl; // SALIDA: Esto esuna prueba
      break;
   }
   case 30:
   {
      string s = " Esto es una prueba";
      string r = ltrim(s);
      cout << "[" << r << "]" << endl; // [Esto es una prueba]
      // sin espacios
      s = "Esto es una prueba";
      r = ltrim(s);
      cout << "[" << r << "]" << endl; // [Esto es una prueba]
      // con espacios a izquierda y derecha
      s = "                    Esto es una prueba ";
      r = ltrim(s);
      cout << "[" << r << "]" << endl; // [Esto es una prueba ]
      break;
   }
   case 31:
   {
      // con espacios a derecha
      string s = "Esto es una prueba                    ";
      string r = rtrim(s);
      cout << "[" << r << "]" << endl; // [Esto es una prueba]
      // sin espacios
      s = "Esto es una prueba";
      r = rtrim(s);
      cout << "[" << r << "]" << endl; // [Esto es una prueba]
      // con espacios a izquierda y derecha
      s = " Esto es una prueba ";
      r = rtrim(s);
      cout << "[" << r << "]" << endl; // [ Esto es una prueba]
      break;
   }
   case 32:
   {
      // con espacios a izquierda y derecha
      string s = "            Esto es una prueba            ";
      string r = trim(s);
      cout << "[" << r << "]" << endl; // [Esto es una prueba]
      // con espacios dentro de la cadena
      s = "Esto es una prueba";
      r = rtrim(s);
      cout << "[" << r << "]" << endl; // [Esto es una prueba]
      break;
   }
   case 33:
   {
      int n = 5;
      char c = 'X';
      string r = replicate(c, n);
      cout << "[" << r << "]" << endl; // muestra: [XXXXX]
      c = ' ';
      r = replicate(c, n);
      cout << "[" << r << "]" << endl; // muestra: [ ]
      break;
   }
   case 34:
   {
      int n = 5;
      string r = spaces(n);
      // muestra: [ ] (cinco espacios)
      cout << "[" << r << "]" << endl;
      break;
   }
   case 35:
   {
      string s = "Hola";
      int n = 10;
      char c = 'X';
      string r = lpad(s, n, c);
      cout << "[" << r << "]" << endl; // muestra: [XXXXXXHola]
      break;
   }
   case 36:
   {
      string s = "Hola";
      int n = 10;
      char c = 'X';
      string r = rpad(s, n, c);
      cout << "[" << r << "]" << endl; // muestra: [HolaXXXXXX]
      break;
   }
   case 37:
   {
      string s = "Hola";
      int n = 10;
      char c = 'X';
      string r = cpad(s, n, c);
      cout << "[" << r << "]" << endl; // muestra: [XXXHolaXXX]
      break;
   }
   case 38:
   {
      char c = '9';
      if (isDigit(c))
      {
         cout << c << " es digito" << endl; // SALIDA
      }
      c = 'A';
      if (!isDigit(c))
      {
         cout << c << " NO es digito" << endl; // SALIDA
      }

      break;
   }
   case 39:
   {
      char c = 'X';
      if (isLetter(c))
      {
         cout << c << " es letra" << endl; // SALIDA
      }
      c = '9';
      if (!isLetter(c))
      {
         cout << c << " NO es letra" << endl; // SALIDA
      }
      break;
   }
   case 40:
   {
      char c = 'X';
      if (isUpperCase(c))
      {
         cout << c << " es letra mayuscula" << endl; // SALIDA
      }
      c = 'x';
      if (!isUpperCase(c))
      {
         cout << c << " NO es mayuscula" << endl; // SALIDA
      }

      break;
   }
   case 41:
   {
      char c = 'a';
      if (isLowerCase(c))
      {
         cout << c << " es letra minuscula" << endl; // SALIDA
      }
      c = 'A';
      if (!isLowerCase(c))
      {
         cout << c << " NO es minuscula" << endl; // SALIDA
      }

      break;
   }
   case 42:
   {
      char c = 'a';
      char r = toUpperCase(c);
      cout << r << endl; // Salida: A (convierte a mayuscula)
      c = 'B';
      r = toUpperCase(c);
      cout << r << endl; // Salida: B (ya era mayuscula)
      c = '9';
      r = toUpperCase(c);
      cout << r << endl; // Salida: 9 (no es una letra)
      break;
   }
   case 43:
   {
      char c = 'A';
      char r = toLowerCase(c);
      cout << r << endl; // Salida: a (convierte a minuscula)
      c = 'b';
      r = toLowerCase(c);
      cout << r << endl; // Salida: b (ya era minuscula)
      c = '9';
      r = toLowerCase(c);
      cout << r << endl; // Salida: 9 (no es una letra)
      break;
   }
   case 44:
   {
      string s = "hola";
      string r = toUpperCase(s);
      cout << r << endl; // Salida: HOLA
      break;
   }
   case 45:
   {
      string s = "HOLA";
      string r = toLowerCase(s);
      cout << r << endl; // Salida: hola
      break;
   }
   case 46:
   {
      string s1 = "Carlosos";
      string s2 = "Carlos";
      if (cmpString(s1, s2) < 0)
      {
         cout << s1 << " es menor que: " << s2 << endl;
      }
      else if (cmpString(s1, s2) > 0)
      {
         cout << s1 << " es mayor que: " << s2 << endl;
      }
      else
      {
         cout << s1 << " es igual que: " << s2 << endl;
      }
      break;
   }
   case 47:
   {
      double x = 25.7;
      double y = 36.9;
      if (cmpDouble(x, y) < 0)
      {
         cout << x << " es menor que: " << y << endl;
      }
      else if (cmpDouble(x, y) > 0)
      {
         cout << x << " es mayor que: " << y << endl;
      }
      else
      {
         cout << x << " es igual que: " << y << endl;
      }
      break;
   }
   case 48:
   {
      string s = "John|Paul|George|Ringo";
      char sep = '|';
      int n = tokenCount(s, sep);
      cout << n << endl; // Salida: 4
      s = "John";
      sep = '|';
      n = tokenCount(s, sep);
      cout << n << endl; // Salida: 1
      s = "";
      sep = '|';
      n = tokenCount(s, sep);
      cout << n << endl; // Salida: 0
      break;
   }
   case 49:
   {
      string s = "";
      char sep = '|';
      addToken(s, sep, "John");
      cout << s << endl; // Salida: John
      addToken(s, sep, "Paul");
      cout << s << endl; // Salida: John|Paul
      addToken(s, sep, "George");
      cout << s << endl; // Salida: John|Paul|George
      addToken(s, sep, "Ringo");
      cout << s << endl; // Salida: John|Paul|George|Ringo
      break;
   }
   case 50:
   {
      string s = "John|Paul|George|Ringo";
      char sep = '|';
      int pos = 0;
      string t = getTokenAt(s, sep, pos);
      cout << t << endl; // Salida: John
      pos = 1;
      t = getTokenAt(s, sep, pos);
      cout << t << endl; // Salida: Paul
      pos = 2;
      t = getTokenAt(s, sep, pos);
      cout << t << endl; // Salida: George
      pos = 3;
      t = getTokenAt(s, sep, pos);
      cout << t << endl; // Salida: Ringo
      break;
   }
   case 51:
   {
      string s = "John|Paul|George|Ringo";
      char sep = '|';
      int i = 2;
      removeTokenAt(s, sep, i);
      cout << s << endl; // Salida: John|Paul|Ringo
      i = 0;
      removeTokenAt(s, sep, i);
      cout << s << endl; // Salida: Paul|Ringo
      break;
   }
   case 52:
   {
      string s = "John|Paul|George|Ringo";
      char sep = '|';
      int i = 1;
      string t = "McCartney";
      setTokenAt(s, sep, t, i);
      cout << s << endl; // Salida: John|McCartney|George|Ringo
      break;
   }
   case 53:
   {
      string s = "John|Paul|George|Ringo";
      char sep = '|';
      string t = "Paul";
      int p = findToken(s, sep, t);
      cout << p << endl; // Salida: 1
      t = "Ringo";
      p = findToken(s, sep, t);
      cout << p << endl; // Salida: 0
      break;
   }

   default:

      break;
   }
   cin.ignore();
   cin.get();
}
#endif
