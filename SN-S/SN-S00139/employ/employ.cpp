#include <bits/stdc++.h>
using namespace std;
int n,m,c[100005];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	int nn=n;
	for(int i=1;i<=n;i++)
	{
		if(c[i]==0)
		{
			nn--;
		}
	}
	int ans=1;
	for(int i=0;i<m;i++)
	{
		ans=ans*((nn-i)%998244353)%998244353;
	}
	return 0;
}
