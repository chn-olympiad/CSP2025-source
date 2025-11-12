#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e4+5,M=1e6+5;//long long
long long n,m,k,pan,u,v,w,i,j,ans;
long long c[20],a[20][N],head[N],cnt,f[N];
struct shu{
	long long u,v,w,next;
}e[M*2];
int cmp(shu a,shu b){
	return a.w<b.w;
}
void add(int u,int v,int w){
	e[++cnt]={u,v,w,head[u]};head[u]=cnt;
	e[++cnt]={v,u,w,head[v]};head[v]=cnt;
}
int read(){
	int op=1,x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')op=-1;
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	return op*x;
}
void out(int x){
	if(x<0){
		x=-x;cout<<"-";
	}
	if(x>=10){
		out(x/10);
	}
		cout<<x%10;
}
int fa(int u){
	if(f[u]==u)return u;
	f[u]=fa(f[u]);
	return f[u];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(i=1;i<=m;i++){
		u=read();v=read();w=read();
		if(u==v)continue;
		add(u,v,w);
	}
	for(i=1;i<=k;i++){
		c[i]=read();
		add(n+k+i,n+i,c[i]);
		if(c[i]!=0)pan=1;
		for(j=1;j<=n;j++){
			a[i][j]=read();
			if(a[i][j]!=0)pan=1;
			add(n+i,j,a[i][j]);
			add(n+k+i,j,a[i][j]);
		}
	}
	if(!pan)cout<<0;
	else{
		sort(e+1,e+cnt+1,cmp);
		for(i=1;i<=n+k+k;i++)f[i]=i;
		for(i=1;i<=cnt;i++){
			u=fa(f[e[i].u]);v=fa(f[e[i].v]);
			if(u!=v){
				f[v]=u;
				ans+=e[i].w;
			}
		}
		cout<<ans;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/