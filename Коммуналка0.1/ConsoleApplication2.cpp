#include <iostream>
#include <sstream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <locale>
#include "Header1.h"        // Объявленные переменные
#include "functions.h"      // Функции
#include <iomanip> 

using namespace std;

int main()
{
    SetColor(378);// цвет текста и консоли
    setlocale(LC_ALL, "Russian"); // Включить локализацию RU
    
    ShowHeader();
       
    Cost[GAZ] = get_naftogaz_cost();
    ShowHeader();
    Cost[VODA] = get_vodokanal_cost();
    ShowHeader();
    Cost[SVET] = get_oblenergo_cost();
    ShowHeader();
    Cost[JEO] = get_jeo_cost();
    ShowHeader();
  
    show_final_cost();
 
    QuitFunction();

    _getch();   // Задержка окна консоли после выполнения программы
}