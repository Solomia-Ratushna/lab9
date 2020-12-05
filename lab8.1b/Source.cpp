
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Special { КH, IS, КI, KB, BI };

string s_special[] = { "Комп’ютерні науки ",
             "Інформаційні системи",
             "Комп’ютерна інженерія",
             "Кібербезпека",
             "Біомедична інженарія " };

struct student
{
    string prizv;
    int kurs;
    Special specialization;
    int phisuka;
    int matematic;
    int informatic;
    int programing;
    int chuslo_metod;
    int pedahohica;
};

void Create(student* s, const int kilkist);
void Print(student* s, const int kilkist);
double find_prozent(student* s, const int kilkist);
double obchuslenua(student* s, const int N);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int kil_student;
    cout << "Введіть кількість студентів: "; cin >> kil_student;
    cout << endl;
    student* s = new student[kil_student];

    Create(s, kil_student);
    cout << endl;
    Print(s, kil_student);
    cout << endl;

    cout << "Процент студентів, які вчаться без трійок (на “відмінно” і “добре”): " << setprecision(2) << find_prozent(s, kil_student) << "%" << endl << endl;

    cout << " Процент студентів, у яких середній бал менший 4: " << setprecision(4) << obchuslenua(s, kil_student) << "%" << endl;
    if (obchuslenua(s, kil_student));
    else
        cout << "Студентів, у яких середній бал менший 4 ,не знайшлося: " << endl << endl;

    delete[] s;
}

void Create(student* s, const int kilkist)
{

    int kurs, special, pecialization;
    for (int i = 0; i < kilkist; i++)
    {
        cout << "студент № " << i + 1 << endl;

        cin.get();
        cin.sync();

        cout << "  прізвище: "; getline(cin, s[i].prizv);
        cout << "  курс: "; cin >> s[i].kurs;
        cout << "  спеціальність (0 -Комп’ютерні науки , 1 -Інформаційні системи , 2 - Комп’ютерна інженерія, 3 -Кібербезпека , 4 -Біомедична інженарія ): "; cin >> special;
        s[i].specialization = (Special)special;
        switch (special)
        {
        case 0:
            cout << "  оцінка з програмування: "; cin >> s[i].programing;
            break;
        case 1:
            cout << "  оцінка з чисельних методів: "; cin >> s[i].chuslo_metod;
            break;
        case 2:
        case 3:
        case 4:
            cout << "  оцінка з педагогіки: "; cin >> s[i].pedahohica;
            break;
        default:
            cout << "Ви ввели помилкове значення! " << endl;
        }
        cout << "  оцінка з фізики: "; cin >> s[i].phisuka;
        cout << "  оцінка з математики: "; cin >> s[i].matematic;
    }
}

void Print(student* s, const int kilkist)
{
    cout << "============================================================================================================================="
        << endl;
    cout << "| №    | Прізвище     | Курс | Спеціальність          | Фізика | Математика  | Програмування | Числовий метод | Педагогіка  |"
        << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < kilkist; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << "   "
            << "| " << setw(13) << left << s[i].prizv
            << "| " << setw(3) << right << s[i].kurs << "   "
            << "| " << setw(22) << right << s_special[s[i].specialization] << ""
            << "| " << setw(4) << right << s[i].phisuka << "   "
            << "| " << setw(6) << right << s[i].matematic << "      ";

     
            switch (s[i].specialization)
            {
            case 0:
                cout << "| " << setw(7) << right << s[i].programing << "       |" << setw(18) << "|" << setw(13) << "|" << endl;
                break;
            case 1:
                cout << "| " << setw(15) << "|" << setw(10) << right << s[i].chuslo_metod << "       |" << setw(13) << "|" << endl;
                break;
            case 2:
            case 3:
            case 4:
                cout << "| " << setw(15) << "|" << setw(18) << "|" << right << setw(7) << s[i].pedahohica << "     |" << endl;
                break;
            }
    }
    cout << "=============================================================================================================================" << endl;
}
double find_prozent(student* s, const int kilkist)
{
    int k = 0;
    for (int i = 0; i < kilkist; i++)
        if (s[i].phisuka > 3 && s[i].matematic > 3 && s[i].informatic > 3)
            k++;
    return 100.0 * k / kilkist;
}

double obchuslenua(student* s, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        switch (s[i].specialization)
        {
        case 0:
            if (((s[i].phisuka + s[i].matematic + s[i].programing) / 3) < 4)
                k++;
            break;
        case 1:
            if (((s[i].phisuka + s[i].matematic + s[i].chuslo_metod) / 3) < 4)
                k++;
            break;
        case 2:
        case 3:
        case 4:
            if (((s[i].phisuka + s[i].matematic + s[i].pedahohica) / 3) < 4)
                k++;
            break;
        }
    }
    return 100.0 * k / N;
}