#include<bits/stdc++.h>
using namespace std;
struct S{
	long long a,b;
};
struct SS{
	long long a,b,c;
	bool operator <(const SS &x)const{
		if(b==x.b){
			return c<x.c;
		}
		return b>x.b;
	}
};
set<long long> s;
priority_queue<SS> q;
vector<S> v[100005];
long long n,m,cnt,k,z[11][100005];bool vis[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=0,a,b,c;i<m;i++){
		cin>>a>>b>>c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	for(long long i=1;i<=n;i++)s.insert(i);
	for(long long i=1;i<=k;i++){
		cin>>z[i][0];
		for(long long j=1;j<=n;j++){
			cin>>z[i][j];
		}
	}
	memset(vis,0,sizeof(vis));
	q.push({1,0,0});
	long long x,y,o;
	while(!q.empty()){
		x=q.top().a;
		y=q.top().b;
		o=q.top().c;
		q.pop();
		if(vis[x]==1)continue;
		vis[x]=1;
		cnt+=y;
		auto pos=lower_bound(s.begin(),s.end(),x);
		s.erase(pos);
		if(o!=0){
			z[o][0]=0;
		}
		long long h;
		for(long long i:s){
			h=1;
			for(long long j=1;j<=k;j++){
				if(z[h][i]+z[h][0]+z[h][x]>z[j][i]+z[j][0]+z[j][x]){
					h=j;
				}
			}
			for(long long j=1;j<=k;j++){
				if(z[h][i]+z[h][0]+z[h][x]==z[j][i]+z[j][0]+z[j][x]){
					q.push({i,z[j][i]+z[j][0]+z[j][x],j});
				}
			}
		}
		for(auto i:v[x]){
			if(vis[i.a]==0){
				q.push({i.a,i.b,0});
			}
		}
	}
	cout<<cnt;
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