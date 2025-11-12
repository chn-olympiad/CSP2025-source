#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[550000],sum[550000];
struct pr
{
	int st;
	int ed;
}p[1100000];
bool cmp(pr x,pr y)
{
	return x.ed<y.ed;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cnt=0;
	int noed=0;
	int ans=0;
	cin>>n>>k;
	if(n<=1100)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum[i]=sum[i-1]^a[i];
		}
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				if((sum[j]^sum[i-1])==k)
				{
					++cnt;
					p[cnt].st=i;
					p[cnt].ed=j;
				}
		sort(p+1,p+cnt+1,cmp);
		for(int i=1;i<=cnt;i++)
		{
			if(p[i].st>noed)
			{
				ans++;
				noed=p[i].ed;
				
			}
		}
		cout<<ans;
	}
	else if(k<=1)
	{
		if(k==1)
		{
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
				if(a[i]==k)
					ans++;
			}
		}
		else if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
				if(a[i]==k)
					ans++;
				if(a[i]==1&&a[i+1]==1)
					ans++,i++;
			}	
		}
		cout<<ans;
	}
	return 0;
}
