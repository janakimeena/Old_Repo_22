#include<iostream>
using namespace std;
#include<array>
int main()
{
	int i,n,min,max;
	array<int,5> a;
	cin>>n;
	cout<<"Enter elements";
	for(i=0;i<n;i++)
		cin>>a[i];
	min = a[0];
	max = a[0];
	for(auto it = a.begin();it!=a.end();it++)
	{
		if(*it<min)
			min = *it;
		if(*it>max)
			max = *it;

	}
	cout<<"Minimum is " <<min<<endl;
	cout<<"Max is "<<max<<endl;
}
