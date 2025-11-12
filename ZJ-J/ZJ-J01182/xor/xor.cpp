#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[10005],s[10005],f[10006][5];
vector<int> vec[10005];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int u=s[j]^s[i-1];
			if(u==k)
			{
				vec[j].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		for(int j=0;j<vec[i].size();j++)
		{
			f[i][1]=max(f[i][1],f[vec[i][j]][0]+1);
		}
		if(a[i]==k)	f[i][1]=max(f[i][1],max(f[i-1][0],f[i-1][1])+1);
	}
	cout<<max(f[n][0],f[n][1]);
	return 0;
}