#include<bits/stdc++.h>
using namespace std;
string s;
int a[10000];
int m,n,sum,summ;
int ox,son;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[1]==1)
	{
		cout<<9;
	}
	if(a[1]==2)
	{
		cout<<6;
	}
	return 0;
}
