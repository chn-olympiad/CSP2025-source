#include <bits/stdc++.h>;
using namespace std;
string s;
int a[1000010]={},i=0,o=0;
int b(char c)
{
	if(c=='1')
	{
		return 1;
	}
	else if(c=='2')
	{
		return 2;
	}
	else if(c=='3')
	{
		return 3;
	}
	else if(c=='4')
	{
		return 4;
	}
	else if(c=='5')
	{
		return 5;
	}
	else if(c=='6')
	{
		return 6;
	}
	else if(c=='7')
	{
		return 7;
	}
	else if(c=='8')
	{
		return 8;
	}
	else if(c=='9')
	{
		return 9;
	}
	else if(c=='0')
	{
		return 0;
	}
	else
	{
		return -1; 
	}
	
}
int main()
{
	freopen("number.in","r",stdin);
	cin>>s;
	while(s[o]!=NULL)
	{
		if(b(s[o])!=-1)
		{
			a[i]=b(s[o]);
			i++;
		}
		o++;
	}
	int temp;
	for(int j=0;j<=i;j++)
	{
		for(int k=0;k<=i-2;k++)
		{
			if(a[k]<a[k+1])
			{
				temp=a[k];
				a[k]=a[k+1];
				a[k+1]=temp;
			}
		}
	}
	freopen("number.out","w",stdout);
	for(int k=0;k<=i-1;k++)
	{
		cout<<a[k];
	}
	return 0; 
}
