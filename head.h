#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#define adfile "D:\\c++\\computerhouse\\admin.txt"
#define stfile "D:\\c++\\computerhouse\\student.txt"
#define tefile "D:\\c++\\computerhouse\\teacher.txt"
#define cofile "D:\\c++\\computerhouse\\computer.txt"

extern int arr[5][3];

using namespace std;



class person
{
public:
    string m_name;
    string m_passwd;
    int m_id;

    virtual void showmenu() = 0;
};
class student : public person
{
public:
    int m_arr[5][3];

    student(){};
    student(int id, string name, string passwd, string arr1 = string(15, '0'))
    {
        m_id = id;
        m_name = name;
        m_passwd = passwd;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                m_arr[i][j] = int(arr1[3 * i + j])-48;
                if (m_arr[i][j] == 2)
                {
                    arr[i][j] += 1;
                }
            }
        }
    }
    void showmenu();
    void showapp(int table[5][3]);
    void clear();
    void start();
    void apply();
    void seek();
    void cancel();

};

class teacher : public person
{
public:
    teacher(){};
    teacher(int id, string name, string passwd)
    {
        m_id = id;
        m_name = name;
        m_passwd = passwd;
    }
    void showmenu();
    void start(vector<student *> *st);
    void seek(vector<student *> *st);
    void examine(vector<student *> *st);
};

class admin : public person
{
public:
    admin(){};
    admin(string name, string passwd)
    {
        m_name = name;
        m_passwd = passwd;
    }
    void showmenu();
    void appe(vector<student *> *st, vector<teacher *> *te);
    void show(vector<student *> *st, vector<teacher *> *te);
    void start(vector<student *> *st, vector<teacher *> *te);
    void showcom();
    void clear(vector<student *> *st);
};

void fullsave(vector<student *> *st, vector<teacher *> *te);