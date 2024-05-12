//
// Instructor: Sai-Keung Wong
// Email:	cswingo@cs.nycu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Hsinchu, Taiwan
// Computer Science
// Date: 2024/03/03
//
#include "mySystemApp.h"

using namespace std;

#define STUDENT_INFO "Name:Hsiu-I, Liao   ID:111652017"

void MY_SYSTEM_APP::showMyStudentInfo_2024( ) const
{
	cout << "*******************************" << endl;
    cout << "Date:2024/03/03" << endl;
	cout << "Student ID:111652017\t" << endl;
	cout << "Student Name:Hsiu-I, Liao\t" << endl;
	cout << "Student Email:abc0975773694@gmail.com\t" << endl;
	cout << "*******************************" << endl;
}

MY_SYSTEM_APP::MY_SYSTEM_APP( )
{
	//mSystemType = SYSTEM_TYPE_MONTE_CARLO_CIRCLE;
	mSystemType = SYSTEM_TYPE_GRAPH;
    string title = STUDENT_INFO;
        glutSetWindowTitle(title.data( ));
}

void MY_SYSTEM_APP::initApp( )
{
	mFlgShow_Grid = true;
}

void MY_SYSTEM_APP::update( )
{

}
// CODE: 2019/02/25. Do not delete this line.