#include<bits/stdc++.h>
#define LF putchar('\n')
#define SP putchar(' ')
using namespace std;
typedef unsigned long long ll;
typedef unsigned int ui;
const ui N=1e6+5,INF=0x3f3f3f3f;
template<typename T>void read(T& x)
{
	x=0;char ch=getchar();while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch&15),ch=getchar();
}
template<typename T,typename... Args>void read(T& x,Args&... args){read(x);read(args...);}
template<typename T>void write(T x)
{
	if(x==0){putchar('0');return ;}if(x<0){x=-x;putchar('-');}
	ui a[25],t=0;while(x){a[++t]=x%10;x/=10;}while(t){putchar(a[t--]|48);}
}
template<typename T,typename... Ts>void write(T x,Ts... args){write(x);if(sizeof...(args)!=0){SP;write(args...);}}
struct EDGE{ui x,y,z;bool operator<(const EDGE w)const{return z<w.z;};}e[N],e2[N];
ui n,m,k,f[N],m2,w[15],a[15][N];
ll ans;
ui Find(ui x){return x==f[x]?x:f[x]=Find(f[x]);}
ll work(ui t)
{
	m=m2;
	ui i=1;
	for(;i<=n+k;i++)f[i]=i;
	for(i=1;i<=m;i++)e[i]=e2[i];
	ll res=0;
	ui c=1;
	while(t)
	{
		if(t&1)
		{
			res+=w[c];
			for(i=1;i<=n;i++)
				if(a[c][i]+a[c][1]<e2[m2].z)
					e[++m].x=i,e[m].y=n+c,e[m].z=a[c][i];
		}
		t>>=1,++c;
	}
	if(res>=ans)return ans;
	sort(e+1,e+1+m);
	for(i=1;i<=m;i++)
	{
		ui x=Find(e[i].x),y=Find(e[i].y);
		if(x==y)continue;
		f[y]=x,res=res+e[i].z;
	}
	return res;
}
void solve()
{
	read(n,m,k);
	for(ui i=1;i<=n+k;i++)f[i]=i;
	for(ui i=1;i<=m;i++)read(e[i].x,e[i].y,e[i].z);
	sort(e+1,e+1+m);
	for(ui i=1;i<=m;i++)
	{
		ui x=Find(e[i].x),y=Find(e[i].y);
		if(x==y)continue;
		f[y]=x,e2[++m2]=e[i],ans=ans+e[i].z;
	}
	for(ui i=1;i<=k;i++)
	{
		read(w[i]);
		for(ui j=1;j<=n;j++)read(a[i][j]);
	}
	ui t=1<<k;
	for(ui i=1;i<t;i++)ans=min(ans,work(i));
	write(ans);
	LF;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();
	return 0;
}

