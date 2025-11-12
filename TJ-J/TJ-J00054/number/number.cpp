#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n=1000005;
string s;
char a[1000005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int c=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=s[i];
			c++;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<c;i++)
	{
		cout<<a[i];
	}
	return 0;
}
