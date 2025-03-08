#include<iostream>
#include"base.h"
#include"administration.h"
#include"department.h"
#include"hod.h"
#include"student.h"
#include"teacher.h"
using namespace std;

int main()
{
    teacher teachers[50];
    student students[50];
    Hod hods[50];
    courses array[100];
    int select;
    student s;
    teacher t;
    Hod h;
    administration a;
   
  
    
    bool check = false;

    do
    {
        cout << "Press 1 for Student login" << endl;
        cout << "Press 2 for Teacher login" << endl;
        cout << "Press 3 for Hod login" << endl;
        cout << "Press 4 for Admin login" << endl;
        cout << "Press 0 to Exit" << endl;
        cin >> select;

        switch (select)
        {
        case 1:
           
            system("cls");
            check = s.login();
            system("cls");
            if (check == true)
            {
                cout << "What you want to do?" << endl;
                cout << "Press 1 to view your attendance: " << endl;
                cout << "Press 2 to view your marks: " << endl;
                cout << "Press 3 to veiw your grades: " << endl;
                cout << "Press 4 to view your courses: " << endl;
                int sselect;
                cin >> sselect;
                if (sselect == 1)
                {
                    s.viewattendance();
                }
                if (sselect == 2)
                {
                    s.viewmarks();
                }
                if (sselect == 3)
                {
                    s.viewgrades(students, array);
                }
                if (sselect == 4)
                {
                    s.viewallcourse(array);
                }

            }
            break;
        case 2:
            system("cls");
            check = t.login();
            system("cls");
            if (check == true)
            {
                cout << "What you want to do?" << endl;
                cout << "Press 1 to view your timetable: " << endl;
                cout << "Press 2 to assign marks: " << endl;
                cout << "Press 3 to assign grades: " << endl;
                cout << "Press 4 to mark attendance: " << endl;
                int tselect;
                cin >> tselect;
                if (tselect == 1)
                {
                    t.teachertimetable();
                }
                if (tselect == 2)
                {
                   t.assignmarks();
                    
                }
                if (tselect == 3)
                {
                    t.assigngarde(students, teachers, array);
                }
                if (tselect == 4)
                {
                    t.markattendence(array);
                }
               
            }
           
               
           break;
        case 3:
            system("cls");
            check = h.login();
            system("cls");
            int aselect;
            if (check == true)
            {
                cout << "What you want to do?" << endl;
                cout << "Press 1 to View TimeTable: " << endl;
                cout << "Press 2 to Assign Marks of student: " << endl;
                cout << "Press 3 to Assign Grades of the student: " << endl;
                cout << "Press 4 to Mark Attendance of the student: " << endl;
                cout << "Press 5 to view all Students:" << endl;
                cout << "Press 6 to view all Teachers:" << endl;
                cout << "Press 7 to Acess Student Moduke: " << endl;
                cout << "press 8 to Acess Teacher Module: " << endl;
               
                cin >> aselect;
                if (aselect == 1)
                {
                    h.hodtimetable();
                }
                if (aselect == 2)
                {
                    t.assignmarks();
                }
                if (aselect == 3)
                {
                    t.assigngarde(students, teachers, array);
                }
                if (aselect == 4)
                {
                    t.markattendence(array);
                }
                if (aselect == 5)
                {
                    
                    a.veiwallteachers(teachers);
                }
                if (aselect == 6)
                {
                    if (check == true)
                    {
                        cout << "What you want to do?" << endl;
                        cout << "Press 1 to view your attendance: " << endl;
                        cout << "Press 2 to view your marks: " << endl;
                        cout << "Press 3 to veiw your grades: " << endl;
                        cout << "Press 4 to view your courses: " << endl;
                        int sselect;
                        cin >> sselect;
                        if (sselect == 1)
                        {
                            s.viewattendance();
                        }
                        if (sselect == 2)
                        {
                            s.viewmarks();
                        }
                        if (sselect == 3)
                        {
                            s.viewgrades(students, array);
                        }
                        if (sselect == 4)
                        {
                            s.viewallcourse(array);
                        }
                    }
                }
                if (aselect == 7)
                {
                    if (check == true)
                    {
                        cout << "What you want to do?" << endl;
                        cout << "Press 1 to view your timetable: " << endl;
                        cout << "Press 2 to assign marks: " << endl;
                        cout << "Press 3 to assign grades: " << endl;
                        cout << "Press 4 to mark attendance: " << endl;
                        int tselect;
                        cin >> tselect;
                        if (tselect == 1)
                        {
                            t.teachertimetable();
                        }
                        if (tselect == 2)
                        {
                            t.assignmarks();

                        }
                        if (tselect == 3)
                        {
                            t.assigngarde(students, teachers, array);
                        }
                        if (tselect == 4)
                        {
                            t.markattendence(array);
                        }

                    }
                }
                break;
            }
               
           
        case 4:
            system("cls");
            check = a.login();
            system("cls");
            if (check == true)
            {
                cout << "What you want to do?" << endl;
                cout << "Press 1 to add new Teacher" << endl;
                cout << "Press 2 to add new Student" << endl;
                cout << "Press 3 to edit Student" << endl;
                cout << "Press 4 to edit Teacher" << endl;
                cout << "Press 5 to view all Students" << endl;
                cout << "Press 6 to view all Teachers" << endl;
                cout << "Press 7 to add timetable for the teacher: " << endl;
                cout << "press 8 to add Hod:" << endl;
                cout << "press 9 to edit Hod:" << endl;
                cout << "press 10 to view all Hod:" << endl;
                cout << "Press 11 to add timetable for the Hod: " << endl;
                cin >> aselect;
                if (aselect == 1)
                {
                    a.addteacher(teachers);
                }
                if (aselect == 2)
                {

                    a.addstudent(students);
                }
                if (aselect == 3)
                {
                    a.editstudent(students);
                }
                if (aselect == 4)
                {
                    a.editteacher();
                }
                if (aselect == 5)
                {
                    a.veiwallstudent(students);
                }
                if (aselect == 6)
                {

                    a.veiwallteachers(teachers);
                }
                if (aselect == 7)
                {

                    a.addtimetable(teachers);
                }
                if (aselect == 8)
                {

                    a.addhod(hods);
                }
                if (aselect == 9)
                {

                    a.edithod();
                }
                if (aselect == 10)
                {

                    
                    a.viewallhod(hods);
                }
                if (aselect == 11)
                {


                    a.addtimetable();
                }
            }
            else
            {
                cout << "You Dont Have the acess to Login: " << endl << endl;
            }
            break;
        default:
            cout << "Please select only from the given options: " << endl;
            cout << endl;
            break;
        }
    } while (select != 0);

    return 0;
}
