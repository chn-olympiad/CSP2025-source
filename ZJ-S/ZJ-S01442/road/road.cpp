#include<bits/stdc++.h>
#define Debug puts("--------------")
#define LL long long 
#define PII pair<int,int>
#define fi first
#define se second 
#define mk make_pair
using namespace std;
const int N=1e4+100,M=1e6+5,K=15;
inline int read(){
	int s=0,w=1;
	char c=getchar();
	for(;c<'0'||c>'9';w*=(c=='-')?(-1):1,c=getchar());
	for(;c>='0'&&c<='9';s=s*10+c-'0',c=getchar());
	return s*w;
}
int n,m,k,c[N],fa[N];
PII a[K][N];
LL ans;
struct Edge{
	int u,v,w;
}E[M],MST[N];
int get(int x){ return (x==fa[x])?x:(fa[x]=get(fa[x])); }
void merge(int x,int y){ fa[get(x)]=get(y); }
void Kruskal(){
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(E+1,E+m+1,[&](Edge x,Edge y){ return x.w<y.w; });
	for(int i=1,tot=0;i<=m;i++){
		int x=get(E[i].u),y=get(E[i].v),w=E[i].w;
		if(x==y) continue;
		fa[x]=y,MST[++tot]=E[i],ans+=w;
	}
}
inline int lowbit(int x){ return x&(-x); }
int id[20],l[20];
LL work(int S){
//	Debug;
//	cout<<S<<':'<<'\n';
	
	LL res=0;
	int num=n+__builtin_popcount(S),cnt=0;
	l[0]=1;
	for(int T=S;T;T-=lowbit(T)){
		int x=__lg(lowbit(T))+1;
		res+=c[x];
		id[++cnt]=x,l[cnt]=1;
	}
	
	for(int i=1;i<=num;i++) fa[i]=i;
	int x,y,w=MST[1].w,op=0;
	for(int i=1;i<=cnt;i++){
		int tw;
		if((tw=a[id[i]][1].fi)<w) op=i,w=tw;
	}
	for(int _=1;_<num;_++){
		int pos=l[op];
		if(op==0) x=MST[pos].u,y=MST[pos].v;
		else x=n+op,y=a[id[op]][pos].se;
//		cout<<x<<' '<<y<<'\n';
		res+=w,l[op]++;
		merge(x,y);
		w=INT_MAX,op=0;
		while(l[0]<n){
			pos=l[0];
			if(get(MST[pos].u)==get(MST[pos].v)) l[0]++;
			else break;
		} 
		if(l[0]<n&&MST[l[0]].w<w) w=MST[l[0]].w,op=0;
		for(int i=1;i<=cnt;i++){
			while(l[i]<=n){
				pos=l[i];
				if(get(n+i)==get(a[id[i]][pos].se)) l[i]++;
				else break;			
			}
			int tw;
			if(l[i]<=n&&(tw=a[id[i]][l[i]].fi)<w) op=i,w=tw;
		}
	}
//	cout<<res<<'\n';
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
 	n=read(),m=read(),k=read();
 	for(int i=1;i<=m;i++){
 		int u=read(),v=read(),w=read();
 		E[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j].fi=read(),a[i][j].se=j;
		sort(a[i]+1,a[i]+n+1);
	}
	Kruskal();
	if(n!=1){
		for(int S=1;S<(1<<k);S++) ans=min(ans,work(S));
	}
	printf("%lld\n",ans);
	return 0;
}

