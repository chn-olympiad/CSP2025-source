#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[int(1e4+1)],to[5][int(1e4+1)];
struct l{
	vector<pair<int,int> >v;
}f[int(1e4+1)];
void dij(){
	priority_queue<pair<int,int> >que;
	int piont=que.top()->first;
	int w=que.top()->second;
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int s,e,c;
		cin>>s>>e>>c;
		f[s].v.push_back(make_pair(e,c));
		f[e].v.push_back(make_pair(s,c));
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>to[i][j];
		}
	}
	dij();
}
