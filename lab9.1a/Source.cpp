#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Special { ʲ, ��, ��, IS, BI };

string s_special[] = { "���������� �������� ",
             "ʳ����������",
             "��������� �����",
             "����������� �������",
             "���������� �������� " };

struct student
{
    string prizv;
    int kurs;
    Special specialization;
    int phisuka;
    int matematic;
    int informatic;
};

void Create(student* s, const int kilkist);
void Print(student* s, const int kilkist);
double find_prozent(student* s, const int kilkist);
int find_studend(student* s, const int kilkist);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int kil_student;
    cout << "������ ������� ��������: "; cin >> kil_student;
    cout << endl;
    student* s = new student[kil_student];

    Create(s, kil_student);
    cout << endl;
    Print(s, kil_student);
    cout << endl;

    cout << "������� ��������, �� ������� ��� ����� (�� ������� � ������): " << setprecision(2) << find_prozent(s, kil_student) << "%" << endl << endl;

    cout << " ������� ��������, � ���� ������� ��� ������ 4: " << setprecision(4) << find_studend(s, kil_student) << "%" << endl;
    if (find_studend(s, kil_student));
    else
        cout << "��������, � ���� ������� ��� ������ 4 ,�� ���������: " << endl << endl;

    delete[] s;
}

void Create(student* s, const int kilkist)
{
    int kurs, special;
    for (int i = 0; i < kilkist; i++)
    {
        cout << "������� � " << i + 1 << endl;

        cin.get();
        cin.sync();

        cout << "  �������: "; getline(cin, s[i].prizv);
        cout << "  ����: "; cin >> s[i].kurs;
        cout << "  ������������ (0 - ���������� ��������, 1 - ʳ����������, 2 - ��������� �����, 3 -����������� ������� , 4 - ���������� �������� ): "; cin >> special;
        s[i].specialization = (Special)special;
        cout << "  ������ � ������: "; cin >> s[i].phisuka;
        cout << "  ������ � ����������: "; cin >> s[i].matematic;
        cout << "  ������ � �����������: "; cin >> s[i].informatic;
    }
}

void Print(student* s, const int kilkist)
{
    cout << "========================================================================================"
        << endl;
    cout << "| �  | �������     | ���� | ������������         | Գ���� | ����������  | ����������� |"
        << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < kilkist; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " "
            << "| " << setw(13) << left << s[i].prizv
            << "| " << setw(3) << right << s[i].kurs << "  "
            << "| " << setw(22) << right << s_special[s[i].specialization] << ""
            << "| " << setw(4) << right << s[i].phisuka << "   "
            << "| " << setw(6) << right << s[i].matematic << "      "
            << "| " << setw(6) << right << s[i].informatic << "     |" << endl;
    }
    cout << "========================================================================================" << endl;
}

double find_prozent(student* s, const int kilkist)
{
    int k = 0;
    for (int i = 0; i < kilkist; i++)
        if (s[i].phisuka > 3 && s[i].matematic > 3 && s[i].informatic > 3)
            k++;
    return 100.0 * k / kilkist;
}

int find_studend(student* s, const int kilkist)
{
    int k = 0;
    for (int i = 0; i < kilkist; i++)
        if (((s[i].phisuka + s[i].matematic + s[i].informatic )/3) < 4)
            k++;
    return 100.0 * k / kilkist;


}