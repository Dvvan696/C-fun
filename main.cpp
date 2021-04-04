#include <iostream>
#include "nunbersHome.h"
using namespace std;
void inputValue(string aTitle, bool *pValue ) // проверка на bool значение ( черт знает что введут)
{
    int value = 5;

    do{
        cout << aTitle;
        cin >> value;

    } while ( value != 0 && value != 1 );

    *pValue = value;
}

Sig EnterSig()  // для приема сигнала
{
    Sig x;

    inputValue( "Enter first signal :\t", &x.x1 );
    inputValue( "Enter second signal :\t", &x.x2 );
    inputValue( "Enter third signal :\t", &x.x3 );

    return x;
}
bool Answer_check(string qes,bool *out) // проверка на верность ввода
{
    char answer;
    cout << qes;
    cin >> answer;
    if(answer == 'Y' || answer == 'y')
        *out=!*out;
    if (answer != 'N' || answer != 'n');
    else
    {
        do {
            cout << "Enter correct answer:\t";
            cin >> answer;
        } while (answer != 'Y' && answer != 'y' && answer !='N' && answer !='n');
    }
    return *out;
}
Blocks User_Changes( Blocks &pros) //замена блоков
{


Answer_check("Do you want invert 1 block? Y/N  ",&pros.or1);
Answer_check("Do you want invert 2 block? Y/N  ",&pros.or2);
Answer_check("Do you want invert 3 block? Y/N  ",&pros.or3);
Answer_check("Do you want invert 4 block? Y/N  ",&pros.and4);
Answer_check("Do you want invert 5 block? Y/N  ",&pros.and5);
Answer_check("Do you want invert 6 block? Y/N  ",&pros.and6);
Answer_check("Do you want invert 7 block? Y/N  ",&pros.or7);

return pros;
}
Outs Process( Sig &x, Blocks &pros, Outs &ou ) // логичские операции из схемы
{
    if (pros.or1 == 1) {
        ou.out1 = x.x1 + x.x2 + x.x3;
        ou.out1 = !ou.out1;
    }
    else
        ou.out1 = x.x1 + x.x2 + x.x3;
    if (pros.or2 == 1)
    {

        ou.out2 = x.x1 + x.x2 + x.x3;
        ou.out2 = !ou.out2;
    }
    else
        ou.out2 = x.x1 + x.x2 + x.x3;
    if (pros.or3 == 1)
    {
        ou.out3 = x.x1 + x.x2 + x.x3;
        ou.out3 = !ou.out3;
    }
    else
        ou.out3 = x.x1 + x.x2 + x.x3;
    if (pros.and4 == true) {
        ou.out4 = ou.out1 * ou.out2 * ou.out3;
        ou.out4 = !ou.out4;
    }
    else

        ou.out4 = ou.out1 * ou.out2 * ou.out3;



    if (pros.and5 == true) {
        ou.out5 = ou.out3 * x.x1;
        ou.out5 = !ou.out5;
    }
        else

        ou.out5 = ou.out3 * x.x1;


    if (pros.and6 == true) {
        ou.out6 = x.x1 * x.x2;
        ou.out6 = !ou.out6;
    }
        else

        ou.out6 = x.x1 * x.x2;


    if (pros.or7==true) {
        ou.out7 = ou.out4 + ou.out5 + ou.out6;
        ou.out7 = !ou.out7;
    }
        else

        ou.out7 = (ou.out4 + ou.out5 + ou.out6);


    return ou;
}
int main() // дом пуджа
{
    setlocale(LC_ALL, "Russian");
    cout << "Выполнял работу: " << "Голышкин Павел Александрович\n";
    cout << "Группа: " << "ИС-29\n";
    cout << "Задание: " << "По имеющейся логической схеме и выходным сигналам определить значения выходных сигналов. Предусмотреть возможность редактирования (инвертирование выходов отдельных логических элементов) схемы пользователем\n";
    cout << "СХЕМА ПСЕВДО-ГРАФИКОЙ\n";
    Sig x; //входной сигнал
    x = EnterSig();
    Blocks pros; //логические блоки
    Outs ou; //выходы
    User_Changes(pros);

    ou = Process( x, pros, ou );

    for (int i=0;i<100;i++)
    {
     cout<<"Calculating process ends on "<<i<<"%\n"<<endl;
    }
cout<<"Y="<<ou.out7;
    return 0;
}