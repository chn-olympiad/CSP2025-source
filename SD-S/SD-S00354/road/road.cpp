#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long
#define fir first
#define sec second
#define pb push_back
#define MaxN 10005
#define MaxM 1000005
using namespace std;
struct Edge{
	ll v,w;
};
ll n,m,k,u,v,w,tmp,c[MaxN],a[10][MaxN],fa[MaxN]
vector<Edge>e[MaxM];
void addEdge(ll _u,ll _v,ll _w){
	e[_u].pb({_v,_w});
	e[_v].pb({_u,_w});
}
void kruskal(){
	for(ll i=1;i<=n;i++)fa[i]=i;
}
int main(){
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++)cin>>u>>v>>w,addEdge(u,v,w);
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++)cin>>a[i][j];
	}
	return 0;
}

