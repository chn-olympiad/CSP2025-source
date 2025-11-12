#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e4+50;
int n,m,k,ans,cnt=0;
struct edge{
	int from,to,w;
	friend bool operator<(edge a,edge b){
		return a.w>b.w;
	}
};
struct node{
	int fz;
}mp[maxn];
struct va{
	int c,r[maxn];
}vi[15];
priority_queue<edge> pq;
int findx(int x){
	if(mp[x].fz==x){
		return x; 
	}
	return mp[x].fz=findx(mp[x].fz);
}
void add(int x,int y,int w){
	int rx=findx(x),ry=findx(y);
	if(rx==ry){
		return ;
	}
	cnt++;
	ans+=w;
	mp[rx].fz=ry;
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		edge x;
		cin>>x.from>>x.to>>x.w;
		pq.push(x);
	}
	for(int i=1;i<=k;i++){
		cin>>vi[i].c;
		for(int j=1;j<=n;j++){
			cin>>vi[i].r[j];
			edge x;
			x.from=n+i,x.to=j,x.w=vi[i].r[j];
			pq.push(x);
		}
	}
	for(int i=1;i<=n+11;i++){
		mp[i].fz=i;
	}
	while(!pq.empty()){
		edge x=pq.top();
		pq.pop();
		add(x.from,x.to,x.w);
		if(cnt==n+k-1){
			break;
		}
	}
	cout<<ans;
	return 0;
}