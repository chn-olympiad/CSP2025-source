#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string n;
char a[1000005];
int k;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<=n.length();i++)
	{
		if(n[i]>='0'&&n[i]<='9')
		{
			a[k]+=n[i];
			k++;
		}
	}
	sort(a,a+n.length());
	for(int i=n.length()-1;i>=0;i--)
	{
		if(int(n[i])-48>=0)
		{
			cout<<int(n[i])-48;
		}
	}
	return 0;
}
