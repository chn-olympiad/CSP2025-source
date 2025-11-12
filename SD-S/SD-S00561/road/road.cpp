#include<bits/stdc++.h>
#include<limits.h>
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
#define pii pair<int,int>
#define int long long
using namespace std;

// rp++;

inline ll read(){
	ll x=0,w=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar();}
	while(c<='9'&&c>='0') x=x*10+c-'0',c=getchar();
	return x*w;
}

struct node{
	int u,v,w;
	node(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
	bool operator<(node p){return w<p.w;}
};

const int N=10050,M=1200000,inf=0x3f3f3f3f;
int n,m,k,x,y,z,cost[20],fa[N];
node edge[M];

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y){fa[x]=y;}

ll work(int cj){
//	cerr<<"working at: "<<cj<<endl;
	int cnt=0;
	ll res=0;
	bool chs[20]={0};
	for(int i=1;i<=k;i++){
		if((cj>>(i-1))&1){
			chs[i]=1;
			cnt++;
			res+=cost[i];
		}
	}
//	for(int i=1;i<=k;i++){
//		cerr<<chs[i]<<" ";
//	}cerr<<endl;
//	cerr<<"res': "<<res<<endl;
	for(int i=1;i<=n+k+10;i++) fa[i]=i;
//	cerr<<"tot: "<<n+cnt<<endl;
	int num=n+cnt,ii=1;
	while(num>1){
//		cerr<<"num: "<<num<<endl;
		node e=edge[ii++];
		int tmp=max(e.u,e.v);
//		cerr<<"tmp: "<<tmp<<endl;
		if(tmp>n){
			if(chs[tmp-n]==0) continue;
//			cerr<<"jumped: "<<e.u<<" "<<e.v<<endl;
		}
		if(find(e.u)==find(e.v)) continue;
		res+=e.w;
		merge(e.u,e.v);
//		cerr<<"merged: "<<e.u<<" "<<e.v<<"cost: "<<e.w<<endl;
		num--;
	}
//	cerr<<"res: "<<res<<endl;
	return res;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		x=read(),y=read(),z=read();
//		cin>>x>>y>>z;
		edge[i]={x,y,z};
	}
	for(int i=1;i<=k;i++){
		cost[i]=read();
		for(int j=1;j<=n;j++){
			x=read();
			edge[++m]={n+i,j,x};
		}
	}
	sort(edge+1,edge+m+1);
//	cerr<<"m "<<m<<endl;
//	cerr<<work(0);
	int up=(1<<k)-1;
	ll ans=LLONG_MAX;
	for(int cj=0;cj<=up;cj++){
		ans=min(ans,work(cj));
	}
	cout<<ans;
	return 0;
}
