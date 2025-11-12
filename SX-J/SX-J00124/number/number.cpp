#include <bits/stdc++.h>
using namespace std;
int b[10],s,x=0,c[1000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(isdigit(a[i]))
		{
			b[a[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<b[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}