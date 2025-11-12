#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Roads{
	ll begin;
	ll end;
	ll weight;
}r[1000010];


ll n,m,k,ans2=1e18;
vector< pair<ll,ll> > t[10010];
ll c[20];
ll _c[20][10010];
//bool vis[1000010];
vector<Roads> v;
ll p=1;
bool visn[10010];

ll read(){
	char c=getchar();
	ll res=0;
	while('0'<=c && c<='9'){
		res=res*10+(c-'0');
		c=getchar();
	}
	return res;
}

void s1(){
	cout << "0";
}

void dfs(ll x){
	if(x>m){
		ll cnt=0;
		
		memset(visn,0,sizeof(visn));
		for(int i=0;i<v.size();i++){
			visn[v[i].begin]=1;
			visn[v[i].end]=1;
			cnt+=v[i].weight;
		}
		for(int i=1;i<=n;i++){
			if(visn[i]==0) return;
		}
		ans2=min(cnt,ans2);
		return;
	}
	dfs(x+1);
	v.push_back(r[x]);
	dfs(x+1);
	v.pop_back();
}

void s2(){
//	memset(vis,0,sizeof(vis));
	ans2=1e18;
	dfs(1);
	cout << ans2;
}

//void s3(){
//	cout << sum;
//}

int main() {
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		ll v=read(),u=read(),w=read();
		t[v].push_back({u,w});
		r[i].begin=v;
		r[i].end=u;
		r[i].weight=w;
//		sum+=w;
	}
	bool flag=1;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]!=0) flag=0;
		for(int j=1;j<=n;j++){
			_c[i][j]=read();
			if(_c[i][j]!=0) flag=0;
		}
	}
	if(flag && k!=0) s1();
	else s2();
	return 0;
}
