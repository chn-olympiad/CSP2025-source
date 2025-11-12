#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
#define gc() getchar()
	int x=0,f=1;
	char ch=gc();
	for(;!isdigit(ch);ch=gc()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=gc()) x=x*10+ch-'0';
	return x*f;
}
const int N=1e4+10,M=1e6+10;
int n,m,k,c[15],a[15][N],p[N*2],cnt[15],d[N],dw[N];
LL f[15],g[15];
struct node{
	int u,v,w;
	bool operator<(const node &t)const{
		return w<t.w;
	}
}ed[M],ed1[15][N*15],ed2[N*15];
int find(int x){
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++) p[i]=i;
	int u,v,w;
	for(int i=1;i<=m;i++) u=read(),v=read(),w=read(),ed[i]={u,v,w};
	sort(ed+1,ed+1+m);
	for(int i=1;i<=m;i++){
		int a=ed[i].u,b=ed[i].v,w=ed[i].w;
		if(find(a)!=find(b)){
			p[find(a)]=find(b);
			f[0]+=w;
			ed1[0][++cnt[0]]={a,b,w};
		}
	}
	for(int i=1;i<=k;i++){
		memset(d,0,sizeof d);
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
		for(int j=1;j<=n+k;j++) p[j]=j;
		cnt[i]=cnt[i-1];
		g[i]=g[i-1]+c[i];
		memcpy(ed1[i],ed1[i-1],sizeof ed1[i-1]);
		for(int t=1;t<=n;t++) ed1[i][++cnt[i]]={t,i+n,a[i][t]};
		sort(ed1[i]+1,ed1[i]+cnt[i]+1);
		for(int j=1;j<=cnt[i];j++){
			int a=ed1[i][j].u,b=ed1[i][j].v,w=ed1[i][j].w;
			a=find(a),b=find(b);
			if(a!=b){
				p[a]=b;
				f[i]+=w;
				d[a]++,d[b]++;
				dw[a]=w,dw[b]=w;
			}
		}
		for(int j=n+1;j<=n+i;j++) if(d[j]==1) f[i]-=dw[j],g[i]-=c[j-n];
		f[i]+=g[i];
		if(f[i]>f[i-1]) cnt[i]=cnt[i-1],memcpy(ed1[i],ed1[i-1],sizeof ed1[i-1]),f[i]=f[i-1],g[i]=g[i-1];
	}
	cout<<f[k];
	
	return 0;
}