#include<bits/stdc++.h>
using namespace std;
const int MM=998244353;
int n;
int m;
string s;
int a[1000010];
int ans;
long long jiecheng(int u)
{
	int qq=1;
	for(int i=1;i<=u;i++)
	{
		qq*=i;
	 } 
	 return qq%MM;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				cout<<0;
				return 0;
			}
		 } 
	}
	else
	{
		long long man=jiecheng(n);
		long long ba=jiecheng(m);
		long long manba=jiecheng(n-m);
		cout<<(man/((manba*ba)%MM))%MM;
	}
	return 0;
}