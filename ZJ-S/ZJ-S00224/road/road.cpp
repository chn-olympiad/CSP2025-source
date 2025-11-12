#include <bits/stdc++.h>
#define fr1(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
using namespace std;
const int maxn=1e4+10,INF=0x3f3f;
int n,m,k;
long long ans=0;
bool visit[maxn];
struct way {
	long long u,w,v;
};
vector<int> link[maxn];
queue<int> vis;
bool check() {
	vis.push(1);
	memset(visit,0,sizeof visit);
	visit[1]=1;
	while(!vis.empty()) {
		int p=vis.front();
		vis.pop();
		for(int x:link[p])if(!visit[x])visit[x]=1,vis.push(x);
	}
	fr1(i,1,n)if(!visit[i])return 0;
	return 1;
}
operator > (way a,way b) {
	return a.v>b.v;
}
priority_queue<way,vector<way>,greater<way>> q;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	way p;
	fr1(i,1,m) {
		cin>>p.u>>p.w>>p.v;
		q.push(p);
	}
	while(!q.empty()) {
		p=q.top();
		q.pop();
		ans+=p.v;
		link[p.u].push_back(p.w),link[p.w].push_back(p.u);
		if(check())break;
	}
	if(k==0)cout<<ans;
	else {
		long long mina=0x3f3f3f3f;
		fr1(i,1,k) {
			cin>>p.v;
			mina=min(mina,p.v);
			fr1(j,1,n)cin>>p.v;
		}
		cout<<min(mina,ans);
	}
	return 0;
}
