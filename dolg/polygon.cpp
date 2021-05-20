#include <iostream>
#include <vector>
using namespace std;
void massch(vector <vector<int>> a, int X, int Y)
{
    vector<vector<int>> newmass;
    int n = a.size();
    for (int k = X; k <n - 1; k++)
    
        for (int j = 0; j <a.size(); j++)
            a[k] [j]= a[k + 1][j];
    for (int k = Y; k < n - 1; k++)

        for (int j = 0; j < a.size(); j++)
            a[j][k] = a[j][k+1];
    
    for (int i = 0; i < a.size() - 1; i++)
    {
        for (int j = 0; j < a.size() - 1; j++)
        {
            cout << a[i][j] << "\t";
            if (j == 3)
            {
                cout << endl;
            }
        }
    }


}


int main()
{
    vector <vector<int>> mass = { {12,4,45,75,23},{65,3,25,66,35},{43,4,14,47,34},{266,346,23,75,34},{35,376,235,36,436} };

    for (int i = 0; i < mass.size(); i++)
    {
        for (int j = 0; j < mass.size(); j++)
        {
            cout << mass[i][j] << "\t";
            if (j == 4)
            {
                cout << endl;
            }
        }
    }
    int X, Y;
    cout << "enter what col and row need to del\n";
    cin >> X >> Y;
   
    massch(mass, X, Y);

    return 0;
}