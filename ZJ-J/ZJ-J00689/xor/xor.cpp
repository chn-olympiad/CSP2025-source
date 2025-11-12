#include<bits/stdc++.h>
using namespace std;
int n,k,a[500100],h[1111][1111];
bool check1()
{
	for(int i=1;i<=n;i++)
		if(a[i]>1) return 0;
	return 1;
}
void solve1()
{
	int f[1111];
	memset(f,0,sizeof f);
	memset(h,0,sizeof h);
	for(int i=1;i<=n;i++) h[i][i]=a[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			h[i][j]=h[i][j-1]^a[j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
		{
			if(h[j][i]==k) f[i]=max(f[i],f[j-1]+1);
			else f[i]=max(f[i],f[j-1]);
		}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,f[i]);
	cout<<ans;
	return ;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(check1())
	{
		int cnt=0;
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0) cnt++;
				if(a[i]==1 && a[i-1]==1) cnt++,a[i]=0;
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
				if(a[i]==1) cnt++;
		}
		cout<<cnt;
		return 0;
	}
	if(n<=1000)
	{
		solve1();
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(a[i]==k) cnt++;
	cout<<cnt;
	return 0;
}
