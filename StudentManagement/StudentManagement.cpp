// StudentManagement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

typedef struct student {
	int id;
	string name;
	float score;
}TY_Student;

typedef vector<TY_Student> TY_StudentList;

int input_number_of_students(void);
void input_students_info(TY_StudentList* vList, int n);
bool check_valid_id(TY_StudentList* vList, int n);
void save_file(TY_StudentList* vList);
void load_file(TY_StudentList *vList);
void print_menu(void);
void display_list(TY_StudentList* vList);

int main()
{
	int select;
	static int numberOfStudents = 0;
	TY_StudentList vList;

	while (1)
	{
		print_menu();
		cin >> select;
		system("cls");
		switch (select)
		{
			case 1:
				
				numberOfStudents = input_number_of_students();
				input_students_info(&vList, numberOfStudents);
				system("cls");
				break;
			case 2:
				display_list(&vList);
				system("pause");
				system("cls");
				break;
			case 3:
				save_file(&vList);
				system("pause");
				system("cls");
				break;
			case 4:
				load_file(&vList);
				system("pause");
				system("cls");
				break;
			case 0:
				vList.clear();
				exit(1);
				break;
			default:
				break;
		}
	}
	system("pause");
    return 0;
}

int input_number_of_students(void) {
	cout << "Please input number of students: ";
	int n;
	cin >> n;
	while (!cin || n <= 0) {
		cout << "Please input a positive numeric data!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> n;
	}
	return n;
}

void input_students_info(TY_StudentList* vList, int n)
{
	TY_Student tmp;
	for (int i = 0; i<n; i++) {
		cout << "Please input information of student " << i + 1 << endl;
		cout << "Please input student id: ";
		cin >> tmp.id;
		while (check_valid_id(vList, tmp.id) == false) {
			cout << "Please input student id again!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> tmp.id;
		}
		cin.get();
		cout << "Student id: " << tmp.id << endl;

		cout << "Input student name: ";
		getline(cin, tmp.name);
		cout << "Student name: " << tmp.name << endl;

		cout << "Input student score: ";
		cin >> tmp.score;
		while (!cin || tmp.score<0 || tmp.score>10) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> tmp.score;
		}
		cout << "Student score: " << tmp.score << endl;

		vList->push_back(tmp);
	}
	return;
}

bool check_valid_id(TY_StudentList *vList, int n) {
	for (auto tmp : *vList) {
		if (n == tmp.id) {
			return false;
		}
	}
	return true;
}

void save_file(TY_StudentList *vList) {
	ofstream fo;
	fo.open("student_list.txt");
	if (fo.fail()) {
		cout << "File not found" << endl;
	}
	else {
		for (auto tmp : *vList) {
			fo << tmp.id << endl;
			fo << tmp.name << endl;
			fo << tmp.score << endl;
		}
		cout << "File write completed" << endl;
	}
	fo.close();
}

void load_file(TY_StudentList *vList) {
	ifstream fi;
	fi.open("student_list.txt");
	if (fi.fail()) {
		cout << "File load failed" << endl;
	}
	else {
		TY_Student tmp;
		string line;
		int id;
		string name;
		float score;

		while (!fi.eof()) {
			getline(fi, line);
			if (line=="")
			{
				break;
			}
			id = stoi(line);
			tmp.id = id;

			getline(fi, line);
			name = line;
			tmp.name = name;

			getline(fi, line);
			score = stof(line);
			tmp.score = score;
			
			vList->push_back(tmp);
		}
		cout << "File load successful" << endl;
	}
	fi.close();
}

void print_menu() {
	cout << "--------------------MENU--------------------" << endl;
	cout << "\t1. Input" << endl;
	cout << "\t2. Display" << endl;
	cout << "\t3. Save to file" << endl;
	cout << "\t4. Load from file" << endl;
	cout << "\t0. Exit" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Choose: ";
}

void display_list(TY_StudentList *vList) {
	if (vList->empty()) {
		cout << "NO RECORDS" << endl;
		return;
	}
		
	cout << setw(10) << left << "ID" << setw(20) << left << "FULL NAME" << setw(10) << left << "SCORE" << endl;
	for (auto tmp : *vList) {
		cout << setw(10) << left << tmp.id << setw(20) << left << tmp.name << setw(10) << left << tmp.score << endl;
	}
}