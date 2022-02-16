#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

string validNum(char varname);

int main(int argc, char *argv[])
{
    cout << fixed << showpoint;
    cout << setprecision(3);
    if (argc == 1)
    {

        double a, b, c;
        a = stod(validNum('a'));
        b = stod(validNum('b'));
        c = stod(validNum('c'));

        cout << "Equation is: (" << a << ") x^2 + (" << b << ") x + (" << c << ") = 0" << endl;

        int discriminant = pow(b, 2) - 4 * a * c;
        double x1;
        double x2;
        if (discriminant < 0)
        {
            cout << "There are 0 roots" << endl;
        }
        else if (discriminant == 0)
        {
            x1 = -b / 2 * a;
            cout << "There are 1 root" << endl;
            cout << "x = " << x1;
        }
        else if (discriminant > 0)
        {
            x1 = (-b - sqrt(discriminant)) / (2 * a);
            x2 = (-b + sqrt(discriminant)) / (2 * a);
            cout << "There are 2 roots" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
    }
    else if (argc == 2)
    {
    }
    else
    {
        cout << "Error" << endl;
    }

    return 0;
}

string validNum(char varname)
{
    string value;
    bool flag = true;
    while (flag)
    {
        cout << varname << " = ";
        cin >> value;
        for (int i = 0; i < value.size(); i++)
        {
            if (!isdigit(value[i]) && value[i] != '.' && value[i] != '-')
            {
                cout << "Error. Expected a valid real number, got invalid instead" << endl;
                break;
            }
            else
            {
                flag = false;
            }
        }
    }
    return value;
}
