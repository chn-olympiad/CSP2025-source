#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10,mod=998244353;

ll n,m,k,ans,cnt;
ll f[N],v,w[N];

struct node{
	ll u,v,w,t;
}a[N];
bool cmp(node a,node b){
	return a.w+a.t<b.w+b.t;
}

ll find(ll x){
	if(f[x]==x) return x;
	else f[x]=find(f[x]);
}
void merge(ll x,ll y){
	x=find(x);
	y=find(y);
	f[x]=y;
}
void kul(){
	for(int i=1;;i++){
		if(cnt==n-1) return;
		if(find(a[i].u)!=find(a[i].v)&&a[i].u!=a[i].v){
			ans+=a[i].w+a[i].t;
			merge(a[i].u,a[i].v);
			cnt++;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(),cout.tie();
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>v;
		for(int j=1;j<=n;j++){
			cin>>w[j];
			if(i==j) continue;
			a[++m].u=i,a[m].v=j,a[m].w=w[j],a[m].t=v+w[i];
		}
	}
	sort(a+1,a+1+m,cmp);
	kul();
	cout<<ans;
	return 0;
}


