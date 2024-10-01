#include "roster.h"


//constructor
Roster::Roster()
{
	
}



//parse
void Roster::parse(string studentData)
{
	//enum 
/*going through each individual student;
 going through the first element of student string (the number part of ID)
 then assigning based off the predetermined degree type for the student*/

	DegreeProgram degreeProgram = SECURITY; //security will be the default value, there is no special set "default" value in my enum
	if (studentData.at(1) == '1') degreeProgram = SECURITY;
	else if (studentData.at(1) == '2') degreeProgram = NETWORK;
	else if (studentData.at(1) == '3') degreeProgram = SOFTWARE;
	else if (studentData.at(1) == '4') degreeProgram = SECURITY;
	else if (studentData.at(1) == '5') degreeProgram = SOFTWARE;

	int rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	//array with the days to complete
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int days1 = stoi(studentData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int days2 = stoi(studentData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int days3 = stoi(studentData.substr(lhs, rhs - lhs));

	add(studentID, firstName, lastName, emailAddress, age, days1, days2, days3, degreeProgram);

}

//add
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degreeProgram)
{
	int daysToComplete[] = { days1, days2, days3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysToComplete, degreeProgram);

}

//remove function
void Roster::remove(string studentID)
{
	bool boolean = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getstudentID() == studentID)
		{
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
			boolean = true;
			break;
		}
	}
	if (!boolean)
	{
		cout << "\n\nStudent: " << studentID << " not found \n";
	}
}
//print all function
void Roster::printAll()
{
	for (int i = 0; i <= lastIndex; i++ )
		if(classRosterArray[i] != nullptr)
	{
		{ classRosterArray[i]->print(); }
	}
}

//print average days 
void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i < classSize; i++)
	{
		if (classRosterArray[i]->getstudentID() == studentID)
		{
			cout << "Average number of days to complete course: ";
			int one = classRosterArray[i]->getDaystoComplete()[0];
			int two = classRosterArray[i]->getDaystoComplete()[1];
			int three = classRosterArray[i]->getDaystoComplete()[2];
			int average = (one + two + three) / 3;
			cout << average << " days for student #" << studentID << ".\n";
		}
	}

}

//print invalid emails
void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		string emailAddress = (classRosterArray[i]->getemailAddress());
		if (emailAddress.find(" ") != string::npos ||
			emailAddress.find('@') == string::npos ||
			emailAddress.find('.') == string::npos)
		{
			any = true;
			cout << emailAddress << " - is invalid \n";

		}
	}
		
}

//print by degree
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i]->getdegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
			cout << "\n";
		}
	}
	
}

string Roster::getStudentID(int studentid)
{
	return classRosterArray[studentid]->getstudentID();
}


//deconstructor 
Roster::~Roster()
{
	for (int i = 0; i < classSize; i++)
	{
		
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
		
	}
	cout << "\n\nComplete \n";
}
