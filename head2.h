#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "D:\c++\computerhouse\head\head.h"
using namespace std;

class manage
{
public:
    manage(){};
    void showmenu();
    void login(int se,vector<student *>*st ,vector<teacher*>*te);
};

void init(vector<student *>*st ,vector<teacher*>*te);

