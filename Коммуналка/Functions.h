using namespace std;
#include <iomanip>

void SetColor(int TextColor) {
    /*
    color your text in Windows console mode
    colors are 0=black 1=blue 2=green and so on to 15=white
    colorattribute = foreground + background * 16
    to get red text on yellow use 4 + 14*16 = 228
    light red on yellow would be 12 + 14*16 = 236
    */

    HANDLE  hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, TextColor);
}

void ShowHeader() {
    system("cls"); // Очистить экран консоли
    cout << WriteLine << endl;
    cout << Header << endl;
    cout << WriteLine << endl;
    cout << "Название\tСтоимость\n" << endl;
    for (int i = 0; i < 4; i++) {
        cout << BillName[i] << "\t" << Cost[i] << Uah  << endl;
    }
    cout << WriteLine << endl;
}

double CheckNum(double value){
    while (!(cin >> value) || cin.peek() != '\n' || (value > 99999999.0) || (value < 0.0)){
        cin.clear();
        while (cin.get() != '\n');
        cout << "Ошибка! Введите корректное число:" << endl;
    }
    return value;
}

void ShowInfo(double present, double previous) {
    cout << "Ошибка: Проверьте введённые данные." << endl;
    cout << "Предыдущие показания не могут быть больше текущих" << endl;
    cout << "Текущие: " << present << endl;
    cout << "Предыдущие: " << previous << endl;
    cout << WriteLine << endl;
}

void QuitFunction() {
    cout << "Завершить: + \t Заново: -" << endl;
    char X;
    cin >> X;
    switch (X) {
    case '-': {
        system("cls"); // Очистить экран консоли
        for (int i = 0; i < 4; i++) {
            Cost[i] = 0.0;
        }
        main();
    }
    default:
        quick_exit(EXIT_SUCCESS);
    }
}

double get_naftogaz_cost()
{
    double present = 0.0, previous = 0.0;
    cout << "Введите текущие показания газового счётчика:" << endl;
    present = CheckNum(present);
    cout << "Введите предыдущие показания газового счётчика:" << endl;
    previous = CheckNum(previous);

    if (present < previous) {
        ShowHeader();
        ShowInfo(present, previous);
        return get_naftogaz_cost();
    }
    else if (present == previous) {
        return 0.0;
    }
    else {
        return (present - previous) * NaftogazCost;
    }
    return 0.0;
}

double get_vodokanal_cost()
{
    double present = 0.0, previous = 0.0;
    cout << "Введите текущие показания водяного счётчика:" << endl;
    present = CheckNum(present);
    cout << "Введите предыдущие показания водяного счётчика:" << endl;
    previous = CheckNum(previous);
    
    if (present < previous) {
        ShowHeader();
        ShowInfo(present, previous);
        return get_vodokanal_cost();
    }
    else if (present == previous) {
        return 0.0;
    }
    else {
        return (present - previous) * VodokanalCost;
    }
    return 0.0;
}

double get_oblenergo_cost()
{
    double present = 0.0, previous = 0.0;
    cout << "Введите текущие показания электро счётчика:" << endl;
    present = CheckNum(present);
    cout << "Введите предыдущие показания электро счётчика:" << endl;
    previous = CheckNum(previous);
    double Diff = present - previous;
    if (Diff < 0.0) {
        ShowHeader();
        ShowInfo(present, previous);
        return get_vodokanal_cost();
    }
    else if (Diff == 0.0) {
        return 0.0;
    }
    else {
        if (Diff <= OblEnergoLimit) {
            return Diff * OblEnergoCost;
        }
        else {
            return Diff * OblEnergoCost2;
        }
    }
    return 0.0;
}

double get_jeo_cost()
{
    int Floors = 0;
    int Square = 0;
    cout << "Укажите этажность вашего дома (для частного сектора укажите 0):" << endl;
    cin >> Floors;
    if (Floors > 0) {
        cout << "Укажите жилую площадь квартиры:" << endl;
        cin >> Square;

        if (Floors > 5)
            return (Square * JEOCost * JEOCoef);
        else
            return (Square * JEOCost);
    }
    else {
        return 0.0;
    }
    return 0.0;
}

void show_final_cost() {
    double FinalCost = 0.0;

    for (int i = 0; i < 4; i++) {
        FinalCost += Cost[i];
    }
    printf("Итоговая цена: \n"); // для понимания сколько брать кредина 
    cout << FinalCost << " " << Uah << endl;
    cout << setw(15) << setprecision(5)  << "Комиссия: " << FinalCost * 0.005 << " " << Uah << " (0.5%)" << endl; // Пример хардкода
    cout << "Итого: " << FinalCost * 1.005 << " " << Uah << endl;
    cout << WriteLine << endl;
}