#pragma once
using std::string;
using std::cout;
#include <string>
#include <iostream>
#include "degree.h"
class Student
{
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComplete[3];
	DegreeProgram degreeProgram;
	

public:
	//constructors
	Student();
	Student(string, string, string, string, int, int[], DegreeProgram);

	//deconstuctor
	~Student();

	// getters
	string getstudentID();
	string getfirstName();
	string getlastName();
	string getemailAddress();
	int getAge();
	int* getDaystoComplete();
	DegreeProgram getdegreeProgram();

	//setters
	void setstudentID(string);
	void setfirstName(string);
	void setlastName(string);
	void setemailAddress(string);
	void setAge(int);
	void setDaystoComplete(int[]);
	void setdegreeProgram(DegreeProgram degreeProgram);

	//print function
	void print();

};
