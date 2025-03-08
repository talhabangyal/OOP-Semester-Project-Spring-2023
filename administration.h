#pragma once
#include<iostream>
#include"teacher.h"
#include"student.h"
#include"hod.h"
#include"base.h"
#include"department.h"
#include"courses.h"
#include"schedule.h"
#include<fstream>
#include<string>
using namespace std;

class administration:public base
{
private:
	string fname, lname, department, cnumber, tid, chr;
	string date, gender, qualification, address;
	string username, password, rdate, select;
	int tnumber = 50;
public:
	string banknum;
	int idcount;
	bool login();
	void addteacher(class teacher teachers[]);
	void editteacher();
	void veiwallteachers(class teacher teachers[]);
	void addtimetable(class teacher teacher[]);
	void addtimetable();
	void addstudent(class student students[]);
	void editstudent(class student students[]);
	void veiwallstudent(class student students[]);
	void addhod(class Hod hods[]);
	void edithod();
	void viewallhod(class Hod hods[]);
	
};
