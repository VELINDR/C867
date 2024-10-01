#include <iostream>
#include "student.h"

//constructors? wip
Student::Student()
{}
Student::Student(string stuID, string firName, string lasName, string emailAdd, int Age, int timeToFinish[], DegreeProgram degree) {
	studentID = stuID;
	firstName = firName;
	lastName = lasName;
	emailAddress = emailAdd;
	age = Age;
	//daysToComplete = timeToFinish;
	for (int i = 0; i < 3; i++) {
		daysToComplete[i] = timeToFinish[i];
	}
	degreeProgram = degree;
}
//deconstuctors 
Student::~Student()
{}

//studentID
void Student::setstudentID(string stuID) {
	studentID = stuID;
}
string Student::getstudentID(){
	return studentID;
}

//first name
void Student::setfirstName(string firName) {
	firstName = firName;
}
string Student::getfirstName() {
	return firstName;
}

//last name
void Student::setlastName(string lasName) {
	lastName = lasName;
}
string Student::getlastName() {
	return lastName;
}

//email address
void Student::setemailAddress(string emailAdd) {
	emailAddress = emailAdd;
}
string Student::getemailAddress() {
	return emailAddress;
}

//age
void Student::setAge(int Age) {
	age = Age;
}
int Student::getAge() {
	return age;
}

//days to complete
void Student::setDaystoComplete(int timeToFinish[]) 
{
	for (int i = 0; i < 3; i++) 
	{
		daysToComplete[i] = timeToFinish[i];
	}
	//daysToComplete = timeToFinish
}
int* Student::getDaystoComplete() {
	return daysToComplete;
}

//degree program
void Student::setdegreeProgram(DegreeProgram degree) 
{
	this->degreeProgram = degree;
}
DegreeProgram Student::getdegreeProgram() 
{
	return this->degreeProgram;
}

//printer follow layout in e.c
void Student::print() {
	cout << studentID << '\t';
	cout << firstName << '\t';
	cout << lastName << '\t';
	cout << emailAddress << '\t';
	cout << age << '\t';
	cout << "{" << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "}" << '\t';
	cout << degreeProgramString[this->getdegreeProgram()] << "\n";

}
