#include<iostream>
using namespace std;

int main()
{
	int t,a;
	cin>>t;
	while(t--!=0)
	{
		cin>>a;
		if(a==2010 || a==2015 || a==2016||a==2017||a==2019)
			cout<<"HOSTED"<<endl;
		else if(a>2010 && a<2019)
			cout<<"NOT HOSTED"<<endl;
	}
	return 0;
}