#include "D:\c++\computerhouse\head\head2.h"

extern int arr[5][3];

void fun(student *std)
{
   for (int i = 0; i < 5; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         (*std).m_arr[i][j] = 0;
         arr[i][j] = 0;
      }
   }
}
void admin::start(vector<student *> *st, vector<teacher *> *const te)
{
   while (1)
   {
      int se;
      // init(st,te);
      this->showmenu();
      cin >> se;
      switch (se)
      {
      case 1:
      {
         this->appe(st, te);
         break;
      }
      case 2:
      {
         show(st, te);
         break;
      }
      case 3:
      {
         showcom();
         break;
      }
      case 4:
      {
         clear(st);
         break;
      }
      case 0:
      {
         fullsave(st, te);
         return;
      }
      }
   }

   system("pause");
}
void admin::showmenu()
{
   cout << "--------��ӭ����Ա-------" << endl
        << endl
        << "\t\t--------------------------\n"
           "\t\t|                         |\n"
           "\t\t|      1.����˺�         |\n"
           "\t\t|                         |\n"
           "\t\t|      2.�鿴�˺�         |\n"
           "\t\t|                         |\n"
           "\t\t|      3.�鿴����         |\n"
           "\t\t|                         |\n"
           "\t\t|      4.���ԤԼ         |\n"
           "\t\t|                         |\n"
           "\t\t|      0.ע����¼         |\n"
           "\t\t|                         |\n"
           "\t\t--------------------------\n"
        << endl;
   cout << "��ѡ��";
}
void admin::appe(vector<student *> *st, vector<teacher *> *const te)
{
   cout << "��׼�����\n"
           "ѧ���˺�-----1\n"
           "��ʦ�˺�-----2\n"
        << endl;
   int se, id;
   string name, passwd;
   cin >> se;
flag:
   cout << "�������ţ�";
   cin >> id;
   if (se == 1)
   {
      for (vector<student *>::iterator it = (*st).begin(); it != (*st).end(); it++)
      {
         if ((*it)->m_id == id)
         {
            cout << "����ظ�" << endl;
            system("pause");
            goto flag;
         }
      }
   }
   else
   {
      for (vector<teacher *>::iterator it = (*te).begin(); it != (*te).end(); it++)
      {
         if ((*it)->m_id == id)
         {
            cout << "����ظ�" << endl;
            system("pause");
            goto flag;
         }
      }
   }
   cout << "������������";
   cin >> name;
   cout << "���������룺";
   cin >> passwd;
   // ofstream ofs;
   if (se == 1)
   {
      // ofs.open(stfile, ios::app);
      // ofs << id << ' ' << name << ' ' << passwd << ' ' << string(15, '0') << ' ';
      (*st).push_back(new student(id, name, passwd));
   }
   else
   {
      // ofs.open(tefile, ios::app);
      // ofs << id << ' ' << name << ' ' << passwd << ' ';
      (*te).push_back(new teacher(id, name, passwd));
   }

   // ofs.close();
   cout << "¼��ɹ�\n";
   system("pause");
   system("cls");
}
// void admin::init(vector<student *>*st,vector<teacher *> *const te)
// {
//    int id;
//    string name, passwd,arr;
//    ifstream ifs;
//    ifs.open(stfile, ios::in);
//    while (ifs >> id && ifs >> name && ifs >> passwd&& ifs>>arr)
//    {
//       student *s = new student(id, name, passwd,arr);
//       (*st).push_back(s);
//    }
//    ifs.close();
//    ifs.open(tefile, ios::in);
//    while (ifs >> id && ifs >> name && ifs >> passwd)
//    {
//       teacher *s = new teacher(id, name, passwd);
//       (*te).push_back(s);
//    }
//    ifs.close();
// }
void admin::show(vector<student *> *st, vector<teacher *> *const te)
{
   cout << "ѧ��:" << endl;
   for (int i = 0; i < (*st).size(); i++)
   {
      cout << "��ţ�" << (*st)[i]->m_id << "������" << (*st)[i]->m_name << "���룺" << (*st)[i]->m_passwd << endl;
   }
   cout << "��ʦ:" << endl;
   for (int i = 0; i < (*te).size(); i++)
   {
      cout << "��ţ�" << (*te)[i]->m_id << "������" << (*te)[i]->m_name << "���룺" << (*te)[i]->m_passwd << endl;
   }
   cout << "��ʾ���" << endl;
   system("pause");
   system("cls");
}
void admin::showcom()
{
   int id, cont;
   ifstream ifs;
   ifs.open(cofile, ios::in);
   while (ifs >> id && ifs >> cont)
   {
      cout << "��ţ�" << id << " ��������" << cont << endl;
   }
   ifs.close();
}
void admin::clear(vector<student *> *st)
{
   for_each(st->begin(), st->end(), fun);
   cout << "������" << endl;
   system("pause");
   system("cls");
}

