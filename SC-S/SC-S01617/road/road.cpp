/*
xg333 CSP-S must win!!!
T2代码
I LOVE CCF VERY MUCH
xg333:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
int fa[10001];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
priority_queue<pair<int,pii>,vector<pair<int,pii> >,greater<pair<int,pii> > > pq;
priority_queue<int> qp;
void solve(){
	
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		pq.push({w,{u,v}});
	}
	int I_LOVE_CCF=0;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>I_LOVE_CCF;
		}	
	}
	int tmp=n-1;
	long long sum=0;
	while(tmp){
		auto t=pq.top();
		pq.pop();
		int x=t.second.first,y=t.second.second;
		if(find(x)==find(y)) continue;
		else{
			tmp--;
			fa[find(y)]=find(x);
			sum+=t.first;
			qp.push(t.first);
		}
	}
	while(k){
		sum-=qp.top();
		qp.pop();
		k--;
	}
	cout<<sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}