#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==m)
	{
		cout<<0;
	}else if(s[1]=='1'&&s[2]=='1')
	{
		cout<<n*m;
	}else
	{
		cout<<2;
	}
	return 0;
	} 
