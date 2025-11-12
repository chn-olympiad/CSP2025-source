#include<bits/stdc++.h> 
using namespace std;
const int N=1e6+5;
long long net[N*5],head[N*5],to[N*5],p,n,m,k,ci[5*N],cc[5*N],ans=1e18,flag[5*N];
void dfs(long long now,long long f,long long sum,long long tot){
	if(tot==n) {
		ans=min(ans,sum);
		return;
	}
	for(long long i=head[now];i;i=net[i]){
		long long v=to[i];
		if(v==f)continue;
		if(flag[v]==1)continue;
		flag[v]=1;
		if(cc[v]!=0)dfs(v,now,sum+ci[i]+cc[v],tot);
		else dfs(v,now,sum+ci[i],tot+1);
		flag[v]=0;
	}
}
void addedge(long long a,long long b,long long c){
	to[++p]=b;
	net[p]=head[a];
	head[a]=p;
	ci[head[a]]=c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		long long x,y,c;
		cin>>x>>y>>c;
		addedge(x,y,c);
		addedge(y,x,c);
	}
	for(long long i=1;i<=k;i++){
		long long ss=i+n;
		long long ccc;
		cin>>ccc;
		cc[ss]=ccc;
		for(long long i=1;i<=n;i++){
			cin>>ccc;
			addedge(ss,i,ccc);
			addedge(i,ss,ccc);
		}
	}
	dfs(1,0,0,1);
	cout<<ans;
	return 0;
}
