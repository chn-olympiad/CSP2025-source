#include<bits/stdc++.h>
#define ll long long
#define N 20005
#define M 1500005
#define inf 0x3f3f3f3f3f3f3f3f
#define Pr pair<ll,int>
using namespace std;

int n,m,k;
int c[15],vis[N];
ll ans=inf;
struct edge{
	int to,nxt;
	ll dis;
}e[M<<1];
int head[N],ecnt;

void addedge(int x,int y,ll z){
	e[++ecnt].to=y;
	e[ecnt].dis=z;
	e[ecnt].nxt=head[x];
	head[x]=ecnt;
}

priority_queue<Pr,vector<Pr>,greater<Pr> >q;

void prim(int s){
	int num=0,cnt=0;
	ll sum=0;
	for(int i=1;i<=k;i++)if(s&(1<<(i-1)))sum+=c[i],++num;
	for(int i=1;i<=n+k;i++)vis[i]=0;
	while(!q.empty())q.pop();
	q.push({0,1});
	while(!q.empty()){
		int dist=q.top().first,x=q.top().second;
		q.pop();
		if(vis[x])continue;
		if(x>n&&(!((1<<(x-n-1))&s)))continue;
		vis[x]=1;
		++cnt;
		sum+=dist;
		if(cnt>=n+num)break;
		if(sum>ans)return;
		for(int i=head[x];i;i=e[i].nxt){
			int y=e[i].to;
			if(vis[y])continue;
			if(y>n&&(!((1<<(y-n-1))&s)))continue;
			q.push({e[i].dis,y});
		}
	}
	ans=min(ans,sum);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		addedge(a,b,c);
		addedge(b,a,c);
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		ll x;
		for(int i=1;i<=n;i++){
			cin>>x;
			addedge(i,n+j,x);
			addedge(n+j,i,x);
		}
	}
	for(int s=0;s<(1<<k);s++){
		prim(s);
	}
	cout<<ans;
	return 0;
}
