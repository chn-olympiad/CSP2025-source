#include<bits/stdc++.h>
#define int long long
#define N 10005
#define M 1000005
using namespace std;
int ans,mi=1e18,to,num,t,n,m,k,x,y,z,f[10020],c[13][10005];
struct node{ int x,y,z; }a[M],b[N],d[N*12];
int read()
{
	int s=0; bool f=0; char c=getchar();
	for(;!isdigit(c);c=getchar()) f|=!(c^45);
	for(;isdigit(c);c=getchar()) s=(s<<1)+(s<<3)+(c^48);
	if(f) s=-s; return s;
}
bool cmp(node x,node y) { return x.z<y.z; }
int get(int x) { return (x==f[x]?x:get(f[x])); }
void sol()
{
	int c=0;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(get(a[i].x)!=get(a[i].y))
			f[get(a[i].x)]=get(a[i].y),b[++t]=a[i],c++;
		if(c==n-1) return;
	} return;
}
int sol2()
{
	int c=0,s=0,l1=1,l2=1;
	node x;
	for(int i=1;i<=n+k;i++) f[i]=i;
	sort(d+1,d+1+to,cmp);
	while(c<n+num-1)
	{
		if(l1>=n || l2<=to && b[l1].z>d[l2].z) x=d[l2],l2++;
		else x=b[l1],l1++;
		if(get(x.x)!=get(x.y)) f[get(x.x)]=get(x.y),c++,s+=x.z;
	}
	return s;
}
bool check()
{
	int fla;
	for(int i=1;i<=k;i++)
	{
		if(c[i][0]!=0) return false;
		fla=0;
		for(int j=1;j<=n;j++)
			if(c[i][j]==0) { fla=1; break; }
		if(!fla) return false;
	}
	return true;
}
void solt()
{
	ans=0,to=0,num=k;
	for(int j=1;j<=k;j++)
		for(int l=1;l<=n;l++) d[++to]=(node){n+j,l,c[j][l]};
	ans+=sol2();
	cout<<ans; return;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++) x=read(),y=read(),z=read(),a[i]=(node){x,y,z};
	sort(a+1,a+1+m,cmp); sol();
	for(int i=1;i<=k;i++)
	{
		c[i][0]=read();
		for(int j=1;j<=n;j++) c[i][j]=read();
	}
	if(check()) { solt();  return 0; }
	for(int i=0;i<(1<<k);i++)
	{
		ans=0,to=0,num=0;
		for(int j=1;j<=k;j++)
		{
			if(!((i>>j-1)&1)) continue;
			ans+=c[j][0],num++;
			for(int l=1;l<=n;l++) d[++to]=(node){n+j,l,c[j][l]};
		}
		ans+=sol2(); mi=min(mi,ans);
	}
	cout<<mi;
	return 0;
}