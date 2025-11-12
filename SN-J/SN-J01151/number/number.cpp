#include<bits/stdc++.h>
using namespace std;
long long number[1000005],n;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]=='0')
		{
			n++;
			number[n]=0;
		}
		if(s[i]=='1')
		{
			n++;
			number[n]=1;
		}
		if(s[i]=='2')
		{
			n++;
			number[n]=2;
		}
		if(s[i]=='3')
		{
			n++;
			number[n]=3;
		}
		if(s[i]=='4')
		{
			n++;
			number[n]=4;
		}
		if(s[i]=='5')
		{
			n++;
			number[n]=5;
		}
		if(s[i]=='6')
		{
			n++;
			number[n]=6;
		}
		if(s[i]=='7')
		{
			n++;
			number[n]=7;
		}
		if(s[i]=='8')
		{
			n++;
			number[n]=8;
		}
		if(s[i]=='9')
		{
			n++;
			number[n]=9;
		}
	}
	sort(number+1,number+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		cout<<number[i];
	}
	cout<<endl;
	return 0;
}
