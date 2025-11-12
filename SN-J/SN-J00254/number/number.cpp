#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int NUM=1e6+5;
int a[NUM];
int n=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			n++;
			a[n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;n>=1;n--)
	{
		cout<<a[n];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
