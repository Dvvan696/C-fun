#include <iostream>
#include <locale>
#include "main.h"
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

void inputValue(string Title, bool* Value) // ïðîâåðêà íà bool çíà÷åíèå ( ÷åðò çíàåò ÷òî ââåäóò)
{
    string value;
    bool x;

    do {
        cout << Title;
        getline(cin,value);

    } while (value != "0" && value != "1");
    if (value == "0")
    {
        x = false;
    }
    else
    {
        x = true;
    }

    *Value = x;
}

Sig EnterSig()  // äëÿ ïðèåìà ñèãíàëà
{
    Sig x;

    inputValue("Enter first signal :\t", &x.x1);
    inputValue("Enter second signal :\t", &x.x2);
    inputValue("Enter third signal :\t", &x.x3);

    return x;
}

bool AnswerCheck(string qes, bool *out) // ïðîâåðêà íà âåðíîñòü ââîäà
{
    
    string answer;
    cout << qes;

    do {
        
        getline(cin, answer);
        
        if (answer.length() == 1) {
            switch (tolower(answer[0])) {
            case 'y':
                *out = !*out;
                return *out;

            case 'n':
                return *out;
            default:
                break;
            }

            do {
                cout << "Enter correct answer:\t";
                cin >> answer;
            } while (tolower(answer[0]) != 'y' && tolower(answer[0]) != 'n');
        }
        else {
            cout << "Please enter 1 symbol: ";
        }
    } while (tolower(answer[0]) != 'y' || tolower(answer[0]) != 'n');
}

Blocks UserChanges(Blocks& pros) //çàìåíà áëîêîâ
{
    AnswerCheck("Do you want invert 1 block? Y/N  ", &pros.or1);
    AnswerCheck("Do you want invert 2 block? Y/N  ", &pros.or2);
    AnswerCheck("Do you want invert 3 block? Y/N  ", &pros.or3);
    AnswerCheck("Do you want invert 4 block? Y/N  ", &pros.and4);
    AnswerCheck("Do you want invert 5 block? Y/N  ", &pros.and5);
    AnswerCheck("Do you want invert 6 block? Y/N  ", &pros.and6);
    AnswerCheck("Do you want invert 7 block? Y/N  ", &pros.or7);

    return pros;
}

Outs Process(Sig& x, Blocks& pros, Outs& ou) // ëîãè÷ñêèå îïåðàöèè èç ñõåìû
{
    if (pros.or1 == 1) {
        ou.out1 = x.x1 + x.x2 + x.x3;
        ou.out1 = !ou.out1;
    }
    else
        ou.out1 = x.x1 + x.x2 + x.x3;
    if (pros.or2 == 1) {

        ou.out2 = x.x1 + x.x2 + x.x3;
        ou.out2 = !ou.out2;
    }
    else
        ou.out2 = x.x1 + x.x2 + x.x3;
    if (pros.or3 == 1) {
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


    if (pros.or7 == true) {
        ou.out7 = ou.out4 + ou.out5 + ou.out6;
        ou.out7 = !ou.out7;
    }
    else

        ou.out7 = (ou.out4 + ou.out5 + ou.out6);


    return ou;
}

int main() // äîì ïóäæà
{
    setlocale(LC_ALL, "Russian");
    cout << "Âûïîëíÿë ðàáîòó: " << "Ãîëûøêèí Ïàâåë Àëåêñàíäðîâè÷\n";
    cout << "Ãðóïïà: " << "ÈÑ-29\n";
    cout << "Çàäàíèå: "
        << "Ïî èìåþùåéñÿ ëîãè÷åñêîé ñõåìå è âûõîäíûì ñèãíàëàì îïðåäåëèòü çíà÷åíèÿ âûõîäíûõ ñèãíàëîâ. Ïðåäóñìîòðåòü âîçìîæíîñòü ðåäàêòèðîâàíèÿ (èíâåðòèðîâàíèå âûõîäîâ îòäåëüíûõ ëîãè÷åñêèõ ýëåìåíòîâ) ñõåìû ïîëüçîâàòåëåì\n";
    cout << "ÑÕÅÌÀ ÏÑÅÂÄÎ-ÃÐÀÔÈÊÎÉ\n";
    cout << "       ___     ___   _____ \n"
            "x1--ã-|1+|°----|4|---|   |-\n"
            "    | |——|  ã--| |   | 7 | \n"
            "x2--|-|2+|°-!ã-|_|  ã|_+_| \n"
            "    | |——|   | ___  !  |   \n"
            "x3----|3+|°--!-|5|--!  |   \n"
            "   |__________ã|&|     |   \n"
            "   |          ___      |   \n"
            "   |----------|6|------!   \n"
            "              |&|          \n";
    Sig x;
    x = EnterSig();
    Blocks pros; //ëîãè÷åñêèå áëîêè
    Outs ou; //âûõîäû
    UserChanges(pros);

    ou = Process(x, pros, ou);

    for (int i = 0; i < 100; i++) {
        cout << "Calculating process ends on " << i << "%\n";
    }
    cout << "Y=" << ou.out7<<endl;
    return 0;
}
