#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000];
int main()
{
	cin>>s;
	long long n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			a[0]++;
		}
		if(s[i]=='1')
		{
			a[1]++;
		}
		if(s[i]=='2')
		{
			a[2]++;
		}
		if(s[i]=='3')
		{
			a[3]++;
		}
		if(s[i]=='4')
		{
			a[4]++;
		}
		if(s[i]=='5')
		{
			a[5]++;
		}
		if(s[i]=='6')
		{
			a[6]++;
		}
		if(s[i]=='7')
		{
			a[7]++;
		}
		if(s[i]=='8')
		{
			a[8]++;
		}
		if(s[i]=='9')
		{
			a[9]++;
		}
	}
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=a[10-i];j++)
		{
			cout<<10-i;
		}
	}
	return 0;
}
