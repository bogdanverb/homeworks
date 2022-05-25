#include <string>
using namespace std;

int main();

string BillName[4] = { "Нафтогаз", "Водоканал", "Облэнерго", "ЖЭО N1    " };

const double NaftogazCost	= 7.95;
const double VodokanalCost	= 45.5;
const double OblEnergoCost	= 1.440;
const double OblEnergoCost2 = 1.680;


const double OblEnergoLimit = 250.0;
const double JEOCost = 4.92;
const double JEOCoef = 1.15;

string WriteLine = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
string Header = "Програма расчёта стоимости коммунальных услуг";
string Bottom = "Стоимость коммунальных услуг составляет:";
string Uah = " UAH";


#define GAZ 0
#define VODA 1
#define SVET 2
#define JEO 3

double Cost[4];
double Counter[4][2];