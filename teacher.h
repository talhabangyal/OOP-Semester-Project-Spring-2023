#pragma once
#include"base.h"
#include"administration.h"
#include"department.h"
#include"schedule.h"
#include"student.h"
#include"courses.h"
#include<iostream>
#include<fstream>
#include<string>
class Hod;
class teacher:public base 
{
public:
	friend class Hod;
	string fname, lname, department, cnumber;
	string date, gender, number, qualification, address;
	string username, password, rdate,tid,salary,sid,marks,courseid;
	bool login();
	void teachertimetable();
	void assignmarks();
	void assigngarde(class student students[], class teacher teacher[], class courses course[]);
	void markattendence(courses course[]);
	friend class Hod;
};
