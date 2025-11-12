#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100005;
ll a[N][4];
int f[N][4];
int uuuu;
int n;
struct node{
	int pos;ll dl;
	friend bool operator <(node _,node __){
		return _.dl>__.dl;
	}
};
node make_node(int pos,int dl){
	node rrat;
	rrat.pos=pos;rrat.dl=dl;
	return rrat;
}
priority_queue<node>q[4];
vector<pair<int,int>>g;
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=3;i++)while(!q[i].empty())q[i].pop();
	memset(a,0,sizeof a);
	memset(f,0,sizeof f);
	long long ans=0;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		g.clear();
		for(int j=1;j<=3;j++){
			g.push_back(make_pair(-a[i][j],j));
		}
		sort(g.begin(),g.end());
		for(int j=0;j<=2;j++){
			f[i][j+1]=g[j].second;
		}
	}
	for(int i=1;i<=n;i++){
		q[f[i][1]].push(make_node(i,a[i][f[i][1]]-a[i][f[i][2]]));
		ans=ans+a[i][f[i][1]];
		if(q[f[i][1]].size()>n/2){
			node u=q[f[i][1]].top();q[f[i][1]].pop();
			ans=ans-u.dl;
			int pos=u.pos;
			q[f[pos][2]].push(make_node(pos,a[pos][f[pos][2]]-a[pos][f[pos][3]]));
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)solve();
	return 0;
}

