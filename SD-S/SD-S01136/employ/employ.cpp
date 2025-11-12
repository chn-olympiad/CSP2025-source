#include<bits/stdc++.h>
#define Modd 998244353
#define int long long 
using namespace std;
int s[666];
int c[666];
int id[666];
char sss[666];
int onn[666];
long long ans;
signed main()
{
    freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>sss[i];
	for(int i=0;i<n;i++) s[i+1]=sss[i]-'0';
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(m==1)
	{
		sort(c+1,c+n+1);
		int jj=1;
		for(int i=0;i<=n;i++)
		{
			while(c[jj]<=i&&jj<=n) jj++;
			if(jj<=n) id[i]=jj;
			else break;
		}
		long long sum=1;
		for(int i=n-1;i>1;i--)
		{
			sum=(sum*i)%Modd;
		}
		int cntt=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]==1)
			{
				onn[++cntt]=i;
				for(int j=1;j<=cntt;j++)
				{
					if(id[onn[j]]-j>=0)
					{
						int cnt=n-id[i-j+1]+1;
						ans=(((ans+cnt)%Modd)*sum)%Modd;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//T4
