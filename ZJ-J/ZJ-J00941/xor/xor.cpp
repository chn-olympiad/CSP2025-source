#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,k,cnt1,cnt2,maxn;
long long ans[N],a[N];
void dfs(int x,long long cnt)
{
	maxn=max(maxn,cnt);
	for(int i=x;i<=n;i++)
		if((ans[i]^ans[x-1])==k)
			dfs(i+1,cnt+1);
	if(x+1<=n) dfs(x+1,cnt);
	return ;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans[i]=ans[i-1]^a[i];
		if(a[i]==1) cnt1++;
		if(a[i]==0) cnt2++;
	}
	if(cnt1==n)
	{
		cout<<n/2;
		return 0;
	}
	else if(cnt1+cnt2==n)
	{
		long long cnt3=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k) cnt3++;
			if(k==0&&a[i]!=k&&a[i+1]!=k&&i+1<=n)
			{
				cnt3++;
				i++;
			}
		}
		cout<<cnt3;
		return 0;
	}
	dfs(1,0);
	cout<<maxn;
	return 0;
}
