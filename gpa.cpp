/*
Project: GPA
Author: Jerred Shepherd
Date: 11-5-15
Course: COMP 150


***********
Description
***********
Calculates GPA from any number of courses with a given letter grade and hour value.

GPA is calculated in the following way
Grade * hours, add the result of this from each class and divide by total hours

Grade should be a one of the following letter: A, B, C, D, F
The respectively correspond to the following grades: 4, 3, 2, 1, 0

Number of courses should be a positive integer, hours should be an integer between 1-6.


***************
Sample Dialogue
***************

Number of courses? 3

For course 1:
Grade? A
Hours? 4

For course 2:
Grade? C
Hours? 2

For course 3:
Grade? B
Hours? 3

GPA is 3.22

*/

#include <iostream>
#include <iomanip>
using namespace std;

bool validateGrade(char grade) {

	switch (grade) {

	case 'A':
	case 'a':
	case 'B':
	case 'b':
	case 'C':
	case 'c':
	case 'D':
	case 'd':
	case 'F':
	case 'f':
		return true;

	default:
		return false;

	}

}

bool validateHours(int hours) {

	if (hours > 6 || hours < 1) {

		return false;

	}

	return true;

}

bool validateCourses(int courses) {

	if (courses < 1) {

		return false;

	}

	return true;

}

int getIntFromLetter(char grade) {

	switch (grade) {

	case 'A':
	case 'a':
		return 4;

	case 'B':
	case 'b':
		return 3;

	case 'C':
	case 'c':
		return 2;

	case 'D':
	case 'd':
		return 1;

	case 'F':
	case 'f':
		return 0;

	default:
		return 0;

	}

}

void main() {

	int courses, hours;
	char grade;
	float gpa, totalHours = 0, qualityPoints = 0;
	bool validHour = false, validGrade = false, validCourses = false;


	cout.precision(2);
	cout.setf(ios::fixed);

	while (!validCourses) {

		cout << "Number of Courses? ";
		cin >> courses;

		if (validateCourses(courses)) {

			validCourses = true;

		} else {

			cout << "\"" << courses << "\" is not a valid number of courses! Please enter a positive integer" << endl;

		}

	}

	cout << endl;

	for (int c = 0; c != courses; c++) {

		cout << "For course " << c + 1 << endl;

		while (!validGrade) {

			cout << "Grade? ";
			cin >> grade;

			if (validateGrade(grade)) {

				validGrade = true;

			} else {

				cout << "\"" << grade << "\" is not a valid grade! Please enter either A, B, C, D, or F" << endl;

			}

		}

		while (!validHour) {

			cout << "Hours? ";
			cin >> hours;

			if (validateHours(hours)) {

				validHour = true;

			} else {

				cout << "\"" << hours << "\" is not a valid number of hours! Please enter an integer from 1-6" << endl;

			}

		}

		totalHours += hours;
		qualityPoints += getIntFromLetter(grade) * hours;

		validGrade = false;
		validHour = false;

		cout << endl;

	}

	gpa = qualityPoints / totalHours;

	cout << "GPA is " << gpa << endl;

	system("pause");

}