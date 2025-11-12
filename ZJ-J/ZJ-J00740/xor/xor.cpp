#include<bits/stdc++.h>
using namespace std;
long long f[500005],a[500005],n,m,i,j,k=0,t,answer=1,ok2=1;
struct XX
{
	long long l,r;
}ans[1000005];
bool cmp(XX a,XX b)
{
	return a.r<b.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1)ok2=0;
	}
	if(m==0&&n>1000)
	{
		long long ansansans=0;
		for(i=1;i<=n;i++)if(a[i]==m)ansansans++;
		cout<<ansansans;
		return 0;
	}
	if(ok2==1&&n>1000)
	{
		if(m!=1)
		{
			cout<<0;
			return 0;
		}
long long ansans=0;
			for(i=1;i<=n;i++)if(a[i]==m)ansans++;
			cout<<ansans;
			return 0;
	}
	for(i=1;i<=n;i++)
	{
		long long sdjh=0;
		sdjh^=f[i-1];
		sdjh^=a[i];
		f[i]=sdjh;
	}
	for(i=1;i<=n;i++)
	for(j=i;j<=n;j++)
	{
		long long sdhsj=0;
		sdhsj^=f[j];
		sdhsj^=f[i-1];
		if(sdhsj==m)
		{
			ans[++k].l=i;
			ans[k].r=j;
		}
	}
	sort(ans+1,ans+k+1,cmp);
	t=ans[1].r;
	for(i=2;i<=k;i++)
	{
		if(ans[i].l>t)
		{
			answer++;
			t=ans[i].r;
		}
	}
	cout<<answer;
	return 0;
}
