#include "D:\c++\computerhouse\head\head2.h"

extern int arr[5][3];

void teacher::start(vector<student *> *st)
{
    int se;
    while (1)
    {
        this->showmenu();
        cin >> se;
        switch (se)
        {
        case 1:
        {
            seek(st);
            cout << "��ʾ���" << endl;
            system("pause");
            system("cls");
            break;
        }

        case 2:
            examine(st);
            break;
        case 0:
        {
            return;
        }
        }
    }
}
void teacher::showmenu()
{
    cout << "--------��ӭ��ʦ-------" << endl
         << endl
         << "\t\t--------------------------\n"
            "\t\t|                         |\n"
            "\t\t|      1.�鿴ԤԼ         |\n"
            "\t\t|                         |\n"
            "\t\t|      2.���ԤԼ         |\n"
            "\t\t|                         |\n"
            "\t\t|      0.ע����¼         |\n"
            "\t\t|                         |\n"
            "\t\t--------------------------\n"
         << endl;
    cout << "��ѡ��";
}

void teacher::examine(vector<student *> *st)
{
    seek(st);
    cout << endl
         << "��Ҫ������λͬѧ(��������)��\n";
    int id;
    cin >> id;
    for (int i = 0; i < (*st).size(); i++)
    {
        if ((*st)[i]->m_id == id)
        {
            int day, room;
            cout << "��Ҫ���������ںͻ���(�����ÿո����)��\n";
            cin >> day >> room;
            int &x = (*st)[i]->m_arr[day - 1][room - 1];
            if (x == 0)
            {
                cout << "��ѧ��δԤԼ���մ˻���\n";
            }
            else if (x == 2)
            {
                cout << "��ѧ����ԤԼ�ɹ�\n";
            }
            else if (x == 3)
            {
                cout << "��ѧ����ԤԼʧ��\n";
            }
            else
            {
                cout << "��Ҫ 1.ͬ�� 2.��� ��ԤԼ��\n";
                int a;
                cin >> a;
                if (a == 1)
                {
                    x = 2;
                    arr[day - 1][room - 1] += 1;
                }
                else
                {
                    x = 3;
                }
                cout << "�����ɹ�" << endl;
            }
            system("pause");
            system("cls");
            return;
        }
    }
    cout << "��ѧ��δԤԼ����޴���\n";
    system("pause");
    system("cls");
    return;
}
void teacher::seek(vector<student *> *st)
{
    for (int i = 0; i < (*st).size(); i++)
    {
        for (int k = 0; k < 5; k++)
        {
            for (int j = 0; j < 3; j++)
            {
                if ((*st)[i]->m_arr[k][j] == 1)
                    cout << "���:" << (*st)[i]->m_id << "  ����: " << (*st)[i]->m_name << "  ����" << k + 1 << " " << j + 1 << "�Ż���" << endl;
            }
        }
    }
}
