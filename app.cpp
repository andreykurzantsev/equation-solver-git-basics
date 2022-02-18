#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdexcept>
using namespace std;

string validNum(char varname);
double *useFile(string filepath);
void solveEquation(double a, double b, double c);
void printDoneEquation(double a, double b, double c);

int main(int argc, char *argv[])
{
    double a, b, c;
    if (argc == 1)
    {
        a = stod(validNum('a'));
        b = stod(validNum('b'));
        c = stod(validNum('c'));
    }
    else if (argc == 2)
    {
        string file = argv[1];
        double *pointforarr = useFile(file);
        a = pointforarr[0];
        b = pointforarr[1];
        c = pointforarr[2];
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
            if (varname == 'a' && value[i] == '0')
            {
                cout << "Error. a cannot be 0" << endl;
                break;
            }
            else if (!isdigit(value[i]) && value[i] != '.' && value[i] != '-')
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

double *useFile(string filepath)
{

    static double coefs[3];
    string inlines, checkformat;
    stringstream strbuf;

    fstream inputfile;
    inputfile.open(filepath, ios::in);

    if (!inputfile.is_open())
    {
        throw logic_error(("File " + filepath + " doesn't exist").c_str());
    }
    else
    {
        getline(inputfile, inlines);
        strbuf.str(inlines);

        inputfile >> checkformat;

        if (checkformat != "")
        {
            throw logic_error("Invalid file format");
        }

        double num;
        int spacecount = 0;

        for (size_t j = 0; j < inlines.size(); j++)
        {
            char s = inlines[j];
            if (s == ' ')
            {
                spacecount++;
            }
        }

        if (spacecount != 2)
        {
            throw logic_error("Invalid file format");
        }

        for (int i = 0; i < 3; i++)
        {

            strbuf >> num;
            if (!strbuf.fail())
            {
                if (i == 0 && num == 0.0)
                {
                    throw logic_error("Error. a cannot be 0");
                }
            }
            if (strbuf.fail())
            {
                throw logic_error("Invalid file format");
            }
            else
            {
                coefs[i] = num;
            }
        }
        if (!strbuf.fail())
        {
            strbuf >> num;
            if (!strbuf.fail())
            {
                throw logic_error("Invalid file format");
            }
        }
    }

    return coefs;
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
