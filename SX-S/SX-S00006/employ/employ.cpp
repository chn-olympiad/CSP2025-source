#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
int a[N];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,f=0;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=0)
		{
			f++;
		}
	}
	if(m==1)
	{
		if(f)
		{
			cout<<f%998244353;
		}
		else
		{
			cout<<0;
		}
	}
	return 0;
}