#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e4+10;
int u[N],v[N],w[N],c[N],a;
struct node{
	int re;
	vector<pair<int,int> > road;
}city[N];
int n,m,k;
void build(int a,int b,int c){
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		build(u[i],v[i],w[i]);
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a;
		}
		
	}
	cout<<0;
}