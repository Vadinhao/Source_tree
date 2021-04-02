#define PI 3.14159265358979323846
#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <string>
#include <vector>
#include <ostream>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ostream;

enum Languages
{
    ENG,
    UK,
};

class Triangle
{
private:
    double A;
    double B;
    double C;
    double perimeter;
    double square;
    double* angle;
    double Perimeter() const;
    double Square() const;
    double* Angle(double* angl);
public:
    Triangle();
    Triangle(double sides[]);
    Triangle(Triangle* triangle);
    ~Triangle();

    void Set(double sides[]);
    double Get_A() const;
    double Get_B() const;
    double Get_C() const;
    double Get_Perimeter() const;
    double Get_Square() const;
    double* Get_Angle() const;
    bool Istriangle() const;
    Triangle operator*(double k);
    string toString() const;
    friend Triangle operator*(double k, Triangle tr);
    friend ostream& operator<<(ostream& os, const Triangle& tr);
};

class Translation : public Triangle
{
public:
    virtual string welcome() const = 0;
    virtual string enter_sides() const = 0;
    virtual string bad_input() const = 0;
    virtual string your_tr() const = 0;
    virtual string output_tr(Triangle tr) const = 0;
    virtual string menu_1() const = 0;
    virtual string menu_2() const = 0;
    virtual string mult() const = 0;
    virtual string new_sides(Triangle tr) const = 0;
    virtual string ex_or_cont() const = 0;
    virtual string language() const = 0;
    virtual ~Translation() {};
};

class EngTranslation : public Translation
{
    virtual string welcome() const override
    {
        return "LabWork #3\nVariant 1(18)";
    }
    virtual string enter_sides() const override
    {
        return "Enter the lengths of the sides of the triangles (0 to continue)";
    }
    virtual string bad_input() const override
    {
        return "You have not entered a triangle, try again";
    }
    virtual string your_tr() const override
    {
        return "Your triangles";
    }
    virtual string output_tr(Triangle tr) const override
    {
        string s1;
        std::ostringstream ostr;
        ostr << "A: " << tr.Get_A() << ", B: " << tr.Get_B() << ", C: " << tr.Get_C() << "\nPerimeter: " << tr.Get_Perimeter() << "\nSquare: " << tr.Get_Square() << "\nAngles(a,b,c): " << tr.Get_Angle()[0] << ", " << tr.Get_Angle()[1] << ", " << tr.Get_Angle()[2];
        s1 = ostr.str();
        return s1;
    }
    virtual string menu_1() const override
    {
        return "Select the triangle or enter 0 to go to the beginning, -1 to change the language: ";
    }
    virtual string menu_2() const override
    {
        return "Select the action for working with triangles: \n0. Exit to the beginning of the program \n1. Multiply the sides of the triangle by factor. \n2. Print your triangles. \n3. Add item \n4. Remove item.";
    }
    virtual string mult() const override
    {
        return "Enter how much it costs to multiply the sides of a triangle:";
    }
    virtual string new_sides(Triangle tr) const override
    {
        string s1;
        std::ostringstream ostr;
        ostr << " New sides of triangles: A: " << tr.Get_A() << ", B: " << tr.Get_B() << ", C: " << tr.Get_C() << "\nPerimeter: " << tr.Get_Perimeter() << "\nSquare: " << tr.Get_Square() << "\nAngles(a,b,c): " << tr.Get_Angle()[0] << ", " << tr.Get_Angle()[1] << ", " << tr.Get_Angle()[2];
        s1 = ostr.str();
        return s1;
    }
    virtual string ex_or_cont() const override
    {
        return "Press 0 to exit or another key to continue...";
    }
    virtual string language() const override 
    {
        return "Enter num for select language:\n0.English\n1.Ukranian";
    }
};

class UkTranslation : public Translation
{
    virtual string welcome() const override
    {
        return "����������� ������ �3\n���i��� 1(18)";
    }
    virtual string enter_sides() const override
    {
        return "����i�� ������� ����i� ���������i� (0 ��� �����������)";
    }
    virtual string bad_input() const override
    {
        return "�� ����� �� ���������, ��������� �� ���";
    }
    virtual string your_tr() const override
    {
        return "���i ����������";
    }
    virtual string output_tr(Triangle tr) const override
    {
        string s1;
        std::ostringstream ostr;
        ostr << "A: " << tr.Get_A() << ", B: " << tr.Get_B() << ", C: " << tr.Get_C() << "\n��������: " << tr.Get_Perimeter() << "\n�����: " << tr.Get_Square() << "\n����(a,b,c): " << tr.Get_Angle()[0] << ", " << tr.Get_Angle()[1] << ", " << tr.Get_Angle()[2];
        s1 = ostr.str();
        return s1;
    }
    virtual string menu_1() const override
    {
        return "�����i�� ��������� ��� ����i�� 0 ��� ������ � ������� ��������, -1 ��� ��i�� ����: ";
    }
    virtual string menu_2() const override
    {
        return "�����i�� �i� � �����������: \n0. ���i� � ������� �������� \n1. ��������� ������� ���������� �� ����i�i���. \n2. ������� ���i ����������. \n3. ������ ������� \n4. �������� �������.";
    }
    virtual string mult() const override
    {
        return "���i�� ����i�i��� ��� ��i�� ����i�i� ����� ����������:";
    }
    virtual string new_sides(Triangle tr) const override
    {
        string s1;
        std::ostringstream ostr;
        ostr << " ���i ������� ����������: A: " << tr.Get_A() << ", B: " << tr.Get_B() << ", C: " << tr.Get_C() << "\n��������: " << tr.Get_Perimeter() << "\n�����: " << tr.Get_Square() << "\n����(a,b,c): " << tr.Get_Angle()[0] << ", " << tr.Get_Angle()[1] << ", " << tr.Get_Angle()[2];
        s1 = ostr.str();
        return s1;
    }
    virtual string ex_or_cont() const override
    {
        return "�������� 0 ��� ������ ��� i��� ����i�� ��� �����������";
    }
    virtual string language() const override
    {
        return "����i�� ����� ��� ������ ����:\n0.English\n1.Ukranian";
    }
};