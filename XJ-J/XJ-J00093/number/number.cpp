#include<iostream>
using namespace std;
char a[10005];
int main()
{
	char s;
	cin>>s;
	for(int i=1;i<=10000000;i++)
	{
		if(s==('0'||'1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9'))
		{
			a[i]=s;
		}
		cout<<a[i];
	 } 

	return 0;
 } 
