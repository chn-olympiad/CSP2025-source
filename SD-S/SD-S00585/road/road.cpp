#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm> 
#define ll long long
using namespace std;

inline ll read() {
	ll x=0,t=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-')
			t=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*t;
}

inline void write(ll x) {
	if(x==0) {
		putchar('0');
		return;
	}
	if(x<0)
		x=-x;
	if(x>9)
		write(x/10);
	putchar(x%10+'0');
}

ll qpow(ll x,ll y,ll mod) {
	ll res=1;
	while(y) {
		if(y&1)
			res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}

const int N=1e4+7,M=1e8+7;

struct node{
	int v,w;
};

vector<node> r[N];

struct bian{
	int v,w,cou;
}q[M];

int fa[N],vis[17],c[17],a[17][N];

bool cmp(bian a,bian b) {
	if(a.w==b.w) {
		if(!a.cou || !b.cou)
			return a.cou>b.cou;
		return a.v<b.v;
	}
	return a.w<b.w;
}

int find(int x) {
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read(),u,w,v;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++) {
		u=read(),v=read(),w=read();
		r[u].push_back({v,w});
		r[v].push_back({u,w});  
	}
	for(int i=1;i<=k;i++) {
		c[i]=read();
		for(int j=1;j<=n;j++) {
			a[i][j]=read();
		}
	}
	
	int now=1,len=1,i=1,num=n,ans=0;
	
	while(num) {
		for(node h:r[now]) {
			q[len]={h.v,h.w,0};
			len++; 
		}
		for(int j=1;j<=n;j++) {
			if(find(j)==find(now))
				continue;
			for(int l=1;l<=k;l++) {
				q[len]={j,a[l][now]+a[l][j]+c[l],l};
				len++;
			}
		}
		
		sort(q+i,q+len,cmp);
		
		for(i;i<len;i++) {
			if(find(q[i].v)==find(now))
				continue;
			c[q[i].cou]=0;
			ans+=q[i].w;
			fa[q[i].v]=find(now);
			now=q[i].v;
			break;
		}
		num--;
	}
	cout<<ans;
	return 0;
}

