#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],b[500010],l,r,md,sum,ans;
void dfs(int st,int nw)
{
	if(st>md)
	{
		sum++;
		return;
	}
	for(int i=nw;i<=n-md+st;i++)
	  if((b[i]^b[nw-1])==k)
		dfs(st+1,i+1);
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	for(int i=1;i<=n;i++)
	  b[i]=b[i-1]^a[i];
	l=1;
	r=n;
	while(l<=r)
	{
		md=(l+r)/2;
		sum=0;
		dfs(1,1);
		if(sum)
		{
			l=md+1;
			ans=md;
		}
		else
		  r=md-1;
	}
	cout<<ans;
	return 0;
}
