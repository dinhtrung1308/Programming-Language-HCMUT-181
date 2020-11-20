#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

#define MAX_SIZE 500
#define MAX_SIZE_STUDENT 1000
#define MAX_SIZE_COURSES 200
#define COUNT_SIZE 5
#define SEM_SIZE 3


struct user
{
	string username;
	string password;
	string position;

	string username_file[MAX_SIZE];
	string password_file[MAX_SIZE];
	string position_file[MAX_SIZE];
};

struct professor
{
	string professor_id;
	string name;
	string dob;
	string phone;
	string place;

	string professor_id_file[MAX_SIZE];
	string name_file[MAX_SIZE];
	string dob_file[MAX_SIZE];
	string phone_file[MAX_SIZE];
	string place_file[MAX_SIZE];
};

struct student
{
	string student_id;
	string name; 
	string dob; 
	string place; 

	string student_id_file[MAX_SIZE_STUDENT];
	string name_file[MAX_SIZE_STUDENT];
	string dob_file[MAX_SIZE_STUDENT];
	string place_file[MAX_SIZE_STUDENT];
};

struct course {
	string course_id; 
	string professor_id;
	string course_name;
	string credit;
	string count_student;
	string max_students;


	string course_id_file[MAX_SIZE_COURSES];
	string professor_id_file[MAX_SIZE_COURSES];
	string course_name_file[MAX_SIZE_COURSES];
	string credit_file[MAX_SIZE_COURSES];
	string count_student_file[MAX_SIZE_COURSES];
	string max_students_file[MAX_SIZE_COURSES];
};

struct grade
{
	string course_id;
	string student_id;
	string professor_id;
	string averaged_score;
	string semester;
	string score_modified_right;

	string course_id_file[MAX_SIZE_COURSES];
	string student_id_file[MAX_SIZE_COURSES];
	string professor_id_file[MAX_SIZE_COURSES];
	string averaged_score_file[MAX_SIZE_COURSES];
	string semester_file[MAX_SIZE_COURSES];
	string score_modified_right_file[MAX_SIZE_COURSES];
};

//Display menu
void displaymenu_login()
{
	cout << "\n _________________________________________________________________ ";
	cout << "\n|                     UNIVERSITY OF TECHNOLOGY                    |";
	cout << "\n|                              LOGIN                              |";
	cout << "\n|_________________________________________________________________|";
	cout << "\n|                                                                 |";
	cout << "\n| 1.  Administrator                                               |";
	cout << "\n| 2.  Professor                                                   |";
	cout << "\n| 3.  Student                                                     |";
	cout << "\n| 0.  Exit program                                                |";
	cout << "\n|_________________________________________________________________|";
	cout << endl;
}

void displaymenu_admin()
{
	cout << "\n _________________________________________________________________ ";
	cout << "\n|                     UNIVERSITY OF TECHNOLOGY                    |";
	cout << "\n|                              ADMIN                              |";
	cout << "\n|_________________________________________________________________|";
	cout << "\n|                                                                 |";
	cout << "\n| 1.  Find user                                                   |";
	cout << "\n| 2.  Add professor                                               |";
	cout << "\n| 3.  Add student                                                 |";
	cout << "\n| 4.  Remove professor                                            |";
	cout << "\n| 5.  Remove student                                              |";
	cout << "\n| 6.  Change password                                             |";
	cout << "\n| 7.  Save to file                                                |";
	cout << "\n| 0.  Log out                                                     |";
	cout << "\n|_________________________________________________________________|";
	cout << "\n\n Please select an option: ";
}

void displaymenu_prof()
{
	cout << "\n _________________________________________________________________ ";
	cout << "\n|                     UNIVERSITY OF TECHNOLOGY                    |";
	cout << "\n|                            PROFESSOR                            |";
	cout << "\n|_________________________________________________________________|";
	cout << "\n|                                                                 |";
	cout << "\n| 1.  Add course                                                  |";
	cout << "\n| 2.  Summarize students's scores                                 |";
	cout << "\n| 3.  Modify student's score                                      |";
	cout << "\n| 4.  Change password                                             |";
	cout << "\n| 0.  Log out                                                     |";
	cout << "\n|_________________________________________________________________|";
	cout << "\n\n Please select an option: ";
}

void displaymenu_student()
{
	cout << "\n _________________________________________________________________ ";
	cout << "\n|                     UNIVERSITY OF TECHNOLOGY                    |";
	cout << "\n|                            STUDENT                              |";
	cout << "\n|_________________________________________________________________|";
	cout << "\n|                                                                 |";
	cout << "\n| 1.  Register course                                             |";
	cout << "\n| 2.  View GPA                                                    |";
	cout << "\n| 3.  View registered courses                                     |";
	cout << "\n| 4.  View courses in the semester                                |";
	cout << "\n| 5.  Find available courses by name                              |";
	cout << "\n| 0.  Log out                                                     |";
	cout << "\n|_________________________________________________________________|";
	cout << "\n\n Please select an option: ";
}

void displaymenu_find_user()
{
	cout << "\n---FIND USER---\n\n";
	cout << "1. Search user by username" << endl;
	cout << "2. Search professor" << endl;
	cout << "3. Search student" << endl;
	cout << "0. Turn back..." << endl;
}

void displaymenu_find_professor()
{
	cout << "\n---FIND PROFESSOR---\n\n";
	cout << "1. Search by ID" << endl;
	cout << "2. Search by name" << endl;
	cout << "3. Search by address" << endl;
	cout << "0. Turn back..." << endl;
}

void displaymenu_find_student()
{
	cout << "\n---FIND STUDENT---\n\n";
	cout << "1. Search by ID" << endl;
	cout << "2. Search by name" << endl;
	cout << "3. Search by address" << endl;
	cout << "0. Turn back..." << endl;
}

//LOAD
void load_file_user(int &count_row, user &account)
{
	ifstream fin("user.csv");

	if (!fin.is_open())
	{
		cout << "ERROR" << endl;
	}

	count_row = 0;
	while (fin.good())
	{
		getline(fin, account.username_file[count_row], ',');
		getline(fin, account.password_file[count_row], ',');
		getline(fin, account.position_file[count_row], '\n');

		count_row++;
	}


	fin.close();
}

void load_file_professor(int &count_row, professor &prof)
{
	ifstream fin("teacher.csv");

	if (!fin.is_open())
	{
		cout << "ERROR" << endl;
	}

	count_row = 0;
	while (fin.good())
	{
		getline(fin, prof.professor_id_file[count_row], ',');
		getline(fin, prof.name_file[count_row], ',');
		getline(fin, prof.dob_file[count_row], ',');
		getline(fin, prof.phone_file[count_row], ',');
		getline(fin, prof.place_file[count_row], '\n');

		count_row++;
	}

	fin.close();
}

void load_file_student(int &count_row, student &stu)
{
	ifstream fin("student.csv");

	if (!fin.is_open())
	{
		cout << "ERROR" << endl;
	}

	count_row = 0;
	while (fin.good())
	{
		getline(fin, stu.student_id_file[count_row], ',');
		getline(fin, stu.name_file[count_row], ',');
		getline(fin, stu.dob_file[count_row], ',');
		getline(fin, stu.place_file[count_row], '\n');

		count_row++;
	}
}

void load_file_course(int &count_row, course &cour)
{
	ifstream fin("course.csv");

	if (!fin.is_open())
	{
		cout << "ERROR" << endl;
	}

	count_row = 0;
	while (fin.good())
	{
		getline(fin, cour.course_id_file[count_row], ',');
		getline(fin, cour.professor_id_file[count_row], ',');
		getline(fin, cour.course_name_file[count_row], ',');
		getline(fin, cour.credit_file[count_row], ',');
		getline(fin, cour.count_student_file[count_row], ',');
		getline(fin, cour.max_students_file[count_row], '\n');

		count_row++;
	}
}

void load_file_grade(int &count_row, grade &gra)
{
	ifstream fin("grade.csv");

	if (!fin.is_open())
	{
		cout << "ERROR" << endl;
	}

	count_row = 0;
	while (fin.good())
	{
		getline(fin, gra.course_id_file[count_row], ',');
		getline(fin, gra.student_id_file[count_row], ',');
		getline(fin, gra.professor_id_file[count_row], ',');
		getline(fin, gra.averaged_score_file[count_row], ',');
		getline(fin, gra.semester_file[count_row], ',');
		getline(fin, gra.score_modified_right_file[count_row], '\n');

		count_row++;
	}
}

//WRITE
void write_file_user(int count_row, user &account)
{
	ofstream fout("user.csv");

	if (!fout.is_open())
	{
		cout << "ERROR" << endl;
	}

	while (fout.good())
	{
		for (int i = 0; i < count_row - 1; i++)
		{
			fout 
				<< account.username_file[i] << "," 
				<< account.password_file[i] << "," 
				<< account.position_file[i] << "\n";
		}
		break;
	}


	fout.close();

	cout << "Saved to user.csv\n";
}

void write_file_professor(int count_row, professor &prof)
{
	ofstream fout("teacher.csv");

	if (!fout.is_open())
	{
		cout << "ERROR" << endl;
	}

	while (fout.good())
	{
		for (int i = 0; i < count_row - 1; i++)
		{
			fout
				<< prof.professor_id_file[i] << ','
				<< prof.name_file[i] << ','
				<< prof.dob_file[i] << ','
				<< prof.phone_file[i] << ','
				<< prof.place_file[i] << '\n';
		}

		break;
	}


	fout.close();
	cout << "Saved to teacher.csv\n";
}

void write_file_student(int count_row, student &stu)
{
	ofstream fout("student.csv");

	if (!fout.is_open())
	{
		cout << "ERROR" << endl;
	}

	while (fout.good())
	{
		for (int i = 0; i < count_row - 1; i++)
		{
			fout
				<< stu.student_id_file[i] << ','
				<< stu.name_file[i] << ','
				<< stu.dob_file[i] << ','
				<< stu.place_file[i] << '\n';
		}

		break;
	}


	fout.close();

	cout << "Saved to student.csv\n";
}

void write_file_course(int count_row, course &cour)
{
	ofstream fout("course.csv");

	if (!fout.is_open())
	{
		cout << "ERROR" << endl;
	}

	while (fout.good())
	{
		for (int i = 0; i < count_row - 1; i++)
		{
			fout
				<< cour.course_id_file[i] << ','
				<< cour.professor_id_file[i] << ','
				<< cour.course_name_file[i] << ','
				<< cour.credit_file[i] << ','
				<< cour.count_student_file[i] << ','
				<< cour. max_students_file[i] << "\n";
		}

		break;
	}


	fout.close();

	cout << "Saved to course.csv\n";
}

void write_file_grade(int count_row, grade &gra)
{
	ofstream fout("grade.csv");

	if (!fout.is_open())
	{
		cout << "ERROR" << endl;
	}

	while (fout.good())
	{
		for (int i = 0; i < count_row - 1; i++)
		{
			fout
				<< gra.course_id_file[i] << ','
				<< gra.student_id_file[i] << ','
				<< gra.professor_id_file[i] << ','
				<< gra.averaged_score_file[i] << ','
				<< gra.semester_file[i] << ','
				<< gra.score_modified_right_file[i] << '\n';
		}

		break;
	}


	fout.close();

	cout << "Saved to grade.csv\n";
}


bool check_comma(string str)
{
	if (str.find(",") != string::npos)
		return true;
	return false;
}

//ADMIN
void read_User(int count_row, user account)
{
	cout << "username\tpassword\tposition" << endl;
	for (int i = 0; i < count_row; i++)
	{
		cout << account.username_file[i] << "\t" << account.password_file[i] << "\t" << account.position_file[i] << "\t" << endl;
	}
}

void get_Position(int choose, user &account)
{
	if (choose == 1)
		account.position = "admin";
	if (choose == 2)
		account.position = "teacher";
	if (choose == 3)
		account.position = "student";
}

void set_Account(user &account)
{
	do
	{
		account.username = "";
		account.username = "";
		cout << "Username: ";
		getline(cin, account.username);

		cout << "Password: ";
		getline(cin, account.password);
		if (check_comma(account.username) == true || check_comma(account.password) == true)
		{
			cout << "\nDetect an symbol that is not allow to use\n";
			Sleep(2000);
			system("CLS");
		}

	} while (check_comma(account.username) == true || check_comma(account.password) == true);
}

bool check_Account_login(int count_row, user account)
{
	for (int i = 0; i < count_row; i++)
	{
		if (account.username == account.username_file[i] && account.position == account.position_file[i] && account.password == account.password_file[i])
			return true;
	}

	return false;
}

bool check_Username_equal(int count_row, user account)
{
	for (int i = 0; i < count_row; i++)
	{
		if (account.username == account.username_file[i])
			return false;
	}

	return true;
}

int find_pos_of_Username(int count_row, user account)
{
	for (int i = 0; i < count_row; i++)
	{
		if (account.username_file[i] == account.username)
			return i;
	}

	return -1;
}

int find_pos_of_Professor_by_name(int count_row, professor prof)
{
	for (int i = 0; i < count_row; i++)
	{
		if (prof.name_file[i] == prof.name)
			return i;
	}

	return -1;
}

int find_pos_of_Student_by_name(int count_row, student stu)
{
	for (int i = 0; i < count_row; i++)
	{
		if (stu.name_file[i] == stu.name)
			return i;
	}

	return -1;
}

int find_pos_of_Course_by_course_id(int count_row, course cour)
{
	for (int i = 0; i < count_row; i++)
	{
		if (cour.course_id_file[i] == cour.course_id)
			return i;
	}

	return -1;
}

int find_pos_of_Course_by_prof_id(int count_row, course cour)
{
	for (int i = 0; i < count_row; i++)
	{
		if (cour.professor_id_file[i] == cour.professor_id)
			return i;
	}

	return -1;
}

int find_pos_of_Grade(int count_row, grade gra)
{

	for (int i = 0; i < count_row; i++)
	{
		if (gra.student_id_file[i] == gra.student_id)
			return i;
	}

	return -1;
}


void change_Password(int count_row, user &account)
{
	string password_temp;
	int check = 0;
	int option;
	int pos = find_pos_of_Username(count_row, account);
	int count_pos = 0;

	do
	{
		system("CLS");
		cout << "\n---CHANGE PASSWORD---\n\n";

		cout << "Enter old password: ";
		cin.ignore();
		getline(cin, password_temp);

		if (password_temp == account.password)
		{
			cout << "\ncorrect\n\n";
			cout << "Enter new password: ";

			getline(cin, account.password);

			if (check_comma(account.password) == true)
			{
				cout << "\nDetect an symbol that is not allow to use\n";
				Sleep(1500);
				system("CLS");
				continue;
			}

			account.password_file[pos] = account.password;

			//Add to file
			write_file_user(count_row, account);

			cout << "\n\nPASSWORD HAS BEEN CHANGED";
			Sleep(2000);
			check = -1;
		}


		if (check == 0)
		{
			
			cout << "\nIncorrect password";
			cout << "\n\n1. Enter again" << endl;
			cout << "0. return back..." << endl;

			do
			{
				cout << "\nChoose an option: ";
				cin >> option;

				switch (option)
				{
				case 1:
					break;
				case 0:
					check = -1;
					break;
				}
			} while (!(option == 1 || option == 0));
		}

	} while (check_comma(account.password) == true || check == 0);
}

//FIND
void find_user_by_username(int count_row, user account)
{
	string SubStr;
	size_t found;
	int check_temp = 0;

	cout << "---FIND USER---\n\n";

	cout << "Enter a username keyword: ";
	cin.ignore();
	getline(cin, SubStr);

	cout << left;
	cout << setw(15) << "Username" << setw(15) << "Password" << setw(15) << "Position" << endl;
	for (int i = 0; i < count_row; i++)
	{
		found = account.username_file[i].find(SubStr);

		if (found != string::npos)
		{
			cout << setw(15) << account.username_file[i] << setw(15) << account.password_file[i] << setw(15) << account.position_file[i] << endl;
		}
	}

	do
	{
		cout << "Press [0] to turn back: ";
		cin >> check_temp;

	} while (check_temp != 0);

	system("CLS");
}

void find_professor_by_array(int count_row, professor prof, string arr[MAX_SIZE])
{
	string SubStr;
	size_t found;

	cin.ignore();
	getline(cin, SubStr);
	cout << "\n\n";
	cout << left;
	cout << setw(8) << "ID" << setw(25) << "Name" << setw(20) << "Date of Birth" << setw(15) << "Phone number" << setw(30) << "Address" << endl;
	for (int i = 0; i < count_row; i++)
	{
		found = arr[i].find(SubStr);

		if (found != string::npos)
		{
			cout << left;
			cout << setw(8) << prof.professor_id_file[i] << setw(25) << prof.name_file[i] << setw(20) << prof.dob_file[i] << setw(15) << prof.phone_file[i] << setw(30) << prof.place_file[i] << endl;
		}
	}
}

int find_professor(int count_row, professor prof)
{
	int check_temp = 0;
	int option;

		do
		{
			option = 0;
			displaymenu_find_professor();
			cout << "\nChoose an option: ";
			cin >> option;

			if (!(option == 1 || option == 2 || option == 3 || option == 0))
			{
				cout << "Input again\n";
				Sleep(2000);
				system("CLS");
			}

			switch (option)
			{
			case 1:
				system("CLS");
				cout << "Enter professor ID as keyword: ";
				find_professor_by_array(count_row, prof, prof.professor_id_file);
				break;

			case 2:
				system("CLS");
				cout << "Enter professor name as keyword: ";
				find_professor_by_array(count_row, prof, prof.name_file);
				break;

			case 3:
				system("CLS");
				cout << "Enter professor address as keyword: ";
				find_professor_by_array(count_row, prof, prof.place_file);
				break;

			case 0:
				system("CLS");
				return 0;
			}

			// TURN BACK TO MENU FIND PROFESSOR
			do
			{
				cout << "\n\nEnter [0] to turn back: ";
				cin >> check_temp;

			} while (check_temp != 0);
			option = -1;
			system("CLS");
		
		} while (!(option == 1 || option == 2 || option == 3 || option == 0));

	return 0;
}

void find_student_by_array(int count_row, student stu, string arr[MAX_SIZE])
{
	string SubStr;
	size_t found;

	cin.ignore();
	getline(cin, SubStr);
	cout << "\n\n";
	cout << left;
	cout << setw(10) << "ID" << setw(25) << "Name" << setw(20) << "Date of Birth" << setw(30) << "Address" << endl;
	for (int i = 0; i < count_row; i++)
	{
		found = arr[i].find(SubStr);
		if (found != string::npos) {
			cout << left;
			cout << setw(10) << stu.student_id_file[i] << setw(25) << stu.name_file[i] << setw(20) << stu.dob_file[i] << setw(30) << stu.place_file[i] << endl;
		}
	}
}

int find_student(int count_row, student stu)
{
	int check_temp = 0;
	int option;

	do
	{
		option = 0;
		displaymenu_find_student();
		cout << "\nChoose an option: ";
		cin >> option;

		if (!(option == 1 || option == 2 || option == 3 || option == 0))
		{
			cout << "Input again\n";
			Sleep(2000);
			system("CLS");
		}

		switch (option)
		{
		case 1:
			system("CLS");
			cout << "Enter student ID as keyword: ";
			find_student_by_array(count_row, stu, stu.student_id_file);
			break;

		case 2:
			system("CLS");
			cout << "Enter student name as keyword: ";
			find_student_by_array(count_row, stu, stu.name_file);
			break;

		case 3:
			system("CLS");
			cout << "Enter professor address as keyword: ";
			find_student_by_array(count_row, stu, stu.place_file);
			break;

		case 0:
			system("CLS");
			return 0;
		}

		// TURN BACK TO MENU FIND STUDENT
		do
		{
			cout << "Enter [0] to turn back: ";
			cin >> check_temp;

		} while (check_temp != 0);
		
		option = -1;
		system("CLS");

	} while (!(option == 1 || option == 2 || option == 3 || option == 0));

	return 0;
}

void switch_find_user(int count_row[COUNT_SIZE], user account, professor prof, student stu)
{
	int option = 0;

	do
	{
		displaymenu_find_user();
		
		cout << "\nChoose an option: ";
		cin >> option;

		switch (option)
		{
		case 1:
			system("CLS");
			find_user_by_username(count_row[0], account);
			option = -1;
			break;

		case 2:
			system("CLS");
			find_professor(count_row[1], prof);
			option = -1;
			break;
			
		case 3:
			system("CLS");
			find_student(count_row[2], stu);
			option = -1;
			break;

		case 0:
			option = 0;
			break;

		}
	} while (!(option == 1 || option == 2 || option == 3 || option == 0));
}


bool check_valid_date(int day, int month, int year)
{
	int daysofmonth;

	if (month >= 1 && month <= 12)
	{
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			daysofmonth = 31;
			break;

		case 4:
		case 6:
		case 9:
		case 11:
			daysofmonth = 30;
			break;

		case 2:
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
				daysofmonth = 29;
			else
				daysofmonth = 28;
			break;
		}

		if (day <= 0 || day > daysofmonth)
			return false;

		else
			return true;
	}

	return false;
}

void add_professor(int count_row[COUNT_SIZE], user &account, professor &prof)
{
	int day = 0;
	int month = 0;
	int year = 0;

	bool x;
	bool date;

	// add to input variables
	do
	{
		cout << "---ADD PROFESSOR---\n\n";

		cout << "Enter username: ";
		cin >> account.username;

		x = check_Username_equal(count_row[0], account);
		if (x == false)
		{
			cout << "Username has already been taken. Input again";
			Sleep(2000);
			system("CLS");
		}

		if (check_comma(account.username) == true)
		{
			cout << "\nDetect an symbol that is not allow to use\n";
			Sleep(1500);
			system("CLS");
		}

	} while (x == false || check_comma(account.username) == true);

	system("CLS");

	//True -> add info
	do
	{
		cout << "---ADD PROFESSOR---\n\n";

		cout << "Name: ";
		cin.ignore();
		getline(cin, prof.name);
		cout << "Date of Birth: " << endl;
		cout << "\t- Day: ";
		cin >> day;
		cout << "\t- Month: ";
		cin >> month;
		cout << "\t- Year: ";
		cin >> year;
		cin.ignore();
		cout << "Phone number: ";
		getline(cin, prof.phone);
		cout << "Address(use a slash - to seperate region, cannot use comma , ): ";
		getline(cin, prof.place);
		date = check_valid_date(day, month, year);

		if (date == false || check_comma(account.username) == true || check_comma(prof.name) == true || check_comma(prof.phone) == true || check_comma(prof.place) == true)
		{
			cout << "Invalid date or detect a symbol that is not allow to use. Input again" << endl;
			Sleep(2000);
			system("CLS");
		}

	} while (date == false || check_comma(prof.name) == true || check_comma(prof.phone) == true || check_comma(prof.place) == true);

	//input to array
	account.username_file[count_row[0]] = account.username;
	account.password_file[count_row[0]] = account.username;
	account.position_file[count_row[0]] = "teacher";

	prof.professor_id = account.username;
	prof.professor_id_file[count_row[1]] = prof.professor_id;
	prof.name_file[count_row[1]] = prof.name;
	prof.dob = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
	prof.dob_file[count_row[1]] = prof.dob;
	prof.phone_file[count_row[1]] = prof.phone;
	prof.place_file[count_row[1]] = prof.place;


	//Add to file user.csv
	ofstream fout_user("user.csv", ios::app);

	if (!fout_user.is_open())
	{
		cout << "ERROR" << endl;
	}

	while (fout_user.good())
	{
		fout_user
				<< account.username_file[count_row[0]] << ','
				<< account.password_file[count_row[0]] << ',' 
				<< account.position_file[count_row[0]] << '\n';
		break;
	}
	fout_user.close();

	//Add to file professor.csv
	ofstream fout_professor("teacher.csv", ios::app);

	if (!fout_professor.is_open())
	{
		cout << "ERROR" << endl;
	}

	while (fout_professor.good())
	{
		fout_professor 
					<< prof.professor_id_file[count_row[1]] << ','
					<< prof.name_file[count_row[1]] << ','
					<< prof.dob_file[count_row[1]] << ',' 
					<< prof.phone_file[count_row[1]] << ',' 
					<< prof.place_file[count_row[1]] << '\n';
		break;
	}
	fout_professor.close();
	cout << "Saved to teacher.csv\n";

	count_row[0]++;
	count_row[1]++;

	cout << "\n\nA MEMBER HAS BEEN ADDED";
	Sleep(3000);
}

void add_student(int count_row[COUNT_SIZE], user &account, student &stu)
{
	int day = 0;
	int month = 0;
	int year = 0;

	bool x;
	bool date;

	// add to input variables
	do
	{
		cout << "---ADD STUDENT---\n\n";

		cout << "Enter username: ";
		cin >> account.username;

		x = check_Username_equal(count_row[0], account);
		if (x == false)
		{
			cout << "Username has already been taken. Input again";
			Sleep(2000);
			system("CLS");
		}

	} while (x == false);

	system("CLS");

	//True -> add info
	do
	{
		cout << "---ADD STUDENT---\n\n";

		cout << "Name: ";
		cin.ignore();
		getline(cin, stu.name);
		cout << "Date of Birth: " << endl;
		cout << "\t- Day: ";
		cin >> day;
		cout << "\t- Month: ";
		cin >> month;
		cout << "\t- Year: ";
		cin >> year;
		cin.ignore();
		cout << "Address(use a slash - to seperate region, cannot use comma ,): ";
		getline(cin, stu.place);
		date = check_valid_date(day, month, year);

		if (date == false || check_comma(account.username) == true || check_comma(stu.name) == true || check_comma(stu.place) == true)
		{
			cout << "Invalid date or detect a symbol that is not allow to use. Input again" << endl;
			Sleep(2000);
			system("CLS");
		}

	} while (date == false || check_comma(account.username) == true || check_comma(stu.name) == true || check_comma(stu.place) == true);

	//input to array
	account.username_file[count_row[0]] = account.username;
	account.password_file[count_row[0]] = account.username;
	account.position_file[count_row[0]] = "student";

	stu.student_id = account.username;
	stu.student_id_file[count_row[2]] = stu.student_id;
	stu.name_file[count_row[2]] = stu.name;
	stu.dob = to_string(year) + "/" + to_string(month) + "/" + to_string(day);
	stu.dob_file[count_row[2]] = stu.dob;
	stu.place_file[count_row[2]] = stu.place;


	//Add to file user.csv
	ofstream fout_user("user.csv", ios::app);

	if (!fout_user.is_open())
	{
		cout << "ERROR" << endl;
	}

	while (fout_user.good())
	{
		fout_user
			<< account.username_file[count_row[0]] << ','
			<< account.password_file[count_row[0]] << ','
			<< account.position_file[count_row[0]] << '\n';
		break;
	}
	fout_user.close();

	//Add to file student.csv
	ofstream fout_student("student.csv", ios::app);

	if (!fout_student.is_open())
	{
		cout << "ERROR" << endl;
	}

	while (fout_student.good())
	{
		fout_student
			<< stu.student_id_file[count_row[2]] << ','
			<< stu.name_file[count_row[2]] << ','
			<< stu.dob_file[count_row[2]] << ','
			<< stu.place_file[count_row[2]] << '\n';
		break;
	}
	fout_student.close();

	count_row[0]++;
	count_row[2]++;

	cout << "\n\nA MEMBER HAS BEEN ADDED";
	Sleep(3000);
}

void delete_professor(int count_row[COUNT_SIZE], user &account, professor &prof, course &cour)
{
	int check_found = 0;
	int pos_user = -1;
	int pos_professor = -1;
	int pos_course_prof = -1;
	int option = 0;

	do
	{
		cout << "---DELETE PROFESSOR---\n\n";

		cout << "Enter name of the professor: ";
		cin.ignore();
		getline(cin, prof.name);

		pos_professor = find_pos_of_Professor_by_name(count_row[1], prof);

		account.username = prof.professor_id_file[pos_professor];
		cour.professor_id = account.username;

		pos_course_prof = find_pos_of_Course_by_prof_id(count_row[3], cour);
		pos_user = find_pos_of_Username(count_row[0], account);

		if (pos_professor == -1)
		{
			cout << "Incorrect name or professor does not exist" << endl;
			
			do
			{
				cout << "1. Enter again" << endl;
				cout << "0. Return back..." << endl;

				cout << "\nChoose an option: ";
				cin >> option;

				switch (option)
				{
				case 1:
					system("CLS");
					option = 0;
					check_found = -1;
					break;

				case 0:
					system("CLS");
					check_found = 0;
					break;
				}
			} while (!(option == 1 || option == 0));
		}

		else
		{
			cout << "\n\nDeleted professor by name: " << prof.name << endl;

			//Delete array
			if (pos_professor != -1)
			{
				for (int i = pos_user; i < count_row[0]; i++)
				{
					account.username_file[i] = account.username_file[i + 1];
					account.password_file[i] = account.password_file[i + 1];
					account.position_file[i] = account.position_file[i + 1];
				}
				count_row[0]--;
			}

			while (pos_course_prof != -1)
			{
				cour.professor_id_file[pos_course_prof] = "";
				pos_course_prof = find_pos_of_Course_by_prof_id(count_row[3], cour);
			}

			for (int i = pos_professor; i < count_row[1]; i++)
			{
				prof.professor_id_file[i] = prof.professor_id_file[i + 1];
				prof.dob_file[i] = prof.dob_file[i + 1];
				prof.name_file[i] = prof.name_file[i + 1];
				prof.phone_file[i] = prof.phone_file[i + 1];
				prof.place_file[i] = prof.place_file[i + 1];
			}

			count_row[1]--;

			//Write to file
			write_file_user(count_row[0], account);
			write_file_professor(count_row[1], prof);
			write_file_course(count_row[3], cour);

			cout << "\nMEMBER HAS BEEN DELETED\n";
			Sleep(3000);
			check_found = 0;
			account.username = "admin";
		}
		
	} while (check_found != 0);

	
}

void delete_student(int count_row[COUNT_SIZE], user &account, student &stu, grade &gra)
{
	int check_found = 0;
	int pos_user = -1;
	int pos_student = -1;
	int pos_grade_stu = -1;
	int option = 0;

	do
	{
		cout << "---DELETE STUDENT---\n\n";

		cout << "Enter name of student: ";
		cin.ignore();
		getline(cin, stu.name);

		pos_student = find_pos_of_Student_by_name(count_row[2], stu);

		account.username = stu.student_id_file[pos_student];
		stu.student_id = account.username;

		pos_grade_stu = find_pos_of_Grade(count_row[4], gra);
		pos_user = find_pos_of_Username(count_row[0], account);

		if (pos_student == -1)
		{
			cout << "Incorrect name or student does not exist\n" << endl;

			do
			{
				cout << "1. Enter again" << endl;
				cout << "2. Return back...\n" << endl;

				cout << "\nChoose an option: ";
				cin >> option;

				switch (option)
				{
				case 1:
					system("CLS");
					option = 0;
					break;

				case 0:
					system("CLS");
					check_found = 0;
					break;
				}
			} while (!(option == 1 || option == 0));
		}

		else
		{
			cout << "\n\nDeleted student by name: " << stu.name << endl;

			//Delete array
			if (pos_user != -1)
			{
				for (int i = pos_user; i < count_row[0]; i++)
				{
					account.username_file[i] = account.username_file[i + 1];
					account.password_file[i] = account.password_file[i + 1];
					account.position_file[i] = account.position_file[i + 1];
				}

				count_row[0]--;
			}

			while (pos_grade_stu != -1)
			{
				for (int i = 0; i < count_row[4]; i++)
				{
					gra.course_id_file[i] = gra.course_id_file[i + 1];
					gra.student_id_file[i] = gra.student_id_file[i + 1];
					gra.professor_id_file[i] = gra.professor_id_file[i + 1];
					gra.averaged_score_file[i] = gra.averaged_score_file[i + 1];
					gra.semester_file[i] = gra.semester_file[i + 1];
					gra.score_modified_right_file[i] = gra.score_modified_right_file[i + 1];
				}

				pos_grade_stu = find_pos_of_Grade(count_row[4], gra);
				count_row[4]--;
			}

			for (int i = pos_student; i < count_row[2]; i++)
			{
				stu.student_id_file[i] = stu.student_id_file[i + 1];
				stu.name_file[i] = stu.name_file[i + 1];
				stu.dob_file[i] = stu.dob_file[i + 1];
				stu.place_file[i] = stu.place_file[i + 1];
			}

			count_row[2]--;

			//Write to file
			write_file_user(count_row[0], account);
			write_file_student(count_row[2], stu);

			cout << "\nMEMBER HAS BEEN DELETED\n";
			Sleep(3000);
			check_found = 0;
			account.username = "admin";
		}

	} while (check_found != 0);


}

void admin_main(int count_row[COUNT_SIZE], user &account, professor &prof, student &stu, course &cour, grade &gra)
{
	int option;
	int check_break;

	do
	{
		system("CLS");
		option = 0;
		check_break = 0;
		displaymenu_admin();
		cout << "\n\nChoose an option: ";
		cin >> option;

		if (!(option == 1 || option == 2 || option == 3 || option == 4 || option == 5 || option == 6 || option == 0))
		{
			cout << "\nInput again\n";
			Sleep(1000);
			system("CLS");
			continue; //skip switch, we dont need switch when input wrong
		}

		switch (option)
		{
		case 1:
			system("CLS");
			switch_find_user(count_row, account, prof, stu);
			option = -1;
			break;

		case 2:
			system("CLS");
			add_professor(count_row, account, prof);
			option = -1;
			break;

		case 3:
			system("CLS");
			add_student(count_row, account, stu);
			option = -1;
			break;

		case 4:
			system("CLS");
			delete_professor(count_row, account, prof, cour);
			option = -1;
			break;
			
		case 5:
			system("CLS");
			delete_student(count_row, account, stu, gra);
			option = -1;
			break;

		case 6:
			system("CLS");
			change_Password(count_row[0],account);
			option = -1;
			break;

		case 0:
			account.username = "";
			system("CLS");

		}
	} while (!(option == 1 || option == 2 || option == 3 || option == 4 || option == 5 || option == 6 || option == 0));

	system("CLS");

}

//PROFFESOR

void Add_Course(int count_row[COUNT_SIZE], user &account, course &cour, grade &gra) {

	bool exit_add_course = false;
	while (exit_add_course == false) {
		// Adding course
		string option;
		string choice;
		size_t found;
		// SEARCH AND VIEW COURSE SO THE PROFESSOR CAN SELECT //
		bool exit_confirm_add_course = false;
		while (exit_confirm_add_course == false) {
			system("cls");
			cout << "\n _____________________________________________________________________________________________________ ";
			cout << "\n|                                             ADD A COURSE                                            |";
			cout << "\n|_____________________________________________________________________________________________________|";
			cout << endl << endl;
			cout << "Enter to search for course: ";
			cin.ignore();
			getline(cin, option);
			if (option.size() == 0) {
				cout << "Invalid course!" << endl;
				Sleep(1000);
				break;
			}
			cout << "\n\n";
			cout << left;
			cout << setw(8) << "ID" << setw(10) << "Professor" << setw(60) << "Course" << setw(10) << "Credit" << setw(10) << "Capacity" << endl;
			for (int i = 0; i < count_row[3]; i++) {
				found = cour.course_name_file[i].find(option);
				if (found != string::npos) {
					cout << left;
					cout << setw(8) << cour.course_id_file[i] << setw(10) << cour.professor_id_file[i] << setw(60) << cour.course_name_file[i] << setw(10) << cour.credit_file[i] << setw(10) << cour.max_students_file[i] << endl;
				}
			}
			// Option to select again or choose a course 
			int search;
			cout << "\nPlease select a course or return to search again" << endl;
			cout << "1.  Choose course" << endl;
			cout << "2.  Search again" << endl;
			cout << "0.  Return to menu" << endl;
			cout << "Select option: ";
			cin >> search;
			size_t selected;
			switch (search) {
			case 2:
				exit_confirm_add_course = true;
				exit_add_course = false;
				break;
			case 1:
				cout << "\nEnter course's ID to select: ";
				cin.ignore();
				getline(cin, cour.course_id);

				// Search course by ID that they've seen:
				system("CLS");
				cout << "\n _____________________________________________________________________________________________________ ";
				cout << "\n|                                           SELECTED COURSE                                           |";
				cout << "\n|_____________________________________________________________________________________________________|";
				cout << "\n\n";
				cout << left;
				cout << setw(8) << "ID" << setw(15) << "Professor" << setw(60) << "Course" << setw(10) << "Credit" << setw(10) << "Capacity" << endl;
				for (int i = 0; i < count_row[3]; i++) {
					selected = cour.course_id_file[i].find(cour.course_id);
					if (selected != string::npos) {

						cout << left;
						cout << setw(8) << cour.course_id_file[i] << setw(15) << cour.professor_id_file[i] << setw(60) << cour.course_name_file[i] << setw(10) << cour.credit_file[i] << setw(10) << cour.max_students_file[i] << endl;
						break;
					}
				}
				// Select an option to confirm adding or adjust the course

				cout << endl;
				cout << "Please check again the course you have selected and confirm" << endl;
				cout << "1.  Confirm adding the course" << endl;
				cout << "2.  Search another course" << endl;
				cout << "0.  Return to menu" << endl;
				cout << "\nSelect option: ";

				getline(cin, choice);
				if (choice == "1") {
					for (int i = 0; i < count_row[3]; i++)
					{
						selected = cour.course_id_file[i].find(cour.course_id);
						if (selected != string::npos)
						{
							cour.professor_id_file[i] = account.username;
							break;
						}
					}

					gra.professor_id_file[count_row[4]] = account.username;
					gra.course_id_file[count_row[4]] = cour.course_id;

					//add to file 
					write_file_course(count_row[3], cour);
					
					ofstream fout_grade("grade.csv", ios::app);

					if (!fout_grade.is_open())
					{
						cout << "ERROR" << endl;
					}

					while (fout_grade.good())
					{
						fout_grade
							<< gra.course_id_file[count_row[4]] << ','
							<< gra.student_id_file[count_row[4]] << ','
							<< gra.professor_id_file[count_row[4]] << ','
							<< gra.averaged_score_file[count_row[4]] << ','
							<< gra.semester_file[count_row[4]] << ','
							<< gra.score_modified_right_file[count_row[4]] << '\n';
						break;
					}
					fout_grade.close();

					count_row[4]++;

					string choice_continue;
					// Select option to continue or return
					system("cls");
					cout << "Course has been added, please select an option " << endl;
					cout << "1.  Add more courses" << endl;
					cout << "0.  Return to previous menu" << endl;
					cout << "Select option: ";

					getline(cin, choice_continue);
					if (choice_continue == "1") {
						exit_confirm_add_course = true;
						exit_add_course = false;
						break;

					}
					else if (choice_continue == "0") {
						exit_add_course = true; // Get out of confirm loop and add course loop -> out of this function
						exit_confirm_add_course = true;
						break;
					}
					else {
						cout << "Invalid option. Press enter to continue." << endl;
						system("cls");
					}
				}


				if (choice == "2") {
					exit_confirm_add_course = true;
					exit_add_course = false;
					break;
				}

				if (choice == "0") {
					exit_confirm_add_course = true;
					exit_add_course = true;
					break;
				}

			case 0:
				exit_confirm_add_course = true;
				exit_add_course = true;
				break;
			}
		}
	}
}

void professor_main(int count_row[COUNT_SIZE], user &account, professor &prof, student &stu, course &cour, grade &gra) {
	int function;
	int check = 0;
	do {
		system("CLS");
		displaymenu_prof();

		cin >> function;
		switch (function)
		{
		case 1: // Open course
			Add_Course(count_row, account, cour, gra);
			system("cls");
			displaymenu_prof();
			professor_main(count_row, account, prof, stu, cour, gra);
			break;
			/*
			case 2: // Summarize students's scores in a course
			Sum_Score();
			system("cls");
			print_menu_prof();
			select_menu_prof(prof);
			wrong_choice = false;
			break;

			case 3: // Modify student's score in opened course
			Modify_Score();
			system("cls");
			print_menu_prof();
			select_menu_prof(prof);
			wrong_choice = false;
			break; */

		case 4:
			change_Password(count_row[0], account);
			break;

		case 0: // Log out
			system("cls");
			check = -1;
			break;

		default:
			system("cls");
			displaymenu_prof();
			cout << "Please select again!" << endl;
		}
	} while (!(function == 1 || function == 2 || function == 3 || function == 4 || function == 0 || check == 0));
}

//STUDENT

float compute_GPA_1_sem(int count_row, grade gra, string sem)
{
	float sum = 0;
	int count = 0;

	for (int i = 0; i < count_row; i++)
	{
		if (gra.student_id_file[i] == gra.student_id && gra.semester_file[i] == sem && stof(gra.averaged_score_file[i]) != -1)
		{
			sum = sum + stof(gra.averaged_score_file[i]);
			count++;
		}
	}

	if (count == 0)
	{
		return -1;
	}
	return sum / (float)count;

}

float compute_averaged_GPA(int count_row, grade gra, string sem[SEM_SIZE])
{
	int count = 0;
	float x;
	float sum = 0;

	for (int i = 0; i < SEM_SIZE; i++)
	{
		x = compute_GPA_1_sem(count_row, gra, sem[i]);
		if (x != -1)
		{
			sum = sum + x;
			count++;
		}
	}

	if (count == 0)
		return -1;

	return sum / (float)count;
}

void view_GPA(int count_row, grade gra, string sem[SEM_SIZE])
{
	int option = 0;
	float average_GPA = compute_averaged_GPA(count_row, gra, sem);

	cout << "---VIEW GPA---\n\n";

	//print
	cout << left;
	cout << setw(10) << "ID" << setw(10) << "GPA" << setw(8) << "Semester" << endl;

	for (int i = 0; i < SEM_SIZE; i++)
		cout << setw(10) << gra.student_id << setw(10) << compute_GPA_1_sem(count_row, gra, sem[i]) << setw(8) << sem[i] << endl;
	

	cout << "\nAVERAGE GPA: " << average_GPA << endl;

	do
	{
		cout << "\n\n0. Return back..." << endl;
		cout << "\nChoose an option: ";
		cin >> option;

	} while (!(option == 0));
}

void view_registered_course(int count_row[COUNT_SIZE], course cour, grade gra)
{
	int option = 0;
	int pos_course_id = -1;

	cout << left;
	cout << setw(8) << "ID" << setw(10) << "Professor" << setw(60) << "Course" << setw(10) << "Credit" << setw(10) << "Capacity" << endl;

	for (int i = 0; i < count_row[4]; i++)
	{
		if (gra.student_id == gra.student_id_file[i])
		{
			cour.course_id = gra.course_id_file[i];
			pos_course_id = find_pos_of_Course_by_course_id(count_row[3], cour);

			if (pos_course_id != -1)
			{
				cout << left;
				cout << setw(8) << cour.course_id_file[pos_course_id] << setw(10) << cour.professor_id_file[pos_course_id] << setw(60) << cour.course_name_file[pos_course_id] << setw(10) << cour.credit_file[pos_course_id] << setw(10) << cour.max_students_file[pos_course_id] << endl;
			}
		}
	}

	cout << "\n\n";
	cout << "0. Turn back... ";

	do
	{
		cout << "\n\nChoose an option: ";
		cin >> option;

	} while (option != 0);
	
}

void view_courses_in_sem(int count_row[COUNT_SIZE], course cour)
{
	int option = 0;

	cout << left;
	cout << setw(8) << "ID" << setw(10) << "Professor" << setw(60) << "Course" << setw(10) << "Credit" << setw(10) << "Capacity" << endl;

	for (int i = 0; i < count_row[3]; i++)
	{
		if (cour.professor_id_file[i] != "")
		{
			cout << left;
			cout << setw(8) << cour.course_id_file[i] << setw(10) << cour.professor_id_file[i] << setw(60) << cour.course_name_file[i] << setw(10) << cour.credit_file[i] << setw(10) << cour.max_students_file[i] << endl;
		}	
	}

	cout << "\n\n";
	cout << "0. Turn back... ";

	do
	{
		cout << "\n\nChoose an option: ";
		cin >> option;
	} while (option != 0);
}

void student_main(int count_row[COUNT_SIZE], user &account, student &stu, course &cour, grade &gra, string sem[SEM_SIZE])
{
	int option;
	int check_break;

	do
	{
		system("CLS");
		option = 0;
		check_break = 0;
		displaymenu_student();
	
		cin >> option;

		if (!(option == 1 || option == 2 || option == 3 || option == 4 || option == 5 || option == 0))
		{
			cout << "\nInput again\n";
			Sleep(1000);
			system("CLS");
			continue; //skip switch, we dont need switch when input wrong
		}

		switch (option)
		{

		case 2:
			system("CLS");
			view_GPA(count_row[4], gra, sem);
			option = -1;
			break;

		case 3:
			system("CLS");
			view_registered_course(count_row, cour, gra);
			option = -1;
			break;

		case 4:
			system("CLS");
			view_courses_in_sem(count_row, cour);
			option = -1;
			break;

		case 0:
			account.username = "";
			system("CLS");

		}
	} while (!(option == 1 || option == 2 || option == 3 || option == 4 || option == 5 || option == 0));

	system("CLS");
}

void main()
{
	user account;
	professor prof;
	student stu;
	course cour;
	grade gra;

	string sem[SEM_SIZE] = { "161", "171", "181" };

	int count_row[COUNT_SIZE];

	int check_login = 0;
	int option = 0;

	load_file_user(count_row[0], account);
	load_file_professor(count_row[1], prof);
	load_file_student(count_row[2], stu);
	load_file_course(count_row[3], cour);
	load_file_grade(count_row[4], gra);

	do
	{
		//LOGIN

		do
		{
			system("CLS");
			displaymenu_login();
			cout << "\nChoose an option: ";
			cin >> option;

			if (!(option == 1 || option == 2 || option == 3 || option == 0))
			{
				cout << "\nInput again\n";
				Sleep(1000);
				system("CLS");
			}
		} while (!(option == 1 || option == 2 || option == 3 || option == 0));

		if (option == 0)
		{
			system("CLS");
			cout << "Exiting...";
			Sleep(2000);

			exit(0);
		}

		system("CLS");

		bool x;
		int check_break = 0;
		int option_temp = 0;
		do
		{
			check_break = 0;
			check_login = 0;
			cin.ignore();
			get_Position(option, account);
			set_Account(account);
			x = check_Account_login(count_row[0], account);

			if (x == true)
			{
				cout << "\n\nACCESS GRANTED\n";
				Sleep(2000);
				system("CLS");
					
				//IMPLEMENT-----------------------------------
				switch (option)
				{
				case 1:
					admin_main(count_row, account, prof, stu, cour, gra); //Only out function when enter 0
					check_break = 0;
					check_login = -1;
					break;

				case 2:
					prof.professor_id = account.username;
					cour.professor_id = account.username;
					gra.professor_id = account.username;
					professor_main(count_row, account, prof, stu, cour, gra);
					check_break = 0;
					check_login = -1;
					break;

				case 3:
					stu.student_id = account.username;
					gra.student_id = account.username;
					student_main(count_row, account, stu, cour, gra, sem);
					check_break = 0;
					check_login = -1;
					break;

				}

			}

			else
			{
				cout << "\n\nINCORRECT UNSERNAME OR PASSWORD\n\n";
				cout << "1. Login again" << endl;
				cout << "0. Return back..." << endl;

				do {
					cout << "\nChoose an option: ";
					cin >> option_temp;

				} while (!(option_temp == 1 || option_temp == 0));

				if (option_temp == 1)
				{
					system("CLS");
					check_break = -1;
				}

				else
				{
					system("CLS");
					check_break = 0;
					check_login = -1;
					break;
				}
			}
		} while (check_break != 0);

	} while (check_login != 0);

	system("PAUSE");

}