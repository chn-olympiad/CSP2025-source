#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[256];
	int a[256];
	int a1,i=0,j=0;
	cin>>s;
	for(int i=0;i<256;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			s[i]=s[i]-'0';
			a[i]=s[i];
			j++;
		}
		
 	}
 	while(a[i]>a[i+1])
	{
		if(a[i]>a[i+1])
		{
			a1=a[i];
			a[i]=a[i+1];
			a[i+1]=a1;	
		}
		i++;
	}
	for(int i=0;i<j;i++)
	{
		cout<<a[i];
	}
	return 0;
}
