#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

string validNum(char varname);
void solveEquation(double a, double b, double c);
void printDoneEquation(double a, double b, double c);

int main(int argc, char *argv[])
{
    double a, b, c;
    cout << fixed << showpoint;
    cout << setprecision(3);
    if (argc == 1)
    {
        a = stod(validNum('a'));
        b = stod(validNum('b'));
        c = stod(validNum('c'));
    }
    else if (argc == 2)
    {
        string inlines, checkformat;
        stringstream strbuf;
        fstream inputfile;
        inputfile.open(argv[1], ios::in);
        if (!inputfile.is_open())
        {
            cout << "File " << argv[1] << " does not exist" << endl;
        }
        else
        {
            getline(inputfile, inlines);
            strbuf.str(inlines);

            inputfile >> checkformat;
            if (checkformat != "")
            {
                cout << "Invalid file format" << endl;
            }
            double coefs[3];
            for (int i = 0; i < 3; i++)
            {
                string k;
                strbuf >> k;
                coefs[i] = stod(k);
            }
            a = coefs[0];
            b = coefs[1];
            c = coefs[2];
        }
    }
    else
    {
        cout << "Error" << endl;
    }
    printDoneEquation(a, b, c);
    solveEquation(a, b, c);

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
        for (size_t i = 0; i < value.size(); i++)
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

void solveEquation(double a, double b, double c)
{
    double discriminant = pow(b, 2) - 4 * a * c;
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

void printDoneEquation(double a, double b, double c)
{
    cout << "Equation is: (" << a << ") x^2 + (" << b << ") x + (" << c << ") = 0" << endl;
}