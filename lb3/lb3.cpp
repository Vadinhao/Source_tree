// lb3.cpp
#include "Header.h"

int main()
{
    setlocale(LC_CTYPE, "ukr");
    Translation* tr_eng = new EngTranslation();
    Translation* tr_uk = new UkTranslation();
    Translation* tr = tr_eng;
    vector <Triangle> vec_triangle;
    double sides[3]{ 0,0,0 };
    bool b = true, er = false;
    int ind = 0, ch = 0, languages = 0, count = 0;
    do
    {
        //
        cout << tr_eng->language() << endl;
        cin >> languages;
        try 
        {
            er = false;
            if (cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                throw tr->catching_errors_type();
            }
            else if (languages < ENG || languages > UK) 
                throw tr->catching_errors_value();

        }
        catch (string s1)
        {
            cout << s1 <<endl;
            er = true;
        }
    }while (er == true);
    er = false;
    if (languages == 0)
        tr = tr_eng;
    else
        tr = tr_uk;
    //
    cout << tr->welcome() << endl;
    while (1)
    {
        //
        cout << tr->enter_sides() << endl;
        b = true;
        while (b)
        {
            do
            {
                try
                {
                    er = false;
                    cout << "A: ";
                    cin >> sides[0];
                    if (cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(32767, '\n');
                        throw tr->catching_errors_type();
                    }
                    if (sides[0] < 0.0) { throw tr->catching_errors_value(); }
                    else if (sides[0] == 0) { b = false; break; }
                    //
                    cout << "B: ";
                    cin >> sides[1];
                    if (cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(32767, '\n');
                        throw tr->catching_errors_type();
                    }
                    if (sides[1] < 0.0) { throw tr->catching_errors_value(); }
                    else if (sides[1] == 0) { b = false; break; }
                    //
                    cout << "C: ";
                    cin >> sides[2];

                    if (cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(32767, '\n');
                        throw tr->catching_errors_type();
                    }
                    if (sides[2] < 0.0) { throw tr->catching_errors_value(); }
                    else if (sides[2] == 0) { b = false; break; }
                }
                catch (string s1)
                {
                    cout << s1 << endl;
                    er = true;
                }
            } while (er == true);
            er = false;
            Triangle temp(sides);
            if (temp.Istriangle())
            {
                count++;
                vec_triangle.push_back(temp);
            }
            else if (vec_triangle.size() == 0)
            {
                //
                cout << tr->bad_input() << endl;
                b = true;
            }        
            cout << "___________________" << endl;
        }
        //
        cout << tr->your_tr() << endl;
        for (int i = 0; i < vec_triangle.size(); i++)
            cout << i + 1 << ".) " << tr->output_tr(vec_triangle[i]) << endl;
        b = true;
        while (b)
        {
            ind = 0;
            do 
            {
                do
                {
                    //
                    cout << tr->menu_1() << endl;
                    cin >> ind;

                    try
                    {
                        er = false;
                        if (cin.fail())
                        {
                            std::cin.clear();
                            std::cin.ignore(32767, '\n');
                            throw tr->catching_errors_type();
                        }
                        if (ind < -1 && ind < vec_triangle.size())
                        {
                            throw tr->catching_errors_value();
                        }
                        if (ind > count)
                        {
                            throw tr->catching_errors_value();
                        }
                    }
                    catch (string s1)
                    {
                        cout << s1 << endl;
                        er = true;
                    }
                } while (er == true);
                er = false;
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
                    do
                    {
                        cin >> languages;
                        try
                        {
                            if (cin.fail())
                            {
                                std::cin.clear();
                                std::cin.ignore(32767, '\n');
                                throw tr->catching_errors_type();
                            }
                            else if (languages < ENG || languages > UK)
                                throw tr->catching_errors_value();
                            er = false;
                        }
                        catch (string s1)
                        {
                            cout << s1 << endl;
                            er = true;
                        }
                    } while (er == true);
                    if (languages == 0)
                        tr = tr_eng;
                    else
                        tr = tr_uk;
                }
            } while (ind < 0 && ind >= vec_triangle.size());
            if (ind <= -1)
                continue;
            do
            {
                //
                cout << tr->menu_2() << endl;
                cin >> ch;
                try
                {
                    er = false;
                    if (cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(32767, '\n');
                        throw tr->catching_errors_type();
                    }
                    else if (ch < 0 || ch > 4)
                        throw tr->catching_errors_value();
                }
                catch (string s1)
                {
                    cout << s1 << endl;
                    er = true;
                }
            } while (er == true);
            er = false;
            if (ch == 0)
            {
                b = false;
                continue;
                break;
            }
            if (ch == 1)
            {
                do
                {
                    //
                    cout << tr->mult() << endl;
                    cin >> ch;
                    try
                    {
                        er = false;
                        if (cin.fail())
                        {
                            std::cin.clear();
                            std::cin.ignore(32767, '\n');
                            throw tr->catching_errors_type();
                        }
                        else if (ch <= 0)
                            throw tr->catching_errors_value();
                    }
                    catch (string s1)
                    {
                        cout << s1 << endl;
                        er = true;
                    }
                } while (er == true);
                er = false;
                vec_triangle[ind] = vec_triangle[ind] * ch; //метод
                //vec_triangle[ind] = ch * vec_triangle[ind];//друж функция
                //
                cout << tr->new_sides(vec_triangle[ind]) << endl;
            }
            else if (ch == 2)
            {
                //
                cout << tr->your_tr() << endl; 
                for (int i = 0; i < vec_triangle.size(); i++)
                    //
                    cout << i + 1 << ".) " << tr->output_tr(vec_triangle[i]) << endl;
            }
            else if (ch == 3)
            {
                do
                {
                    try
                    {
                        er = false;
                        cout << "A: ";
                        cin >> sides[0];
                        if (cin.fail())
                        {
                            std::cin.clear();
                            std::cin.ignore(32767, '\n');
                            throw tr->catching_errors_type();
                        }
                        if (sides[0] < 0.0) { throw tr->catching_errors_value(); }
                        else if (sides[0] == 0) { b = false; break; }
                        //
                        cout << "B: ";
                        cin >> sides[1];
                        if (cin.fail())
                        {
                            std::cin.clear();
                            std::cin.ignore(32767, '\n');
                            throw tr->catching_errors_type();
                        }
                        if (sides[1] < 0.0) { throw tr->catching_errors_value(); }
                        else if (sides[1] == 0) { b = false; break; }
                        //
                        cout << "C: ";
                        cin >> sides[2];

                        if (cin.fail())
                        {
                            std::cin.clear();
                            std::cin.ignore(32767, '\n');
                            throw tr->catching_errors_type();
                        }
                        if (sides[2] < 0.0) { throw tr->catching_errors_value(); }
                        else if (sides[2] == 0) { b = false; break; }
                    }
                    catch (string s1)
                    {
                        cout << s1 << endl;
                        er = true;
                    }
                } while (er == true);
                er = false;
                Triangle temp(sides);
                if (temp.Istriangle())
                {
                    count++;
                    vec_triangle.push_back(temp);
                }
                else if (vec_triangle.size() == 0)
                {
                    //
                    cout << tr->bad_input() << endl;
                    b = false;
                }
                cout << "___________________" << endl;
            }
            else if (ch == 4)
            {
                auto iter = vec_triangle.cbegin();
                vec_triangle.erase(iter + ind);
                count--;
                //
                cout << tr->your_tr() << endl;
                if (vec_triangle.size() != 0)
                    for (int i = 0; i < vec_triangle.size(); i++)
                        //
                        cout << i + 1 << ".) " << tr->output_tr(vec_triangle[i]) << endl;
                else 
                {
                    b = false;
                    cout << tr->bad_input() << endl;
                }
            }
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        string sss;
        //
        cout << tr->ex_or_cont() << endl;
        getline(cin, sss);
        if (sss == "0") { break; }
    }
}