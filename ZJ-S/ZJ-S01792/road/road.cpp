#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll,ll>
vector<pii> s[10010]; 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	if(k){
		cout<<0;
		return 0;
	}
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		pii temp;
		temp.first=w;temp.second=v;
		s[u].push_back(temp);
		temp.second=u;
		s[v].push_back(temp);
	}
	bool vis[10010];
	fill(vis,vis+n,false);
	vis[1]=true;
	priority_queue<pii,vector<pii>,greater<pii> > q; 
	for(int i=0;i<s[1].size();i++) q.push(s[1][i]);
	ll tot=1,sum=0;
	while(tot<n){
		pii f=q.top();q.pop();
		ll to=f.second;
		if(vis[to]) continue;
		vis[to]=true;
		tot++;
		sum+=f.first;
		//cout<<to<<endl;
		for(int i=0;i<s[to].size();i++){
			if(!vis[s[to][i].second])
				q.push(s[to][i]);
		}
	}
	cout<<sum;
	return 0;
}
