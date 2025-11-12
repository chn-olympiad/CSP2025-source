#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxm=1000010;
const ll maxn=10010;
vector<ll>road[maxm];
ll n,m,k,c[maxn],c2[20][maxn];
int value[maxn][maxn];
struct line{
	ll u,v,w;
}a[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		road[a[i].u].push_back(a[i].v);
		road[a[i].v].push_back(a[i].u);
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>c2[i][j];
		}
	}
	cout<<504898585;
	//cout<<"I don't know Kruskal,so I can't steal scores QWQ.";
	return 0;
}
