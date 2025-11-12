#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+100,M=1.1e6+10;
int c[15],f[N];
int fa(int p){
	if(f[p]==p)return p;
	return fa(f[p]);
}
bool b[15]={1};
struct node{
	int u,v,w;
	bool operator<(const node a)const{
		return a.w>w;
	}
}pq[M];
int n,m,k;
ll ans=1e18;
void dfs(int p){
	if(p<=k){
		b[p]=1;
		dfs(p+1);
		b[p]=0;
		dfs(p+1);
		return;
	}
	ll sum=0;
	int ni=n-1;
	for(int i=1;i<=k;i++){
		if(b[i]){
			sum+=c[i];
			ni++;
		}
	}
	memset(f,0,sizeof(f));
	for(int i=1;i<=n+10;i++){
		f[i]=i;
	}
	int i=1;
	while(ni){
		ni--;
		while(fa(pq[i].u)==fa(pq[i].v)||!b[max(pq[i].u-n,0)])i++;
		f[fa(pq[i].u)]=fa(pq[i].v);
		sum+=pq[i].w;
		i++;
	}
	ans=min(ans,sum);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	int ui,vi,wi,ai;
	for(int i=1;i<=m;i++){
		cin>>ui>>vi>>wi;
		pq[i]={ui,vi,wi};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int o=1;o<=n;o++){
			cin>>ai;
			pq[m+(i-1)*n+o]={i+n,o,ai};
		}
	}
	sort(pq+1,pq+m+k*n+1);
	dfs(1);
	cout<<ans;
	return 0;
}