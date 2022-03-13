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
            cout << "显示完毕" << endl;
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
    cout << "--------欢迎教师-------" << endl
         << endl
         << "\t\t--------------------------\n"
            "\t\t|                         |\n"
            "\t\t|      1.查看预约         |\n"
            "\t\t|                         |\n"
            "\t\t|      2.审核预约         |\n"
            "\t\t|                         |\n"
            "\t\t|      0.注销登录         |\n"
            "\t\t|                         |\n"
            "\t\t--------------------------\n"
         << endl;
    cout << "请选择：";
}

void teacher::examine(vector<student *> *st)
{
    seek(st);
    cout << endl
         << "您要审批哪位同学(请输入编号)：\n";
    int id;
    cin >> id;
    for (int i = 0; i < (*st).size(); i++)
    {
        if ((*st)[i]->m_id == id)
        {
            int day, room;
            cout << "您要审批的日期和机房(输入用空格隔开)：\n";
            cin >> day >> room;
            int &x = (*st)[i]->m_arr[day - 1][room - 1];
            if (x == 0)
            {
                cout << "该学生未预约此日此机房\n";
            }
            else if (x == 2)
            {
                cout << "该学生已预约成功\n";
            }
            else if (x == 3)
            {
                cout << "该学生已预约失败\n";
            }
            else
            {
                cout << "您要 1.同意 2.否决 该预约：\n";
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
                cout << "审批成功" << endl;
            }
            system("pause");
            system("cls");
            return;
        }
    }
    cout << "该学生未预约或查无此人\n";
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
                    cout << "编号:" << (*st)[i]->m_id << "  姓名: " << (*st)[i]->m_name << "  星期" << k + 1 << " " << j + 1 << "号机房" << endl;
            }
        }
    }
}
