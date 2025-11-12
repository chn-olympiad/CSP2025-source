#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+666;
const int N=1e4+666;
const int inf=1e18+7;
int read(){
	int res=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		res=(res<<3)+(res<<1)+(c^48);
		c=getchar();
	}
	return res;
}
void print(int x){
	if(x>9)print(x/10);
	putchar((x%10)^48);
}
int n,m,k,ans,cnt;
struct edge{
	int u,v,w;
	bool operator <(edge c1)const{
		return w<c1.w;
	}
}E[M],e[M],ee[M];
vector<pair<int,int> >G[N];
int a[12][N],fa[N],rk[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);y=find(y);
	if(x==y)return;
	if(rk[x]<rk[y])fa[x]=y;
	else if(rk[x]>rk[y])fa[y]=x;
	else{
		fa[x]=y;
		rk[y]++;
	}
}
bool col[N];
int w[N];
int GET(int mask){
	int res=0,ncnt=cnt,ttt=0;
	for(int i=1;i<=k;++i){
		if(mask>>(i-1)&1){
			ttt++;res+=a[i][0];
		}
	}
	for(int i=1;i<=cnt;++i)ee[i]=e[i];
	for(int i=1;i<=n+k;++i){
		fa[i]=i;rk[i]=0;
	}
	for(int i=n+1;i<=n+k;++i){
		int j=i-n;
		if(mask>>(j-1)&1){
			for(int o=1;o<=n;++o){
				ee[++ncnt]={o,i,a[j][o]};
			}
		}
	}
	sort(ee+1,ee+1+ncnt);
	for(int i=1,tot=1;i<=ncnt;++i){
		int u=ee[i].u,v=ee[i].v;
		if(find(u)==find(v))continue;
		res+=ee[i].w;
		merge(u,v);
		tot++;
		if(tot==n+ttt)break;
	}
//	cout<<mask<<":"<<res<<"\n";
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	ans=0;
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
	for(int i=1;i<=m;++i){
		E[i].u=read();E[i].v=read();E[i].w=read();
	}
	for(int i=1;i<=k;++i){
		for(int j=0;j<=n;++j){
			a[i][j]=read();
		}
	}
//	solve();
//	for(int mask=1;mask<(1<<k);++mask){
//		for(int i=1;i<=n;++i){
//			sum[mask]+=t[mask][i];
//		}
//		ans=min(ans,sum[mask]+cost[mask]);
//	}
	sort(E+1,E+1+m);
	for(int i=1,tot=1;i<=m;++i){
		int u=E[i].u,v=E[i].v;
		if(find(u)==find(v))continue;
		ans+=E[i].w;
		e[++cnt]=E[i];
		merge(u,v);
		tot++;
		if(tot==n)break;
	}
	for(int i=0;i<(1<<k);++i){
		ans=min(ans,GET(i));
	}
	print(ans);putchar('\n');
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
