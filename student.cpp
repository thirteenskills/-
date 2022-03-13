#include "D:\c++\computerhouse\head\head2.h"

extern int arr[5][3];

void student::start()
{
    int se;
    while (1)
    {
        this->showmenu();
        cin >> se;
        switch (se)
        {
        case 1:
            apply();
            break;
        case 2:
        {
            showapp(m_arr);
            system("pause");
            system("cls");
            break;
        }
        case 3:
            cancel();
            break;
        case 4:
            clear();
            break;
        case 5:
        {
            showapp(arr);
            system("pause");
            system("cls");
            break;
        }

        case 0:
        {
            return;
            break;
        }
        }
    }
    system("pause");
}
void student::showmenu()
{
    cout << "--------��ӭѧ��-------" << endl
         << endl
         << "\t\t--------------------------\n"
            "\t\t|                         |\n"
            "\t\t|      1.����ԤԼ         |\n"
            "\t\t|                         |\n"
            "\t\t|      2.�鿴ԤԼ         |\n"
            "\t\t|                         |\n"
            "\t\t|      3.ȡ��ԤԼ         |\n"
            "\t\t|                         |\n"
            "\t\t|      4.���ԤԼ         |\n"
            "\t\t|                         |\n"
            "\t\t|      5.�鿴����         |\n"
            "\t\t|                         |\n"
            "\t\t|      0.ע����¼         |\n"
            "\t\t|                         |\n"
            "\t\t--------------------------\n"
         << endl;
    cout << "��ѡ��";
}
void student::apply()
{
    int day;
    cout << "�������ڣ� \n"
            "��һ-------1\n"
            "�ܶ�-------2\n"
            "����-------3\n"
            "����-------4\n"
            "����-------5\n"
         << endl;
    cin >> day;
    int room;
    cout << "��������� \n"
            "һ��-------1\n"
            "����-------2\n"
            "����-------3\n"
         << endl;
    cin >> room;
    if (m_arr[day - 1][room - 1] == 1)
    {
        cout << "��������";
    }
    else if (m_arr[day - 1][room - 1] == 2)
    {
        cout << "������ͨ��";
    }
    else
    {
        if (arr[day - 1][room - 1] == 50 * room)
        {
            cout << "��������" << endl;
            system("pause");
            system("cls");
            return;
        }
        m_arr[day - 1][room - 1] = 1;
        cout << "����ɹ�" << endl;
    }
    system("pause");
    system("cls");
    return;
}
void student::cancel()
{
    cout << "��Ҫȡ����һ���ԤԼ��\n";
    int day, room;
    showapp(m_arr);
    cout << "����";
    cin >> day;
    cout << "����";
    cin >> room;
    m_arr[day - 1][room - 1] = 0;
    cout << "ȡ���ɹ�" << endl;
    system("pause");
    system("cls");
}
void student::showapp(int table[5][3])
{
    cout << "-------------------------------------------\n"
            "|    һ�Ż���   ���Ż���   ���Ż���        |\n"
            "|                                          |\n"
            "| ��һ     "
         << table[0][0] << "       " << table[0][1] << "       " << table[0][2] << "               |\n"
                                                                                   "|                                         |\n"
                                                                                   "| �ܶ�     "
         << table[1][0] << "       " << table[1][1] << "       " << table[1][2] << "               |\n"
                                                                                   "|                                         |\n"
                                                                                   "| ����     "
         << table[2][0] << "       " << table[2][1] << "       " << table[2][2] << "               |\n"
                                                                                   "|                                         |\n"
                                                                                   "| ����     "
         << table[3][0] << "       " << table[3][1] << "       " << table[3][2] << "               |\n"
                                                                                   "|                                         |\n"
                                                                                   "| ����     "
         << table[4][0] << "       " << table[4][1] << "       " << table[4][2] << "               |\n"
                                                                                   "|                                         |\n"
                                                                                   "-------------------------------------------\n";
}
void student::clear()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (m_arr[i][j] == 2)
                arr[i][j]--;
            m_arr[i][j] = 0;
        }
    }
    cout << "ȡ���ɹ�" << endl;
    system("pause");
    system("cls");
}