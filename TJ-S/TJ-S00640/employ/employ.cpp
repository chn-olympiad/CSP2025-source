#include<bits/stdc++.h>
using namespace std;
int c[510]={0};

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	long long ji=1;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	int x=n;
	for(int i=1;i<=x;i++)
	{
		if(c[i]<=0)
		{
			for(int j=i+1;j<=x;j++)	c[j]--;
			n--;
		}
	}
	while(n>=1)
	{
		ji*=n;
		ji=ji%998244353;
		n--;
	}
	cout<<ji;
	return 0;
}
