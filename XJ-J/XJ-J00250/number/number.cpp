#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	
	char s[10000000];
	int a[10]={0};
	cin>>s;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]>='1'&&s[i]<='0')a[s[i]-('1'-1)]++;
	}
	bool f=0;
	for(int i=9;i>=0;i--)
	{
		if(a[i]!=0)
		{
			if(i!=0)f=1;
			if(f!=0)
			{
				for(int j=0;j<a[i];j++)
				{
					cout<<i;
				}
			}
			
		}
	}
	if(f==0)cout<<0;
	return 0;
 } 
