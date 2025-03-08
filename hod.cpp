#include "hod.h"

bool Hod::login()
{
	string h_id, h_pass;
	cout << "HOD login:" << endl;
	cout << "Enter your ID:" << endl;
	cin >> h_id;
	cout << "Enter your password:" << endl;
	cin >> h_pass;
	ifstream file("HOD.txt");
	string line;
	while (getline(file, line))
	{
		stringstream ss(line);
		getline(ss, hid, ',');
		getline(ss, fname, ',');
		getline(ss, lname, ',');
		getline(ss, department, ',');
		getline(ss, username, ',');
		getline(ss, gender, ',');
		getline(ss, cnumber, ',');
		getline(ss, password, ',');
		getline(ss, rdate, ',');
		getline(ss, address, ',');
		if (h_id == hid && h_pass == password)
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

void Hod::hodtimetable()
{
	ifstream file("HodSchedule.txt");
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			istringstream ss(line);
			string token;
			int count = 0;
			string h_id, fName, lecture, lectured, lecturet;
			while (getline(ss, token, ','))
			{
				if (count == 0)
				{
					h_id = token;
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
			if (h_id == hid)
			{
				cout << "Hod ID: " << h_id << endl;
				cout << "Hod Name: " << fname << endl;
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
