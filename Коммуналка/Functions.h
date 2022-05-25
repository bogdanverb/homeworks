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
    system("cls"); // �������� ����� �������
    cout << WriteLine << endl;
    cout << Header << endl;
    cout << WriteLine << endl;
    cout << "��������\t���������\n" << endl;
    for (int i = 0; i < 4; i++) {
        cout << BillName[i] << "\t" << Cost[i] << Uah  << endl;
    }
    cout << WriteLine << endl;
}

double CheckNum(double value){
    while (!(cin >> value) || cin.peek() != '\n' || (value > 99999999.0) || (value < 0.0)){
        cin.clear();
        while (cin.get() != '\n');
        cout << "������! ������� ���������� �����:" << endl;
    }
    return value;
}

void ShowInfo(double present, double previous) {
    cout << "������: ��������� �������� ������." << endl;
    cout << "���������� ��������� �� ����� ���� ������ �������" << endl;
    cout << "�������: " << present << endl;
    cout << "����������: " << previous << endl;
    cout << WriteLine << endl;
}

void QuitFunction() {
    cout << "���������: + \t ������: -" << endl;
    char X;
    cin >> X;
    switch (X) {
    case '-': {
        system("cls"); // �������� ����� �������
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
    cout << "������� ������� ��������� �������� ��������:" << endl;
    present = CheckNum(present);
    cout << "������� ���������� ��������� �������� ��������:" << endl;
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
    cout << "������� ������� ��������� �������� ��������:" << endl;
    present = CheckNum(present);
    cout << "������� ���������� ��������� �������� ��������:" << endl;
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
    cout << "������� ������� ��������� ������� ��������:" << endl;
    present = CheckNum(present);
    cout << "������� ���������� ��������� ������� ��������:" << endl;
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
    cout << "������� ��������� ������ ���� (��� �������� ������� ������� 0):" << endl;
    cin >> Floors;
    if (Floors > 0) {
        cout << "������� ����� ������� ��������:" << endl;
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
    printf("�������� ����: \n"); // ��� ��������� ������� ����� ������� 
    cout << FinalCost << " " << Uah << endl;
    cout << setw(15) << setprecision(5)  << "��������: " << FinalCost * 0.005 << " " << Uah << " (0.5%)" << endl; // ������ ��������
    cout << "�����: " << FinalCost * 1.005 << " " << Uah << endl;
    cout << WriteLine << endl;
}