
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
    Special special;
    int phisuka;
    int matematic;
    int informatic;
};

void Create(student* s, const int kilkist);
void Print(student* s, const int kilkist);
double find_prozent(student* s, const int kilkist);
int find_studend(student* s, const int kilkist);
void Sort(student* s, const int kilkist);
int BinSearch(student* s, const int kilkist, const string prizv, const Special special);
int* IndexSort(student* s, const int kilkist);
void PrintIndexSorted(student* s, int* I, const int kilkist);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int kilkist;
    cout << "������ ������� ��������: "; cin >> kilkist;

    student* s = new student[kilkist];
    double proc;
    int ispecial;
    Special special;
    string prizv;
    int found;
    char filename[100];


    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "������� ��:" << endl << endl;
        cout << " [1] - �������� ����� � ���������" << endl;
        cout << " [2] - ���� ����� �� �����" << endl;
        cout << " [3] - ������� ��������, � ���� ������� ��� ������ 4:" << endl;
        cout << " [4] - ������� ������������� �����" << endl << endl;
        cout << " [5] - ������� ����� ��������� ������� �� �������� �������� �� ��������� ���� �� ������� ������������" << endl;
        cout << " [6] - �������� ������������� �� ���� �����" << endl;
        cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
        cout << "������ ��������: "; cin >> menuItem;
        cout << endl << endl << endl;
        switch (menuItem)
        {
        case 1:
            Create(s, kilkist);
            Print(s, kilkist);
            break;
        case 2:
            Print(s, kilkist);
            break;
        case 3:
            proc = find_prozent(s, kilkist);
            cout << "������� ��������, � ���� ������� ��� ������ 4:" << endl;
            cout << proc << "%" << endl;
            Print(s, kilkist);
            break;
        case 4:
            Sort(s, kilkist);
            Print(s, kilkist);
            break;
        case 5:
            cout << "������ ����� ������:" << endl;
            cout << " ������������ (0 -����'����� �����, 1-��������� �����, 2-����������� ��������, 3-ʳ���������� ): ";
            cin >> ispecial;
            special = (Special)ispecial;
            cin.get(); // ������� ����� ��������� � �� ����������� �������
            cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����

            cout << " �������: "; getline(cin, prizv);
            cout << endl;
            if ((found = BinSearch(s, kilkist, prizv, special)) != -1)
                cout << "�������� �������� � ������� " << found + 1 << endl;
            else
                cout << "�������� �������� �� ��������" << endl;
            break;
       
        case 0:
            break;
        default:
            cout << "�� ����� ��������� ��������! "
                "��� ������ ����� - ����� ��������� ������ ����" << endl;
        }
    } while (menuItem != 0);

    return 0;
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
        cout << "  ������������ (0 - ���������� ��������, 1 - ʳ����������, 2 - ��������� �����, 3 -����������� ������� , 4 -  ): "; cin >> special;
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
        if (((s[i].phisuka + s[i].matematic + s[i].informatic) / 3) < 4)
            k++;
    return 100.0 * k / kilkist;


}
void Sort(student* s, const int kilkist)
{
    student tmp;
    for (int i0 = 0; i0 < kilkist - 1; i0++) // ����� "���������"
        for (int i1 = 0; i1 < kilkist - i0 - 1; i1++)
            if ((s[i1].kurs > s[i1 + 1].kurs)
                ||
                (s[i1].kurs == s[i1 + 1].kurs &&
                    s[i1].specialization > s[i1 + 1].specialization))
            {
                tmp = s[i1];
                s[i1] = s[i1 + 1];
                s[i1 + 1] = tmp;
            }
}
int BinSearch(student* s, const int  kilkist, const string prizv, const Special special)
{ // ������� ������ ���������� �������� ��� -1, ���� ������� ������� �������
    int L = 0, R = kilkist - 1, i;
    do {
        i = (L + R) / 2;
        if (s[i].prizv == prizv && s[i].special == special)
            return i;
        if ((s[i].special < special)
            ||
            (s[i].special == special &&
                s[i].prizv < prizv))
        {
            L = i + 1;
        }
        else
        {
            R = i - 1;
        }
    } while (L <= R);
    return -1;
}
int* IndexSort(student* s, const int kilkist)
{
    int* I = new int[kilkist];
    for (int i = 0; i < kilkist; i++)
        I[i] = i;
    int i, j, value;
    for (i = 1; i < kilkist; i++)
    {
        value = I[i];
        for (j = i - 1;
            j >= 0 && ((s[I[j]].special > s[value].special) ||
                (s[I[j]].special == s[value].special &&
                    s[I[j]].prizv > s[value].prizv));
            j--)
        {
            I[j + 1] = I[j];
        }
        I[j + 1] = value;
    }
    return I;
}
void PrintIndexSorted(student* s, int* I, const int kilkist)
{
    cout << "========================================================================="
        << endl;
    cout << "| � | ������� | г�.���. | ������ | ����� | ������ |"
        << endl;
    cout << "-------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < kilkist; i++)
    {
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(13) << left << s[I[i]].prizv
            << "| " << setw(4) << right << s[I[i]].kurs << " "
            << "| " << setw(11) << left << s_special[s[I[i]].special];
        switch (s[I[i]].special)
        {
        case 0:
        case 1:
        case 2:
        case 3:
            cout << "| " << setw(9) << setprecision(2) << fixed << right
                << s[I[i]].phisuka << " |"
                << setw(13) << right << "|"
                << endl;
            cout << "| " << setw(11) << right << "|" << " " << setw(8) << right
                << s[I[i]].matematic << " |"
                << endl;
            cout << "| " << setw(15) << right << "|" << " " << setw(5) << right
                << s[i].informatic << " |" << endl;
            break;
        }
    }
    cout << "========================================================================="
        << endl;
    cout << endl;
}