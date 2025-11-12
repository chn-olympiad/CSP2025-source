#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PQ priority_queue
#define ump unordered_map
#define inf 0x3f3f3f3f
using namespace std;
const int N=4e6+10;
struct AC{
	int u,v;
	ll w;
}g[N];
bool cmp(AC x,AC y){
	return x.w<y.w;
}
int h[N];
int n,m,k,idx;
ll ans;
int p[N],cnt,num;
int find(int x){
	if(x!=p[x]) return p[x]=find(p[x]);
	return p[x];
}
bool merge(int a,int b){
	int pa=find(a),pb=find(b);
	if(pa!=pb){
		p[pa]=pb;
		return true;
	}
	return false;
}
void kelusikaer(){
	for(int i=1;i<=idx;i++){
		if(merge(g[i].u,g[i].v)){
			ans+=g[i].w;
			cnt++;
		}
		if(cnt==n-1) return;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) p[i]=i;
	for(int i=1;i<=m;i++){
		idx++;
		cin>>g[idx].u>>g[idx].v>>g[idx].w;
	}
	int flag=1;
	for(int i=1;i<=k;i++){
		ll c;
		cin>>c;
		h[n+i]=c;
		if(c!=0) flag=0;
		for(int j=1;j<=n;j++){
			ll x;
			cin>>x;
			if(x!=0) flag=0;
			idx++;
			g[idx].u=n+i;
			g[idx].v=j;
			g[idx].w=x;
		}
	}
	if(flag&&k){
		cout<<0;
		return 0;
	}
	sort(g+1,g+idx+1,cmp);
	kelusikaer();
	cout<<ans;
	
	
	return 0;
} 
