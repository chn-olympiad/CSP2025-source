#include<bits/stdc++.h>
#define int long long
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define dow(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
const int N=1e5+5;
int n;
int cnt[3],sum;
int a[N][3],b[N],c[N],d[N],idx;
void solve()
{
	sum=0;
	scanf("%lld",&n);
	rep(i,1,n) scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
	rep(i,0,2) cnt[i]=0;
	int ip,ma,cma,cip;
	rep(i,1,n)
	{
		ma=cma=0;
		rep(j,0,2)
		  if(a[i][j]>=ma)
		    cma=ma,cip=ip,ma=a[i][j],ip=j;
		  else if(a[i][j]>=cma)
		    cma=a[i][j],cip=j;
		cnt[ip]++;
		sum+=a[i][ip];
		b[i]=ip;
		c[i]=cip;
	}
	int m=0,k;
	rep(i,0,2)
	  if(cnt[i]>=m)
	    m=cnt[i],k=i;
	if(m<=n/2) {printf("%lld\n",sum);return;}
	idx=0;
	rep(i,1,n)
	{
		if(b[i]!=k) continue;
		d[++idx]=a[i][b[i]]-a[i][c[i]];
	}
	sort(d+1,d+1+m);
	rep(i,1,m-n/2) sum-=d[i];
	printf("%lld\n",sum);
	return;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while(T--) solve();
	return 0;
}