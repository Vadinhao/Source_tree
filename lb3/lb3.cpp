// lb3.cpp
#include "Header.h"

int main()
{
    setlocale(LC_CTYPE, "ukr");
    Translation* tr_eng = new EngTranslation();//0
    Translation* tr_uk = new UkTranslation();//1
    Translation* tr = tr_eng;
    vector <Triangle> vec_triangle;
    double sides[3]{ 0,0,0 };
    bool b = true;
    int ind = 0, ch = 0, languages = 0;
    //
    cout << tr_eng->language() << endl;
    cin >> languages;
    if (languages == 0)
        tr = tr_eng;
    else
        tr = tr_uk;
    //
    cout << tr->welcome() << endl;
    //
    while (1)
    {
        //
        cout << tr->enter_sides() << endl;
        //
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
                //
                cout << tr->bad_input() << endl;
                //
            cout << "___________________" << endl;
        }
        //
        cout << tr->your_tr() << endl;
        //
        for (int i = 0; i < vec_triangle.size(); i++)
            cout << i + 1 << ".) " << tr->output_tr(vec_triangle[i]) << endl;
        //
        while (b)
        {
            ind = 0;
            do {
                //
                cout << tr->menu_1() << endl;
                //
                cin >> ind;
                ind--;
                if (ind == -1)
                {
                    b = false;
                    break;
                }
                if (ind == -2) 
                {
                    //
                    cout << tr->language() << endl;
                    //
                    cin >> languages;
                    if (languages == 0)
                        tr = tr_eng;
                    else
                        tr = tr_uk;
                }
            } while (ind < 0 && ind >= vec_triangle.size());
            if (ind == -1)
                continue;
            //
            cout << tr->menu_2() << endl;
            //
            cin >> ch;
            if (ch == 0)
            {
                b = false;
                continue;
                break;
            }
            if (ch == 1)
            {
                //
                cout << tr->mult() << endl;
                //
                cin >> ch;
                vec_triangle[ind] = vec_triangle[ind] * ch; //метод
                //vec_triangle[ind] = ch * vec_triangle[ind];//друж функция
                //
                cout << tr->new_sides(vec_triangle[ind]) << endl;
                //
            }
            else if (ch == 2)
            {
                //
                cout << tr->your_tr() << endl; 
                //
                for (int i = 0; i < vec_triangle.size(); i++)
                    //
                    cout << i + 1 << ".) " << tr->output_tr(vec_triangle[i]) << endl;
                    //
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
                    //
                    cout << tr->your_tr() << endl;
                    //
                    for (int i = 0; i < vec_triangle.size(); i++)
                        //
                        cout << i + 1 << ".) " << tr->output_tr(vec_triangle[i]) << endl;
                        //
                }
                else
                    //
                    cout << tr->bad_input() << endl;
                    //
            }
            else if (ch == 4)
            {
                auto iter = vec_triangle.cbegin();
                vec_triangle.erase(iter + ind);
                //
                cout << tr->your_tr() << endl;
                //
                for (int i = 0; i < vec_triangle.size(); i++)
                    //
                    cout << i + 1 << ".) " << tr->output_tr(vec_triangle[i]) << endl;
                    //
            }
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        string sss;
        //
        cout << tr->ex_or_cont() << endl;
        //
        getline(cin, sss);
        if (sss == "0") { break; }
    }
}