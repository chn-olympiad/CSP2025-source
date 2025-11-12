#include<bits/stdc++.h>
using namespace std;
int n,m,k,cntw;
struct r{
	int u,v,w;
}a[1000007];
bool cmp(r p,r q){
	if(p.u==q.u)return p.v<q.v;
	else return p.u<q.u;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		cntw+=a[i].w;
	}
	if(n==m-1){
		cout<<cntw;
		return 0;
	}
	
	return 0;
}

