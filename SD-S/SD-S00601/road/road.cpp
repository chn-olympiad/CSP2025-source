#include<bits/stdc++.h>
#define pii pair<int,int> 
using namespace std;
int n,m,k,fa[10010];
int Find(int x){
	if(fa[x]!=x)return fa[x]=Find(fa[x]);
	return x;
}
priority_queue<pair<int,pii > >q;
long long ans=0;
void kruskal(){
	int cnt=0;
	while(cnt<n-1){
		int tmp=-q.top().first;
		q.pop();
		int x=q.top().second.first,y=q.top().second.second;
		if(Find(x)==Find(y))continue;
		fa[x]=y;
		cnt++;
		ans+=tmp;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i =1;i<=n;i++)fa[i]=i;
	for(int i =1,x,y,z;i<=m;i++){
		cin>>x>>y>>z;
		q.push({-z,{x,y}});
	}
	
	for(int i =1,x;i<=k;i++){
		cin>>x;
		for(int i =1;i<=n;i++)cin>>x;
	}
	kruskal();
	cout<<ans;
}
//4
//5
//0
//1 2 6
//1 3 2
//1 4 3
//2 3 7
//2 4 9
