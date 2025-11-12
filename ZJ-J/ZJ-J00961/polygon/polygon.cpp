#include<bits/stdc++.h>
using namespace std;
int n,a[5010],sp[5010];
long long ans,mod=998244353,s[5010],sl[5010],sx,hj,hx,x,y;
void check(int l,int r,int id,int lx)
{
	while(l<=r)
	{
		int mid=l+r>>1;
		if(sp[mid+lx]-sp[mid-1]<=a[id]) l=mid+1;
		else r=mid-1;
	}
	int x=l;
	if(x+lx<id)
	ans=(ans+sl[x-lx-1]*sl[x-1]%mod+1)%mod;
}
void dfs(int id,long long sum)
{
	if(sum>a[id]*2) ans++;
	if(id==n) return;
	for(int i=id+1;i<=n;i++) dfs(i,sum+a[i]);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	s[1]=1;sl[1]=1;
	for(int i=2;i<=5000;i++)
	{
		s[i]=s[i-1]+i%mod;
		sl[i]=sl[i-1]*1ll*i%mod;
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sp[i]=sp[i-1]+a[i];
	sort(a+1,a+n+1);
	if(a[n]==1)
	{
		hx=1;
		for(int i=1;i<=n-2;i++)
		{
			x=(x+hx)%mod;
			y=(y+x)%mod;
			hj=(hj+y)%mod;
			hx=hx*2%mod;
		}
		printf("%lld",hj);
		return 0;
	}
	else if(n<=30) dfs(0,0);
	else
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=i-2;j++)
		check(1,i-j,i,j);
	}
	cout<<ans%mod<<endl;
	return 0;
}
