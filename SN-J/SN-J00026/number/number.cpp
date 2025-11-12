#include <bits/stdc++.h>
using namespace std;
string s;
int a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		if(s[j]>s[j-1])
		{
			a=s[j-1];
			s[j-1]=s[j];
			s[j]=a;
		}
	}
	cout<<s;
	return 0;
} 
