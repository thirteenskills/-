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
    cout << "--------欢迎学生-------" << endl
         << endl
         << "\t\t--------------------------\n"
            "\t\t|                         |\n"
            "\t\t|      1.申请预约         |\n"
            "\t\t|                         |\n"
            "\t\t|      2.查看预约         |\n"
            "\t\t|                         |\n"
            "\t\t|      3.取消预约         |\n"
            "\t\t|                         |\n"
            "\t\t|      4.清空预约         |\n"
            "\t\t|                         |\n"
            "\t\t|      5.查看机房         |\n"
            "\t\t|                         |\n"
            "\t\t|      0.注销登录         |\n"
            "\t\t|                         |\n"
            "\t\t--------------------------\n"
         << endl;
    cout << "请选择：";
}
void student::apply()
{
    int day;
    cout << "申请日期： \n"
            "周一-------1\n"
            "周二-------2\n"
            "周三-------3\n"
            "周四-------4\n"
            "周五-------5\n"
         << endl;
    cin >> day;
    int room;
    cout << "申请机房： \n"
            "一号-------1\n"
            "二号-------2\n"
            "三号-------3\n"
         << endl;
    cin >> room;
    if (m_arr[day - 1][room - 1] == 1)
    {
        cout << "正在审批";
    }
    else if (m_arr[day - 1][room - 1] == 2)
    {
        cout << "审批已通过";
    }
    else
    {
        if (arr[day - 1][room - 1] == 50 * room)
        {
            cout << "人数已满" << endl;
            system("pause");
            system("cls");
            return;
        }
        m_arr[day - 1][room - 1] = 1;
        cout << "申请成功" << endl;
    }
    system("pause");
    system("cls");
    return;
}
void student::cancel()
{
    cout << "您要取消哪一天的预约？\n";
    int day, room;
    showapp(m_arr);
    cout << "日期";
    cin >> day;
    cout << "机房";
    cin >> room;
    m_arr[day - 1][room - 1] = 0;
    cout << "取消成功" << endl;
    system("pause");
    system("cls");
}
void student::showapp(int table[5][3])
{
    cout << "-------------------------------------------\n"
            "|    一号机房   二号机房   三号机房        |\n"
            "|                                          |\n"
            "| 周一     "
         << table[0][0] << "       " << table[0][1] << "       " << table[0][2] << "               |\n"
                                                                                   "|                                         |\n"
                                                                                   "| 周二     "
         << table[1][0] << "       " << table[1][1] << "       " << table[1][2] << "               |\n"
                                                                                   "|                                         |\n"
                                                                                   "| 周三     "
         << table[2][0] << "       " << table[2][1] << "       " << table[2][2] << "               |\n"
                                                                                   "|                                         |\n"
                                                                                   "| 周四     "
         << table[3][0] << "       " << table[3][1] << "       " << table[3][2] << "               |\n"
                                                                                   "|                                         |\n"
                                                                                   "| 周五     "
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
    cout << "取消成功" << endl;
    system("pause");
    system("cls");
}