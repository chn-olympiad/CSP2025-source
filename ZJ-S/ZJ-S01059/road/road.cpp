#include<bits/stdc++.h>
using namespace std;
long long ans=1e18;
int n,m,k;
int h[10019],e[2200009],ne[2200009],w[2200009],idx=1;
void add(int a,int b,int c){
	e[idx]=b;
	w[idx]=c;
	ne[idx]=h[a];
	h[a]=idx++;
}
long long dist[10019];
bool st[10019];
int g[19];
long long fun(int a){
	long long sum=0;
	priority_queue<pair<long long,int>> q;
	memset(dist,0x3f,sizeof dist);
	memset(st,0,sizeof st);
	dist[1]=0;
	q.push({0,1});
	while(q.size()){
		pair<long long,int> t=q.top();
		q.pop();
		int u=t.second;
		if(st[u])continue;
		st[u]=1;
		sum+=dist[u];
		for(int i=h[u];i;i=ne[i]){
			int x=e[i];
			if(st[x])continue;
			if(x>n&&!((1<<(x-1-n))&a))continue;
			if(dist[x]>w[i]){
				dist[x]=w[i];
				q.push({-dist[x],x});
			}
		}
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&g[i]);
		for(int j=1;j<=n;j++){
			int c;
			scanf("%d",&c);
			add(i+n,j,c);
			add(j,i+n,c);
		}
	}
	for(int i=0;i<=(1<<k)-1;i++){
		long long a=0;
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1)))a=a+g[j];
		}
		ans=min(ans,fun(i)+a);
	}
	cout<<ans;
	return 0;
}
