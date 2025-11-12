//张巍邺-SN-J00223-西安市曲江第一中学
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10,K=20;
typedef pair<int,int> PII;
vector<PII> a[N];
int dist[N];
int ans;
int n,m,k;
bool st[N];
void di() {
	memset(dist ,0x7f,sizeof dist);
	memset(st ,false,sizeof st);
	priority_queue<PII,vector<PII>,greater<PII> >q;
	int cnt=0;
	dist[1]=0;
	q.push({0,1});
	while(q.size()) {

		PII p = q.top();
		q.pop();
		int u = p.second;
		if(st[u]) {
			continue;
		}
		st[u]=true;
		for(int i = 0; i<a[u].size(); i++) {
			int v =a[u][i].first;
			int w= a[u][i].second;
//			cout <<v<<" "<<w<<"   ";
			if(dist[v]>dist[u]+w&&cnt!=n-1) {
				dist[v]=dist[u]+w;
				cnt++;
				ans+=w;
				q.push({cnt,v});
			}
		}

	}
	if(cnt==n-1) {
		return;
	}

}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin >> n >> m >>k;
	for(int i = 1; i<=m; i++) {
		int u,v,w;
		cin >> u >> v >>w;

		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
//	for(int i = 1; i<=m; i++) {
//		for(int j = 0; j<a[i].size(); j++) {
//			int v =a[i][j].first;
//			int w= a[i][j].second;
//			cout <<v<<" "<<w<<"   ";
//
//		}
//	}
//	for(int j = 1; j<=k; j++) {
//		for(int i = 1;i<=n; i++){
//			cin >> w[j];
//			cin >> c[j][i];
//		}
//	}

	di();



	cout <<ans;
//	4 4 0
//	1 4 6
//	2 3 7
//	4 2 5
//	4 3 4
	return 0;
}
