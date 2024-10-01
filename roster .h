#pragma once
#include <iostream>
#include "student.h"

class Roster 
{

private:
	const static int classSize = 5;
	Student* classRosterArray[classSize] = {nullptr, nullptr, nullptr, nullptr, nullptr};
	int lastIndex = -1;
public:
	Roster();
	~Roster();
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void parse(string studentData);
	string getStudentID(int studentid);
	
};
