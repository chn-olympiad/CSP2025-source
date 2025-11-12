#include <iostream>
#include <string>
using namespace std;
char a[1000005];
string b;
int main()
{
	cin>>b;
	for(int i=1;b[i];i++)
	{
		cin>>a[i];
	}
	for(int i=1;b[i];i++)
	{
		cout<<a[i];
	}
	
} 
