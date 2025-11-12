#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
struct node{
	long long to,val;
};
struct node1{
	long long id,val;
	bool operator < (const node1 & a) const {
		return val > a.val;
	}
};
long long dis[11000],book[11000],A[11000],G[11000];
vector <node> V[11000];
priority_queue <node1> Q;
long long kur(){
	long long ans=0,i;
	node1 cun;
	dis[1] = 0;
	Q.push((node1){1,0});
	while(!Q.empty()){
		cun = Q.top();
		Q.pop();
		if(book[cun.id] == 1){
			continue;
		}
		ans += dis[cun.id];
		dis[cun.id] = 0;
		book[cun.id] = 1;
		for(i = 0;i < V[cun.id].size();i++){;
			if(book[V[cun.id][i].to] == 1){
				continue;
			}
			if(dis[V[cun.id][i].to] > dis[cun.id] + V[cun.id][i].val){
				dis[V[cun.id][i].to] = dis[cun.id] + V[cun.id][i].val;
				Q.push((node1){V[cun.id][i].to,dis[V[cun.id][i].to]});
			}
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,i,u,v,w,inf = 1e18,c,cc=0,ans = 0,j,o,cun;
	cin>>n>>m>>k;
	for(i = 1;i <= m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		V[u].push_back((node){v,w});
		V[v].push_back((node){u,w});
	}
	for(i = 1;i <= n;i++){
		dis[i] = inf;
		book[i] = 0;
	}
	ans = kur();
	for(i = 1;i <= k;i++){
		scanf("%lld",&c);
		cc += c;
		while(!Q.empty()){
			Q.pop();
		}
		for(j = 1;j <= n;j++){
			scanf("%lld",&A[j]);
			dis[j] = inf;
			book[j] = 0;
		}
		for(j = 1;j <= n;j++){
			for(o = j+1;o <= n;o++){
				V[j].push_back((node){o,A[j]+A[o]});
				V[o].push_back((node){j,A[j]+A[o]});
			}
		}
		cun = kur();
		cun += cc;
		if(cun > ans){
			for(j = 1;j <= n;j++){
				for(o = j+1;o <= n;o++){
					V[j].pop_back();
					V[o].pop_back();
				}
			}
			cc -= c;
		}else{
			ans = cun;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}//48-60pts
