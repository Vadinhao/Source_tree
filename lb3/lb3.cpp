// lb3.cpp
#include "Header.h"

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Вариант 1(18-й)" << endl;//welcome+
    double sides[3]{ 0,0,0 };
    bool b = true;
    int ind = 0, ch = 0, languages = 0;
    Translation* tr_eng = new EngTranslation();//0
    Translation* tr_uk = new EngTranslation();//1
    vector <Triangle> vec_triangle;
    while (1)
    {
        if (languages == ENG)
            cout << tr_eng->enter_sides() << endl;//enter_sides+
        else

        while (1)
        {
            cout << "A: ";
            cin >> sides[0];
            if (sides[0] == 0) { break; }

            cout << "B: ";
            cin >> sides[1];
            if (sides[1] == 0) { break; }

            cout << "C: ";
            cin >> sides[2];
            if (sides[2] == 0) { break; }
            Triangle temp(sides);
            if (temp.Istriangle())
            {
                vec_triangle.push_back(temp);
            }
            else
                cout << "Вы ввели не треугольник, попробуйте по новой." << endl;//bad_input+
            cout << "___________________" << endl;
        }
        cout << "Ваши треугольники" << endl;//your_tr+
        for (int i = 0; i < vec_triangle.size(); i++)
            cout << i + 1 << "\n" << vec_triangle[i] << endl;//output_tr+
        while (b)
        {
            ind = 0;
            do {
                cout << "Выберите треугольник или введите 0 для выхода в начало, -1 для смены языка: " << endl;//menu_1+
                cin >> ind;
                ind--;
                if (ind == -1)
                {
                    b = false;
                    break;
                }
                if (ind == -2) 
                {
                    //изменить язык
                }
            } while (ind < 0 && ind >= vec_triangle.size());
            if (ind == -1)
                continue;
            cout << "Выберите действие для работы с треугольниками:\n0. Выход в начало программы\n1. Умножить стороны треугольника на коефициент.\n2. Вывести ваши треугольники.\n3. Добавить элемент\n4. Удалить элемент." << endl;//menu_2+
            cin >> ch;
            if (ch == 0)
            {
                b = false;
                continue;
                break;
            }
            if (ch == 1)
            {
                cout << "Введите на сколько стоит умножить стороны треугольника: " << endl;//mult+
                cin >> ch;
                vec_triangle[ind] = vec_triangle[ind] * ch; //метод
                //vec_triangle[ind] = ch * vec_triangle[ind];//друж функция
                cout << "Новые стороны треугольника: " << vec_triangle[ind].Get_A() << " " << vec_triangle[ind].Get_B() << " " << vec_triangle[ind].Get_C() << endl;//new_sides+
            }
            else if (ch == 2)
            {
                cout << "Ваши треугольники" << endl;//your_tr+
                for (int i = 0; i < vec_triangle.size(); i++)
                    cout << i + 1 << "\n" << vec_triangle[i] << endl;//output_tr+
            }
            else if (ch == 3)
            {
                cout << "A: ";
                cin >> sides[0];
                if (sides[0] == 0) { break; }

                cout << "B: ";
                cin >> sides[1];
                if (sides[1] == 0) { break; }

                cout << "C: ";
                cin >> sides[2];
                if (sides[2] == 0) { break; }
                Triangle temp(sides);
                if (temp.Istriangle())
                {
                    auto iter = vec_triangle.cbegin();
                    vec_triangle.emplace(iter + ind, temp);
                    cout << "Ваши треугольники" << endl;//your_tr+
                    for (int i = 0; i < vec_triangle.size(); i++)
                        cout << i + 1 << "\n" << vec_triangle[i] << endl;//output_tr+
                }
                else
                    cout << "Вы ввели не треугольник, попробуйте по новой." << endl;//bad_input+
            }
            else if (ch == 4)
            {
                auto iter = vec_triangle.cbegin();
                vec_triangle.erase(iter + ind);
                cout << "Ваши треугольники" << endl;//your_tr+
                for (int i = 0; i < vec_triangle.size(); i++)
                    cout << i + 1 << "\n" << vec_triangle[i] << endl;//output_tr+
            }
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        string sss;
        cout << "Нажмите 0 для выхода или другую клавишу для продолжения..." << endl;//ex_or_cont
        getline(cin, sss);
        if (sss == "0") { break; }
    }
}