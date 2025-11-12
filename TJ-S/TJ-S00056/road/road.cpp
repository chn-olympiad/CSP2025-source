#include<bits/stdc++.h>
#define LANH using
#define AK namespace
#define CSPS std
LANH AK CSPS;
typedef long long ll;
ll n,m,k;
struct nodess{
	vector<pair<int,ll> >s;
}a[10209];
ll b[109][10009];
ll c[109];
struct node{
	ll dis,i;
	bool operator > (node y)const{
		return dis>y.dis;
	}
};
ll dis[10209];
bool vis[10209];
ll prim(int nn,int ksd){
	for(int i=1;i<=nn;i++){
		vis[i]=0;
		dis[i]=999999999999;
	}
	ll sum=0;
	priority_queue<node,vector<node>,greater<node> >pq;
	while(!pq.empty())pq.pop();
	pq.push({0,1});
	dis[1]=0;
	while(!pq.empty()&&ksd){
		if(vis[pq.top().i]){
			pq.pop();
			continue;
		}
		ksd--;
		node cur=pq.top();
		sum+=cur.dis;
		vis[cur.i]=1;
		pq.pop();
		for(pair<int,int>j:a[cur.i].s){
			if(dis[j.first]>j.second){
				dis[j.first]=j.second;
				pq.push({j.second,j.first});
			}
		}
	}
	/*for(int i=1;i<=nn;i++){
		sum+=bey[i];
		cout<<bey[i]<<" ";
	}*/
	return sum;
} 
ll res;
void dfs(int cur,ll sud,int dfl){
	if(sud>=res)return ;
	if(cur==k+1){
		res=min(res,prim(k+n,n+dfl)+sud);
		return;
	}
	dfs(cur+1,sud,dfl);
	for(int i=1;i<=n;++i){
		a[i].s.push_back(make_pair(cur+n,b[cur][i]));
		a[cur+n].s.push_back(make_pair(i,b[cur][i]));
	}
	dfs(cur+1,sud+c[cur],dfl+1);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	res=9999999999999;
	for(ll i=1,x,y,z;i<=m;i++){
		scanf("%d%d%lld",&x,&y,&z);
		a[x].s.push_back(make_pair(y,z));
		a[y].s.push_back(make_pair(x,z));
	}
	if(k==0){
		cout<<prim(n,n);
		return 0;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&b[i][j]);
		}
	}
	dfs(1,0,0);
	printf("%lld",res);
	return 0;

}

