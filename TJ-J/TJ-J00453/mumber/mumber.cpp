#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string a;
string h;
int main()
{
    freopen("mumber.in","r",stdin);
    freopen("mumber.out","w",stdout);
	int m;
	string s,l;
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		m=int(s[i]);
		if(m>=48&&m<=57){
			a+=s[i];
		}


	}
	for(int k=0;k<a.size();k++)
	{
		char n=0;
		int c;
		for(int i=0;i<a.size();i++)
		{
			if(n<a[i])
			{
				n=a[i];
				c=i;
			}
		}
		h+=n;
		a[c]=0;
	}
	cout << h;
	return 0;
}
