#include<bits/stdc++.h>
#define int long long
#define I ios_base::sync_with_stdio(0);
#define AK cin.tie(0);
#define CSP cout.tie(0);
#define endl '\n'
using namespace std;
const int maxn=1001010;  
struct node{int to,w;};
struct qnode{
	int to,w;
	qnode(int too,int ww){to=too; w=ww;}
	friend bool operator <(qnode q1,qnode q2){
		return q1.w>q2.w;
	}
};
vector<node> vi[maxn];
int a[11][maxn];int c[11];
int n,m,k; bool vis[maxn]; int ki=0;
int prim(){
	int ans=0;
	priority_queue<qnode> q; 
	vis[1]=true; ki++;
	for(int i=0;i<vi[1].size();i++){
		q.push({vi[1][i].to,vi[1][i].w});
	}
	while(!q.empty()){
		if(ki==n)break;
		qnode qn=q.top(); q.pop(); 
		if(vis[qn.to])continue;
		vis[qn.to]=true; ki++; ans+=qn.w;
		for(int i=0;i<vi[qn.to].size();i++){
			q.push({vi[qn.to][i].to,vi[qn.to][i].w});
		}
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	I AK CSP 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,wi; cin>>u>>v>>wi;
		vi[u].push_back({v,wi});
		vi[v].push_back({u,wi});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				vi[j].push_back({k,a[i][j]+a[i][k]});
				vi[k].push_back({j,a[i][j]+a[i][k]});
			}
		}
	}
	cout<<prim();
	return 0;
}