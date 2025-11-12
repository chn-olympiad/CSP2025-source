#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int t;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	getline(cin,s);
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			t++;
			a[t]=s[i]-'0';
		}
	}
	sort(a+1,a+1+t,cmp);
	if(a[1]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=t;i++)
	{
		cout<<a[i];
	}
	return 0;
}
