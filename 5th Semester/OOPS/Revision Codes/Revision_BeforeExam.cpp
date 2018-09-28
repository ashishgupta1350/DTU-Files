#include<iostream>
// university - name, date_started, alumini, percent_placed etc
// branch - name <<< this is clashing ? no , students/peryear, average_result, topper etc
using namespace std;

class university{
	protected: // lets give the branch this data
	string univ_name,date_started,percent_placed;
public:
	class alumini{
	public:
		string name; int age; string company_placed;
		alumini(string name, int age=21,  string company_placed="none"): name(name), age(age), company_placed(company_placed)
		{}

	};
	class student{
		string name;
		int age;
	public:
		// some functions;
	};
	class branch{
	public:
		string name;
		int number_students;
		float average_package;
		string topper;
		student*student_array;
	};
};


int main()
{




}
