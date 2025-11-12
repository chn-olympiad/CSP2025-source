#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int n;
bool f(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("numberin","r",stdin);
	freopen("numberout","w",stdout);
	string s="";
	cin>>s;
	int m=0;
	for(int i=0;i<s.length();++i)
	{
		m=int(s[i])-48;
		if(m>=0 and m<=9)
		{
			n++;
			a[n]=m;
		}
	}
	sort(a+1,a+n+1,f);
	for(int i=1;i<=n;i++) cout<<a[i];
	return 0;
}
