#include "teacher.h"


bool teacher::login()
{

	string t_id, t_pass;
	cout << "Teacher login:" << endl;
	cout << "Enter your username:" << endl;
	cin >> t_id;
	cout << "Enter your password:" << endl;
	cin >> t_pass;
	ifstream file("Teacher.txt");
	string line;
	while (getline(file, line))
	{
		stringstream ss(line);
		getline(ss, tid, ',');
		getline(ss, fname, ',');
		getline(ss, lname, ',');
		getline(ss, department, ',');
		getline(ss, username, ',');
		getline(ss, gender, ',');
		getline(ss, cnumber, ',');
		getline(ss, password, ',');
		getline(ss, rdate, ',');
		getline(ss, address, ',');
		if (t_id == tid && t_pass == password)
		{
			cout << "Login successful!" << endl;
			file.close();
			return true;
		}
	}
	cout << "Invalid username or password!" << endl;
	file.close();
	return false;
}

void teacher::teachertimetable()
{
	ifstream file("Schedule.txt");
	if (file.is_open()) {
		string line;
		while (getline(file, line)) 
		{
			istringstream ss(line);
			string token;
			int count = 0;
			string t_id, fName, lecture, lectured, lecturet;
			while (getline(ss, token, ','))
			{
				if (count == 0)
				{
					t_id = token;
				}
				else if (count == 1)
				{
					fName = token;
				}
				else if (count == 2)
				{
					lecture = token;
				}
				else if (count == 3)
				{
					lectured = token;
				}
				else if (count == 4)
				{
					lecturet = token;
				}
				count++;
			}
			if (t_id == tid)
			{
				cout << "Teacher ID: " << t_id << endl;
				cout << "Teacher Name: " << fname << endl;
				cout << "Lecture: " << lecture << endl;
				cout << "Lecture Date: " << lectured << endl;
				cout << "Lecture Time: " << lecturet << endl;
				cout << "..........................................." << endl;
			}
		}
	}
	else
	{
		cout << "Unable to open file." << endl;
	}
	file.close();
}

void teacher::assignmarks()
{
	string studentid;
	string courseid;
	string marks;
	cin.ignore(1);
	cout << "student id of whom you want to add Marks: " << endl;
	getline(cin, studentid);
	cout << "course id to add Marks: " << endl;
	getline(cin, courseid);
	cout << "Enter the Marks: " << endl;
	getline(cin, marks);

	ofstream file;
	file.open("Marks.txt", ios::app);
	if (file.is_open()) {
		file << studentid << "," << courseid << "," << marks << endl;
		cout << "Marks assigned successfully." << endl;
	}
	else {
		cout << "Unable to open file." << endl;
	}
	file.close();
}


void teacher::assigngarde(student students[], teacher teacher[], courses course[])
{
	cout << "Enter student ID: ";
	string sid;
	cin >> sid;

	ifstream file("Marks.txt");
	if (!file.is_open()) {
		cout << "Unable to open file." << endl;
		return;
	}

	ofstream gradeFile("Grade.txt", ios::app);
	if (!gradeFile.is_open()) {
		cout << "Unable to open file." << endl;
		file.close();
		return;
	}

	string line;
	bool found = false;
	while (getline(file, line)) 
	{
		istringstream ss(line);
		string token;
		int count = 0;
		string courseCode;
		int marks;
		while (getline(ss, token, ',')) 
		{
			switch (count) 
			{
			case 0:
				if (token == sid) 
				{
					found = true;
				}
				break;
			case 1:
				courseCode = token;
				break;
			case 2:
				marks = stoi(token);
				break;
			}
			count++;
		}
		if (found) 
		{
			char grade;
			if (marks >= 90) 
			{
				grade = 'A';
			}
			else if (marks >= 80) 
			{
				grade = 'B';
			}
			else if (marks >= 70) 
			
			{
				grade = 'C';
			}
			else if (marks >= 60) 
			{
				grade = 'D';
			}
			else {
				grade = 'F';
			}
			gradeFile << sid << "," << courseCode << "," << grade << endl;
			found = false;
		}
	}
	if (!found) 
	{
		cout << "No marks found for student " << sid << endl;
	}

	file.close();
	gradeFile.close();
}


void teacher::markattendence(courses course[])
{
	

}



	