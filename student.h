#pragma once
#include"base.h"
#include"courses.h"
#include"teacher.h"
#include"administration.h"
#include<iostream>
#include<fstream>
using namespace std;

class student:public base
{
public:
	string fname, lname, department, cnumber;
	string date, gender, number, qualification, address;
	string username, password, rdate, sid,fees;
	bool login();
	void viewattendance();
	void viewmarks();
	void viewgrades(class student students[], class courses course[]);
	void viewallcourse(class courses courses[]);
	void feestatus(student students[]);
};
