#include <iostream>
#include "roster.h"
int main()
{
	cout << "C867- Scripting & Programming: Applications";
	cout << "\n" << "Language: C++" << "\n";
	cout << "Student ID: 012311809" << "\n" << "Name: Indira lastname\n";

	const string studentData[] = {

"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",      
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Indira,lastname,schoolemail,18,20,20,20,SOFTWARE"

	};

	Roster classRoster;
	const static int classSize = 5;

	cout << "Displaying all Students \n";
	for (int i = 0; i < classSize; i++) 
	{ classRoster.parse(studentData[i]); }

	//given pseudocode for rest of the function + follow example for output
	classRoster.printAll();
	cout << "\n\n";

	cout << "Displaying Invalid Emails\n";
	classRoster.printInvalidEmails();
	cout << "\n\n";

	cout << "Average Days to Complete Courses\n";
	for (int i = 0; i < classSize; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.getStudentID(i));
	}
	cout << "\n\n";

	cout << "Displaying by Degree Program\n";
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << "\n\n";

	cout << "Removing Student A3\n";
	classRoster.remove("A3");
	cout << "\n\n";
	classRoster.printAll();
	cout << "\n\nRemoving Student A3 again";
	classRoster.remove("A3");

	cout << "Destructor called";
	return 0;
};
