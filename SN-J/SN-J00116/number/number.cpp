#include<bits/stdc++.h>
#include<iostream>
#define ll long long int 

using namespace std;
char a[1000010];
ll m[90];
string s;

int main()
{
	
	freopen("number.in","r",stdin);
	freopen("nember.out","w",stdout);
	cin>>s;
	int k=0;
	for(ll i=0;i<=s.length()-1;i++)
	{
		a[i]=s[i];
		k=a[i];
		if(k<=57)
		{
			m[k-48]++;
		}
		k=0;
	}
	ll all;
	for(int i=0;i<=9;i++)
	{
		all+=m[i];
	}
	for(ll j=1;j<=all;j++)
	{
		for(int i=9;i>=0;i--)
		{
			if(m[i]!=0)
			{
				m[i]--;
				cout<<i;
				break;
			}
		}
	}
	return 0;
}
