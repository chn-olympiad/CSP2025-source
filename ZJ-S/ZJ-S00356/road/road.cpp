#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+20;
ll n,m,k,u,v,w,x,a[N];bool ct[N];
vector<pair<ll,ll> >rd[N];
struct node{
	ll c,a[N];
}tw[12];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		rd[u].push_back(make_pair(v,w));
		rd[v].push_back(make_pair(u,w));
		x+=w;
	}
	cout<<x;
	return 0;
}
//help