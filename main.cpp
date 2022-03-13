#include "D:\c++\computerhouse\head\head2.h"

int arr[5][3];

int main()
{
    manage ma;
    vector<student *> *const st = new vector<student *>;
    vector<teacher *> *const te = new vector<teacher *>;
    init(st, te);
    while (1)
    {
        ma.showmenu();
        string name;
        int se, passwd, id;
        cin >> se;
        switch (se)
        {
        case 0:
        {
            cout << "欢迎下次使用" << endl;
            system("pause");
            fullsave(st, te);
            return 0;
        }
        default:
            ma.login(se, st, te);
        }
        system("pause");
        system("cls");
    }
    return 0;
}