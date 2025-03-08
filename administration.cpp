#include "administration.h"

bool administration::login()
{
	string a_id, a_pass;
	
	cout << "Input Your admin name: " << endl;
	cin >> a_id;
	cout << "Input Your admin Password: " << endl;
	cin >> a_pass;
	if (a_id == "admin" && a_pass == "admin")
	{
		return true;
	}
	else
	{
		return false;
	}

}
void administration::addteacher(teacher teachers[])
{
	static int idcount = 0;
	string name;
	teacher newteacher;

	
	cout << "                               Enter Your Department: " << endl;
	cout << "                               Enter Spelling correctly: " << endl;
	cout << "                            1. Computer Science" << endl;
	cout << "                            2. Electric Engineering" << endl;
	cout << "                            3. Software Engineering" << endl;
	cout << "                            4. Business" << endl;
	cout << "                            5. Social Sciences" << endl;

	cin >> select;
	if (select == "computerscence")
	{
		chr = "CS";
	}
	else if (select == "electricalengineering")
	{
		chr = "EE";
	}
	else if (select == "softwareengineering")
	{
		chr = "SE";
	}
	else if (select == "business")
	{
		chr = "B";
	}
	else if (select == "socialscience")
	{
		chr = "SC";
	}
	idcount++;
	newteacher.tid = chr + "-" + to_string(idcount);
	
	newteacher.department = select;
	ofstream file;
	file.open("Teacher.txt", ios::app);

	if (file.is_open())
	{
		cout << "Input FirstName: " << endl;
		cin.ignore(1);
		getline(cin, newteacher.fname);
		cout << "Input lastName: " << endl;
		getline(cin, newteacher.lname);
		cout << "Input userName: " << endl;
		getline(cin, newteacher.username);
		cout << "Input password: " << endl;
		getline(cin, newteacher.password);
		cout << "Input registrationdate: " << endl;
		getline(cin, newteacher.rdate);
		cout << "Input gender: " << endl;
		getline(cin, newteacher.gender);
		cout << "Input contactnumber: " << endl;
		getline(cin, newteacher.cnumber);
		cout << "Input qualification: " << endl;
		getline(cin, newteacher.qualification);
		cout << "Input address: " << endl;
		getline(cin, newteacher.address);
		cout << "New Teacher has been Registered Sucessfully: " << endl;
		//cout << newteacher.tid << newteacher.fname << "," << newteacher.lname << "," << newteacher.department << ","  << "," << newteacher.username << "," << newteacher.password << "," << newteacher.rdate << "," << newteacher.gender << "," << newteacher.cnumber << "," << newteacher.address << endl;
		file << newteacher.tid << "," << newteacher.fname << "," << newteacher.lname << "," << newteacher.department  << "," << newteacher.username << "," << newteacher.gender << "," << newteacher.cnumber << "," << newteacher.password << "," << newteacher.rdate << "," << newteacher.address << endl;
		file.close();
	}
	else
	{
		cout << "Unable to register the teacher there could be error in opening the file: " << endl;
	}


}
//////////////////////////////////////////////////////////////////////////////////////////////
void administration::editteacher() 
{
	string id;
	cout << "Enter Teacher ID: ";
	cin >> id;

	// Open the Teacher.txt file in read mode
	ifstream file("Teacher.txt");

	// Create a temporary file to store the modified records
	ofstream temp("temp.txt");

	if (file.is_open() && temp.is_open()) {
		string line;
		bool found = false;

		// Read each line from the file
		while (getline(file, line)) {
			istringstream ss(line);
			string token;
			int count = 0;
			teacher t;

			// Parse the line and create a teacher object
			while (getline(ss, token, ',')) {
				switch (count) {
				case 0:
					t.tid = token;
					break;
				case 1:
					t.fname = token;
					break;
				case 2:
					t.lname = token;
					break;
				case 3:
					t.department = token;
					break;
				case 4:
					t.username = token;
					break;
				case 5:
					t.gender = token;
					break;
				case 6:
					t.cnumber = token;
					break;
				case 7:
					t.password = token;
					break;
				case 8:
					t.rdate = token;
					break;
				case 9:
					t.address = token;
					break;
				case 10:
					t.qualification = token;
					break;
				case 11:
					t.salary = token;
					break;
				default:
					break;
				}
				count++;
			}

			// Check if the current teacher ID matches the input ID
			if (t.tid == id) {
				found = true;
				cout << "Enter new Address: ";
				getline(cin >> ws, t.address);  // ws is used to clear the input buffer

				cout << "Enter new Contact No: ";
				getline(cin, t.cnumber);

				cout << "Enter new Qualification: ";
				getline(cin, t.qualification);

				cout << "Enter new Salary: ";
				getline(cin, t.salary);

				// Write the modified teacher object to the temporary file
				temp << t.tid << "," << t.fname << "," << t.lname << "," << t.department
					<< "," << t.username << "," << t.gender << "," << t.cnumber << ","
					<< t.password << "," << t.rdate << "," << t.address << ","
					<< t.qualification << "," << t.salary << endl;
			}
			else {
				// Write the original line to the temporary file
				temp << line << endl;
			}
		}

		file.close();
		temp.close();

		if (found) {
			// Replace the original file with the temporary file
			remove("Teacher.txt");
			rename("temp.txt", "Teacher.txt");
			cout << "Teacher details updated successfully." << endl;
		}
		else {
			remove("temp.txt");
			cout << "Teacher not found." << endl;
		}
	}
	else {
		cout << "Unable to open file." << endl;
	}
}


void administration::veiwallteachers(teacher teachers[]) 
{
	ifstream file;
	file.open("Teacher.txt");
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			istringstream ss(line);
			string token;
			int count = 0;
			while (getline(ss, token, ',')) {
				switch (count) {
				case 0:
					cout << "Teacher ID: " << token << endl;
					break;
				case 1:
					cout << "First Name: " << token << endl;
					break;
				case 2:
					cout << "Last Name: " << token << endl;
					break;
				case 3:
					cout << "Department: " << token << endl;
					break;
				case 4:
					cout << "Username: " << token << endl;
					break;
				case 5:
					cout << "Gender: " << token << endl;
					break;
				case 6:
					cout << "Contact Number: " << token << endl;
					break;
				default:
					break;
				}
				count++;
			}
			cout << "**********************************" << endl;
			cout << "**********************************" << endl;
		}
		file.close();
	}
	else {
		cout << "Unable to open file." << endl;
	}
}




void administration::addstudent(student students[])
{
	
	student newstudent;
	string fname, lname, department, cnumber, sid, chr;
	string date, gender, qualification, address;
	string username, password, rdate, select, fees;
	static int idcount = 0;
	string name;
	
	cout << "                               Enter The Year Of Admission: " << endl;
	cout << "                            1. 2019" << endl;
	cout << "                            2. 2020" << endl;
	cout << "                            3. 2021" << endl;
	cout << "                            4. 2022" << endl;
	cout << "                            5. 2023" << endl;

	cin >> select;
	if (select == "2019")
	{
		chr = "19F";
	}
	else if (select == "2020")
	{
		chr = "20F";
	}
	else if (select == "2021")
	{
		chr = "21F";
	}
	else if (select == "2022")
	{
		chr = "22F";
	}
	else if (select == "2023")
	{
		chr = "23F";
	}
	idcount++;
	newstudent.sid = chr + "-" + to_string(idcount);
	
	ofstream file;
	file.open("Student.txt", ios::app);

	if (file.is_open())
	{
		cout << "                               Enter Your Department: " << endl;
		cout << "                               Enter Spelling correctly: " << endl;
		cout << "                            1. Computer Science" << endl;
		cout << "                            2. Electric Engineering" << endl;
		cout << "                            3. Software Engineering" << endl;
		cout << "                            4. Business" << endl;
		cout << "                            5. Social Sciences" << endl;
		cin.ignore(1);
		getline(cin, newstudent.department);
		cout << "Input FirstName: " << endl;		
		getline(cin, newstudent.fname);
		cout << "Input lastName: " << endl;
		getline(cin, newstudent.lname);
		cout << "Input userName: " << endl;
		getline(cin, newstudent.username);
		cout << "Input password: " << endl;
		getline(cin, newstudent.password);
		cout << "Input registrationdate: " << endl;
		getline(cin, newstudent.rdate);
		cout << "Input gender: " << endl;
		getline(cin, newstudent.gender);
		cout << "Input contactnumber: " << endl;
		getline(cin, newstudent.cnumber);
		cout << "Input qualification: " << endl;
		getline(cin, newstudent.qualification);
		cout << "Input address: " << endl;
		getline(cin, newstudent.address);
		cout << "Input Fees Status (paid) or (unpaid): " << endl;
		getline(cin, newstudent.fees);
		cout << "New Student has been Registered Sucessfully: " << endl;
		//cout << newteacher.tid << newteacher.fname << "," << newteacher.lname << "," << newteacher.department << ","  << "," << newteacher.username << "," << newteacher.password << "," << newteacher.rdate << "," << newteacher.gender << "," << newteacher.cnumber << "," << newteacher.address << endl;
		file << newstudent.sid << "," << newstudent.fname << "," << newstudent.lname << "," << newstudent.department << "," << newstudent.username << "," << newstudent.gender << "," << newstudent.cnumber << "," << newstudent.password << "," << newstudent.fees << "," << newstudent.rdate << "," << newstudent.address << endl;
		file.close();
	}
	else
	{
		cout << "Unable to register the Student there could be error in opening the file: " << endl;
	}

	


}

void administration::editstudent(student students[])
{

	string id;
	cout << "Enter Student ID: ";
	cin >> id;

	// Open the Teacher.txt file in read mode
	ifstream file("Student.txt");

	// Create a temporary file to store the modified records
	ofstream temp2("temp2.txt");

	if (file.is_open() && temp2.is_open()) {
		string line;
		bool found = false;

		// Read each line from the file
		while (getline(file, line)) {
			istringstream ss(line);
			string token;
			int count = 0;
			student s;

			// Parse the line and create a teacher object
			while (getline(ss, token, ',')) {
				switch (count) {
				case 0:
					s.sid = token;
					break;
				case 1:
					s.fname = token;
					break;
				case 2:
					s.lname = token;
					break;
				case 3:
					s.department = token;
					break;
				case 4:
					s.username = token;
					break;
				case 5:
					s.gender = token;
					break;
				case 6:
					s.cnumber = token;
					break;
				case 7:
					s.password = token;
					break;
				case 8:
					s.rdate = token;
					break;
				case 9:
					s.address = token;
					break;
				case 10:
					s.qualification = token;
					break;
				case 11:
					s.fees = token;
					break;
				default:
					break;
				}
				count++;
			}

			// Check if the current teacher ID matches the input ID
			if (s.sid == id) {
				found = true;
				cout << "Enter new First Name: ";
				getline(cin >> ws, s.fname);
				cout << "Enter new Last Name: ";
				getline(cin, s.lname);  // ws is used to clear the input buffer
				cout << "Enter new Contact No: ";
				getline(cin, s.cnumber);
				cout << "Enter new address: ";
				getline(cin, s.address);
				cout << "Enter fees Status (paid) or (unpaid): ";
				getline(cin, s.fees);

				
				// Write the modified teacher object to the temporary file
				temp2<< s.sid << "," << s.fname << "," << s.lname << "," << s.department
					<< "," << s.username << "," << s.gender << "," << s.cnumber << ","
					<< s.password << "," << s.rdate << "," << s.address << ","
					<< s.qualification << "," << s.fees << endl;
			}
			else {
				// Write the original line to the temporary file
				temp2 << line << endl;
			}
		}

		file.close();
		temp2.close();

		if (found) {
			// Replace the original file with the temporary file
			remove("Student.txt");
			rename("temp2.txt", "Student.txt");
			cout << "Student details updated successfully." << endl;
		}
		else {
			remove("temp2.txt");
			cout << "Student not found." << endl;
		}
	}
	else {
		cout << "Unable to open file." << endl;
	}
}

void administration::veiwallstudent(student students[])
{
	ifstream file;
	file.open("Student.txt");
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			istringstream ss(line);
			string token;
			int count = 0;
			while (getline(ss, token, ',')) {
				switch (count) {
				case 0:
					cout << "Student ID: " << token << endl;
					break;
				case 1:
					cout << "First Name: " << token << endl;
					break;
				case 2:
					cout << "Last Name: " << token << endl;
					break;
				case 3:
					cout << "Department: " << token << endl;
					break;
				case 4:
					cout << "Username: " << token << endl;
					break;
				case 5:
					cout << "Gender: " << token << endl;
					break;
				case 6:
					cout << "Contact Number: " << token << endl;
					break;
				default:
					break;
				}
				count++;
			}
			cout << "**********************************" << endl;
			cout << "**********************************" << endl;
		}
		file.close();
	}
	else {
		cout << "Unable to open file." << endl;
	}
}

void administration::addtimetable(teacher teachers[])
{
	string lecture, lectured, lecturet;
	int num;
	teacher t2;
	string tid;
	cout << "input teacher id for whom you want to add timetable: " << endl;
	cin >> tid;
	ifstream file("Teacher.txt");
	ofstream file2("Schedule.txt", ios::app);
	if (file.is_open() && file2.is_open()) {
		string line;
		bool found = false;
		// Read each line from the file
		while (getline(file, line)) {
			istringstream ss(line);
			string token;
			int count2 = 0;
			// Parse the line and create a teacher object
			while (getline(ss, token, ','))
			{
				if (count2 == 0)
				{
					t2.tid = token;
				}
				else if (count2 == 1)
				{
					t2.fname = token;
				}
				else if (count2 == 2)
				{
					t2.lname = token;
				}
				else if (count2 == 3)
				{
					t2.department = token;
				}
				else if (count2 == 4)
				{
					t2.username = token;
				}
				else if (count2 == 5)
				{
					t2.gender = token;
				}
				else if (count2 == 6)
				{
					t2.cnumber = token;
				}
				else if (count2 == 7)
				{
					t2.password = token;
				}
				else if (count2 == 8)
				{
					t2.rdate = token;
				}
				else if (count2 == 9)
				{
					t2.address = token;
				}
				count2++;
			}
			if (t2.tid == tid)
			{
				found = true;
				cout << "how many lectures do you want to add? " << endl;
				cin >> num;
				while (num > 0)
				{

					cout << "Enter Lecture Name: " << endl;
					cin.ignore(1);
					getline(cin, lecture);
					cout << "Enter Lecture date: " << endl;
					getline(cin, lectured);
					cout << "Enter Lecture Time: " << endl;
					getline(cin, lecturet);
					file2 << t2.tid << "," << t2.fname << "," << lecture << "," << lectured << "," << lecturet << endl;
					num--;
				}
				cout << "TimeTable Sucessfully Make: " << endl;
				break; // no need to continue looping once the teacher is found
			}
		}
		if (!found)
		{
			cout << "Teacher ID not found." << endl;
		}
	}
	else
	{
		cout << "Unable to open file." << endl;
	}
	file.close();
	file2.close();
}

void administration::addtimetable()
{
	string lecture, lectured, lecturet;
	int num;
	Hod t2;
	string tid;
	cout << "input Hod id for whom you want to add timetable: " << endl;
	cin >> tid;
	ifstream file("Hod.txt");
	ofstream file3("HodSchedule.txt", ios::app);
	if (file.is_open() && file3.is_open()) 
	{
		string line;
		bool found = false;
		// Read each line from the file
		while (getline(file, line)) {
			istringstream ss(line);
			string token;
			int count2 = 0;
			// Parse the line and create a teacher object
			while (getline(ss, token, ','))
			{
				if (count2 == 0)
				{
					t2.hid = token;
				}
				else if (count2 == 1)
				{
					t2.fname = token;
				}
				else if (count2 == 2)
				{
					t2.lname = token;
				}
				else if (count2 == 3)
				{
					t2.department = token;
				}
				else if (count2 == 4)
				{
					t2.username = token;
				}
				else if (count2 == 5)
				{
					t2.gender = token;
				}
				else if (count2 == 6)
				{
					t2.cnumber = token;
				}
				else if (count2 == 7)
				{
					t2.password = token;
				}
				else if (count2 == 8)
				{
					t2.rdate = token;
				}
				else if (count2 == 9)
				{
					t2.address = token;
				}
				count2++;
			}
			if (t2.hid == tid)
			{
				found = true;
				cout << "how many lectures do you want to add? " << endl;
				cin >> num;
				while (num > 0)
				{

					cout << "Enter Lecture Name: " << endl;
					cin.ignore(1);
					getline(cin, lecture);
					cout << "Enter Lecture date: " << endl;
					getline(cin, lectured);
					cout << "Enter Lecture Time: " << endl;
					getline(cin, lecturet);
					file3 << t2.hid << "," << t2.fname << "," << lecture << "," << lectured << "," << lecturet << endl;
					num--;
				}
				cout << "TimeTable Sucessfully Has Been Made: " << endl;
				break; // no need to continue looping once the teacher is found
			}
		}
		if (!found)
		{
			cout << "Hod ID not found." << endl;
		}
	}
	else
	{
		cout << "Unable to open file." << endl;
	}
	file.close();
	file3.close();
}

void administration::addhod(Hod hods[])
{
	static int idcount = 0;
	string name;
	Hod newhod ;


	cout << "                               Enter Your Department: " << endl;
	cout << "                               Enter Spelling correctly: " << endl;
	cout << "                            1. Computer Science" << endl;
	cout << "                            2. Electric Engineering" << endl;
	cout << "                            3. Software Engineering" << endl;
	cout << "                            4. Business" << endl;
	cout << "                            5. Social Sciences" << endl;

	cin >> select;
	if (select == "computerscence")
	{
		chr = "CS";
	}
	else if (select == "electricalengineering")
	{
		chr = "EE";
	}
	else if (select == "softwareengineering")
	{
		chr = "SE";
	}
	else if (select == "business")
	{
		chr = "B";
	}
	else if (select == "socialscience")
	{
		chr = "SC";
	}
	idcount++;
	newhod.hid = chr + "-" + to_string(idcount);

	newhod.department = select;
	ofstream file;
	file.open("Hod.txt", ios::app);

	if (file.is_open())
	{
		cout << "Input FirstName: " << endl;
		cin.ignore(1);
		getline(cin, newhod.fname);
		cout << "Input lastName: " << endl;
		getline(cin, newhod.lname);
		cout << "Input userName: " << endl;
		getline(cin, newhod.username);
		cout << "Input password: " << endl;
		getline(cin, newhod.password);
		cout << "Input registrationdate: " << endl;
		getline(cin, newhod.rdate);
		cout << "Input gender: " << endl;
		getline(cin, newhod.gender);
		cout << "Input contactnumber: " << endl;
		getline(cin, newhod.cnumber);
		cout << "Input qualification: " << endl;
		getline(cin, newhod.qualification);
		cout << "Input address: " << endl;
		getline(cin, newhod.address);
		cout << "New Hod has been Registered Sucessfully: " << endl;
		//cout << newteacher.tid << newteacher.fname << "," << newteacher.lname << "," << newteacher.department << ","  << "," << newteacher.username << "," << newteacher.password << "," << newteacher.rdate << "," << newteacher.gender << "," << newteacher.cnumber << "," << newteacher.address << endl;
		file << newhod.hid << "," << newhod.fname << "," << newhod.lname << "," << newhod.department << "," << newhod.username << "," << newhod.gender << "," << newhod.cnumber << "," << newhod.password << "," << newhod.rdate << "," << newhod.address << endl;
		file.close();
	}
	else
	{
		cout << "Unable to register the hod there could be error in opening the file: " << endl;
	}
}
void administration::edithod()
{
	string id;
	cout << "Enter Hod ID: ";
	cin >> id;

	// Open the Teacher.txt file in read mode
	ifstream file("Hod.txt");

	// Create a temporary file to store the modified records
	ofstream temp3("temp3.txt");

	if (file.is_open() && temp3.is_open()) {
		string line;
		bool found = false;

		// Read each line from the file
		while (getline(file, line)) {
			istringstream ss(line);
			string token;
			int count = 0;
			Hod h;

			// Parse the line and create a teacher object
			while (getline(ss, token, ',')) {
				switch (count) {
				case 0:
					h.hid = token;
					break;
				case 1:
					h.fname = token;
					break;
				case 2:
					h.lname = token;
					break;
				case 3:
					h.department = token;
					break;
				case 4:
					h.username = token;
					break;
				case 5:
					h.gender = token;
					break;
				case 6:
					h.cnumber = token;
					break;
				case 7:
					h.password = token;
					break;
				case 8:
					h.rdate = token;
					break;
				case 9:
					h.address = token;
					break;
				case 10:
					h.qualification = token;
					break;
				case 11:
					h.salary = token;
					break;
				default:
					break;
				}
				count++;
			}

			// Check if the current teacher ID matches the input ID
			if (h.hid == id) {
				found = true;
				cout << "Enter new Address: ";
				getline(cin >> ws, h.address);  // ws is used to clear the input buffer

				cout << "Enter new Contact No: ";
				getline(cin, h.cnumber);

				cout << "Enter new Qualification: ";
				getline(cin, h.qualification);

				cout << "Enter new Salary: ";
				getline(cin, h.salary);

				// Write the modified teacher object to the temporary file
				temp3 << h.hid << "," << h.fname << "," << h.lname << "," << h.department
					<< "," << h.username << "," << h.gender << "," << h.cnumber << ","
					<< h.password << "," << h.rdate << "," << h.address << ","
					<< h.qualification << "," << h.salary << endl;
			}
			else {
				// Write the original line to the temporary file
				temp3 << line << endl;
			}
		}

		file.close();
		temp3.close();

		if (found) {
			// Replace the original file with the temporary file
			remove("Hod.txt");
			rename("temp3.txt", "Hod.txt");
			cout << "Hod details updated successfully." << endl;
		}
		else {
			remove("temp3.txt");
			cout << "Hod not found." << endl;
		}
	}
	else {
		cout << "Unable to open file." << endl;
	}
}
void administration::viewallhod(Hod hods[])
{
	ifstream file;
	file.open("Hod.txt");
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			istringstream ss(line);
			string token;
			int count = 0;
			while (getline(ss, token, ',')) {
				switch (count) {
				case 0:
					cout << "Hod ID: " << token << endl;
					break;
				case 1:
					cout << "First Name: " << token << endl;
					break;
				case 2:
					cout << "Last Name: " << token << endl;
					break;
				case 3:
					cout << "Department: " << token << endl;
					break;
				case 4:
					cout << "Username: " << token << endl;
					break;
				case 5:
					cout << "Gender: " << token << endl;
					break;
				case 6:
					cout << "Contact Number: " << token << endl;
					break;
				default:
					break;
				}
				count++;
			}
			cout << "**********************************" << endl;
			cout << "**********************************" << endl;
		}
		file.close();
	}
	else {
		cout << "Unable to open file." << endl;
	}
}
