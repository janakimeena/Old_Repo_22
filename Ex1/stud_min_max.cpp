#include<iostream>
using namespace std;
#include<array>
#include<string>
// Student class with name and marks as data members
class student
{
	string name;
	int marks;
	public:
	// Overloading extraction Operator
	friend istream& operator>>(istream&,student&);
	// Overloading insertion Operator
	friend ostream& operator<<(ostream&,student&);
	// Overloading less than operator to compare marks
	bool operator<(student&);
	// Overloading greater than operator to compare marks
	bool operator>(student&);
};
istream& operator>>(istream& in, student& s)
{
	cout<<"Enter name and marks";
	in>>s.name>>s.marks;
}
ostream& operator<<(ostream& out, student& s)
{
	out<<s.name<<"\t"<<s.marks<<endl;
}
bool student::operator<(student& s)
{
	return (marks<s.marks);
}
bool student::operator>(student& s)
{
	return(marks>s.marks);
}
int main()
{
	int i,n;
	student min,max;
	array<student,20> a;
	cin>>n;
	cout<<"Enter elements";
	for(i=0;i<n;i++)
		cin>>a[i];
	min = a[0];
	max = a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]<min)
			min = a[i];
		if(a[i]>max)
			max = a[i];

	}
	cout<<"Minimum is " <<min<<endl;
	cout<<"Max is "<<max<<endl;
}
