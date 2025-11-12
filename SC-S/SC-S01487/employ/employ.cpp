#include<bits/stdc++.h>
using namespace std;
const int L=998244353;
int n,m,c[1000005],p,r,sum;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[j]=='1'||c[j]<=p)
			{
				p++;
			}
			else
			{
				r++;
			}
		}
		if(r>=m)
		{
			sum++;
		}
		int x=c[i];
		for(int i=2;i<=n;i++)
		{
			c[i-1]=c[i];
		}
		c[n]=x;
	}
	cout<<sum%L;
	return 0;
}