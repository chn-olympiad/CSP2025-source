#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+15,M=2e6+5;
struct node{
	ll to,val;
	bool operator< (const node &a)const{
		return val>a.val;
	}
};
int a[11][N],n,k,m,c[11],flag[N];
ll ans,dis[N];
priority_queue<node> que;
vector<node>vec[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,val;i<=m;i++){
		cin>>u>>v>>val;
		vec[u].push_back((node){v,val});
		vec[v].push_back((node){u,val});
	}
	ll checka=0ll;
	for(int i=1;i<=k;i++){
		cin>>c[i],checka+=c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			vec[j].push_back((node){n+i,a[i][j]+c[i]});
			vec[n+i].push_back((node){j,a[i][j]});
		}
	}
	memset(dis,-1,sizeof dis);
	que.push((node){1,0ll});
	int has=0;
	while(!que.empty()&&has<n){
		node now=que.top();
		que.pop();
		if(flag[now.to])continue;
//		cout<<now.to<<'\n';
		flag[now.to]=1,ans+=now.val;
		if(now.to<=n)has++;
//		cout<<vec[now.to].size()<<'\n';
		for(int i=0;i<vec[now.to].size();i++){
			int ne=vec[now.to][i].to;
			if(flag[ne])continue;
			if(dis[ne]>vec[now.to][i].val||dis[ne]==-1){
				dis[ne]=vec[now.to][i].val;
				que.push((node){ne,dis[ne]});
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
