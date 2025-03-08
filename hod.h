#pragma once
#include"base.h"
#include"courses.h"
#include"administration.h"
#include"teacher.h"
#include<iostream>
#include<fstream>
using namespace std;
class Hod:public base
{
public:
	string fname, lname, department, cnumber;
	string date, gender, number, qualification, address;
	string username, password, rdate, hid, salary;
	
	
	bool login();
	void hodtimetable();
};