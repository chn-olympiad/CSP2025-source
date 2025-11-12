#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF=0x3f3f3f3f3f3f3f3f;
const int N=2e6+5;
const int D=1e5+5;
int n,m,k;
/*
struct node{
	int v,nxt,w;
}e[N<<1];
int tot,h[D];*/
struct edge{
	int u,v,w;
	bool operator < (const edge &oo) const{
		return w>oo.w;
	}
}b[N];
int c[12],f[12][D];
int siz[D];
int fa[D];
ll ad,anss=INF;
priority_queue<edge> q,q2; 
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
} 
void solve(int mm,int fff){
//	sort(b+1,b+1+mm,cmp);
	int cnt=0;
	ll ans=0;
	for(int i=1;i<=n;++i) fa[i]=i,siz[i]=1;
///	for(int i=1;i<=mm;i++) cout<<b[i].u<<" "<<b[i].v<<"-"<<b[i].w<<endl;
//	cout<<endl;
	for(int i=1;i<=mm;++i){
		if(q2.empty()){
		//	cout<<"k!"<<endl;
			return ;
		}
		int u=q2.top().u,v=q2.top().v,w=q2.top().w;
		q2.pop();
	//	cout<<u<<" "<<v<<" "<<w<<"-"<<cnt<<endl;
		if(u==v) continue;
		u=find(u),v=find(v);
		if(u==v) continue;
	//	cout<<u<<" "<<v<<" "<<w<<" "<<cnt<<endl;
		cnt++;
		if(siz[u]>siz[v]) swap(u,v);
		fa[u]=v;
		siz[v]+=siz[u];
		ans=ans+1ll*w;
		if(ans+ad>anss) return ;
		if(cnt==n-1) break;		
	}
//	cout<<cnt<<"?"<<ans+ad<<endl;
	if(fff) anss=min(anss,ans+ad);
	else printf("%lld\n",ans+ad);
}
void solve2(){
	int tt=m;
	for(int i=1;i<=k;++i){
		ad+=f[i][i];
		for(int j=1;j<=n;++j){
			b[++tt]={i,j,f[i][j]};
		}
	}
	solve(tt,0);
}
void solve3(){
	int tt=m;
	ad=0;
	for(int i=0;i<(1<<k);++i){
		ad=0;
		int x=i,ct=1;
		tt=m;
		q2=q;
		ll mii=INF;
		while(x){
			if(x&1){
			//	cout<<ct<<' ';
				ad+=1ll*c[ct];
			//	mii=min(mii,1ll*f[ct][ct]);	
				ad+=1ll*f[ct][ct];
		//		cout<<f[ct][ct]<<" ";
				for(int j=1;j<=n;++j) {
				//	cout<<tt<<"?"<<endl;
					++tt;
					q2.push({ct,j,f[ct][j]});
				//	b[++tt]={ct,j,f[ct][j]};	
				}
			}
			
			x>>=1;
			ct++;
		}
	//	cout<<endl;
		solve(tt,1);
	}
}
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;
		x=read(),y=read(),z=read();
		b[i]={x,y,z};
		q.push({x,y,z});
	}
	int fl=0;
	for(int i=1;i<=k;i++){
		c[i]=read();
	//	cout<<c[i]<<" ";
		if(c[i]) fl=1;
		for(int j=1;j<=n;j++){
			f[i][j]=read();
		}
	}
	if(k==0){
		solve(m,0);
		return 0;
	}
	/*if(!fl){
		solve2();
		return 0;
	}*/
	solve3(); 
	printf("%lld\n",anss);
	return 0;
}
