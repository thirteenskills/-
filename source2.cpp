#include "D:\c++\computerhouse\head\head2.h"

extern int arr[5][3];

void init(vector<student *> *st, vector<teacher *> *te)
{
    int id, day, room;
    string name, passwd, arr1;
    ifstream ifs;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = 0;
        }
    }
    ifs.open(stfile, ios::in);
    while (ifs >> id && ifs >> name && ifs >> passwd && ifs >> arr1)
    {
        student *s = new student(id, name, passwd, arr1);
        (*st).push_back(s);
    }
    ifs.close();
    ifs.open(tefile, ios::in);
    while (ifs >> id && ifs >> name && ifs >> passwd)
    {
        teacher *s = new teacher(id, name, passwd);
        (*te).push_back(s);
    }
    ifs.close();
    ifs.open(adfile, ios::in);
    char c;
    ifs >> c;
    if (ifs.is_open() && !ifs.eof())
    {
        ifs.close();
    }
    else
    {
        ifs.close();
        ofstream ofs;
        ofs.open(adfile, ios::app);
        ofs << "root 123 ";
        ofs.close();
    }
}

void manage::showmenu()
{
    cout << "-------��ӭʹ�û���ԤԼϵͳ--------" << endl
         << endl
         << "�������������" << endl
         << "\t\t-----------------------\n"
            "\t\t|                     |\n"
            "\t\t|      1.ѧ��         |\n"
            "\t\t|                     |\n"
            "\t\t|      2.��ʦ         |\n"
            "\t\t|                     |\n"
            "\t\t|      3.����Ա       |\n"
            "\t\t|                     |\n"
            "\t\t|      0.�˳�         |\n"
            "\t\t|                     |\n"
            "\t\t-----------------------\n"
         << endl;
    cout << "��ѡ��";
}

void manage::login(int se, vector<student *> *st, vector<teacher *> *te)
{
    string name, name1, passwd, passwd1;
    int id, id1;

    while (1)
    {
        if (se != 3)
        {
            cout << "��������";
            cin >> id;
        }
        cout << "�������û�����";
        cin >> name;
        cout << "����������(����exit000000������һ��)��";
        cin >> passwd;
        if (passwd == "exit000000")
        {
            break;
        }
        ifstream ifs;
        if (se == 3)
        {
            ifs.open(adfile, ios::in);
            while (ifs >> name1 && ifs >> passwd1)
            {
                if (name1 == name && passwd1 == passwd)
                {
                    cout << "��֤�ɹ�" << endl;
                    system("pause");
                    system("cls");
                    (new admin(name, passwd))->start(st, te);
                    goto f1;
                }
            }
            cout << "��֤ʧ��,����������" << endl;
            system("pause");
        }
        else if(se==1)
        {
            for (int i = 0; i < (*st).size(); i++)
            {
                if ((*st)[i]->m_id == id && (*st)[i]->m_name == name && (*st)[i]->m_passwd == passwd)

                {
                    cout << "��֤�ɹ�" << endl;
                    system("pause");
                    system("cls");
                    ((*st)[i])->start();
                    goto f1;
                }
            }
            cout << "��֤ʧ��,����������" << endl;
            system("pause");
            system("cls");
        }
        else
        {
            for (int i = 0; i < (*te).size(); i++)
            {
                if ((*te)[i]->m_id == id && (*te)[i]->m_name == name && (*te)[i]->m_passwd == passwd)

                {
                    cout << "��֤�ɹ�" << endl;
                    system("pause");
                    system("cls");
                    ((*te)[i])->start(st);
                    goto f1;
                }
            }
        }
    }
 f1:
    return;
}

void fullsave(vector<student *> *st, vector<teacher *> *te)
{
    ofstream ofs;
    ofs.open(stfile, ios::out);
    for (int i = 0; i < (*st).size(); i++)
    {
        string arr1 = "";
        for (int k = 0; k < 5; k++)
        {
            for (int j = 0; j < 3; j++)
            {
                arr1 += char(48+(*st)[i]->m_arr[k][j]);
            }
        }
        ofs << (*st)[i]->m_id << " " << (*st)[i]->m_name << " " << (*st)[i]->m_passwd << " " << arr1 << " ";
    }
    ofs.close();
    ofs.open(tefile, ios::out);
    for (int i = 0; i < (*te).size(); i++)
    {
        ofs << (*te)[i]->m_id << " " << (*te)[i]->m_name << " " << (*te)[i]->m_passwd << " ";
    }
    ofs.close();
}