bool M1;
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<random>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<string>

#define ll long long
#define inf ((ll)1e18)
#define pc putchar
#define pb push_back
#define mid ((l+r)>>1)
#define lowbit(x) ((x)&(-(x)))
#define pir pair<int,int>
#define plr pair<ll,ll>
#define fi first
#define se second

using namespace std;

ll read(){
	ll w,f=1;char c;
	while((c=getchar())>'9'||c<'0')
		if(c=='-')f=-1;
	w=c-'0';
	while((c=getchar())>='0'&&c<='9')
		w=w*10+c-'0';
	return w*f;
}

signed NEV[102],NE;

void print(ll x){
	if(x<0)
		pc('-'),x=-x;
	if(x==0)
		pc('0');
	while(x)
		NEV[++NE]=x%10,x/=10;
	while(NE)
		pc(NEV[NE--]+'0');
}

const int N=1e4+5,M=1e6+5;

struct DSU{
	int fa[N],sum[N];
	void init(int n){
		for(int i=1;i<=n;i++)	
			fa[i]=i,sum[i]=1;
	}
	int fd(int x){
		return fa[x]==x?x:fa[x]=fd(fa[x]);
	}
	bool merge(int x,int y){
		x=fd(x),y=fd(y);
		if(x==y)
			return 0;
		if(sum[x]<sum[y])swap(x,y);
		fa[y]=x;sum[x]+=sum[y];
		return 1;
	}
}D;

struct edge{
	int u,v,w;
	bool operator<(edge ano)const{
		return w<ano.w;
	}
}E[12][M];

int c[N];

struct dudu{
	int at,id,w;
	bool operator<(dudu ano)const{
		return w>ano.w;
	}
};
priority_queue<dudu>q;

bool M2;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cerr<<(&M1-&M2)/1024.0/1024.0<<endl;
	double st=clock();
	int n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		E[0][i]={u,v,w};
	}
	sort(E[0]+1,E[0]+1+m);
	int tot=0;D.init(n);
	for(int i=1;i<=m;i++){
		int u=E[0][i].u,v=E[0][i].v;
		if(D.merge(u,v))
			E[0][++tot]=E[0][i];
	}m=tot;
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)
			E[i][j]={i+n,j,read()};
		sort(E[i]+1,E[i]+1+n);
	}
	int all=(1<<k)-1;
	ll ans=inf;
	for(int l=0;l<=all;l++){
		while(!q.empty())q.pop();
		D.init(n+k);
		q.push({0,1,E[0][1].w});
		ll sum=0;
		for(int i=1;i<=k;i++)
			if((l>>(i-1))&1)
				q.push({i,1,E[i][1].w}),sum+=c[i];
//		cout<<l<<" "<<sum<<endl;
		int cnt=-(int)__builtin_popcount(l);
		while(!q.empty()&&cnt<n-1){
			int at=q.top().at,id=q.top().id;
			q.pop();
			int u=E[at][id].u,v=E[at][id].v,w=E[at][id].w;
			if(at==0&&id<m||at!=0&&id<n)
				q.push({at,id+1,E[at][id+1].w});
			if(D.merge(u,v))
				cnt++,sum+=w;
		}
//		cout<<l<<" "<<cnt<<" "<<sum<<endl;
		if(cnt==n-1)
			ans=min(ans,sum);
	}print(ans),pc('\n');
	cerr<<(clock()-st)/1000.0<<endl;
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
