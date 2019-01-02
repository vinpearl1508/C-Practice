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

int main()
{
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