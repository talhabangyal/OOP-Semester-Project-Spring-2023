#include "student.h"

bool student::login()
{
	string s_id, s_pass;
	cout << "Student login:" << endl;
	cout << "Enter your ID:" << endl;
	cin >> s_id;
	cout << "Enter your password:" << endl;
	cin >> s_pass;
	ifstream file("Student.txt");
	string line;
	while (getline(file, line))
	{
		stringstream ss(line);
		getline(ss, sid, ',');
		getline(ss, fname, ',');
		getline(ss, lname, ',');
		getline(ss, department, ',');
		getline(ss, username, ',');
		getline(ss, gender, ',');
		getline(ss, cnumber, ',');
		getline(ss, password, ',');
		getline(ss, rdate, ',');
		getline(ss, address, ',');
		if (s_id == sid && s_pass == password)
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
void student::viewmarks()
{
	ifstream file("Marks.txt");
	if (!file.is_open()) {
		cout << "Unable to open file." << endl;
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
			switch (count) {
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
			cout << "Marks for student " << sid << " in course " << courseCode << ": " << marks << endl;
			found = false;
		}
	}
	if (!found) 
	{
		cout << "No marks found for student " << sid << endl;
	}

	file.close();

}
void student::viewattendance() 
{
	
}

   
	
	void student::viewgrades(student students[], courses course[])
	{
		ifstream file("Marks.txt");
		if (!file.is_open()) {
			cout << "Unable to open file." << endl;
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
				cout << "Grade for student " << sid << " in course " << courseCode << ": " << grade << endl;
				found = false;
			}
		}
		if (!found) 
		{
			cout << "No marks found for student " << sid << endl;
		}

		file.close();
	}

	void student::viewallcourse(courses courses[])
	{
		ifstream file("Marks.txt");
		if (!file.is_open()) {
			cout << "Unable to open file." << endl;
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
				cout << "You Are Registered in the course: " << sid << " in course " << courseCode  << endl;
				found = false;
			}
		}
		if (!found) 
		{
			cout << "No marks found for student " << sid << endl;
		}

		file.close();

	}

	



	




