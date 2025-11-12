#include<bits/stdc++.h>
using namespace std;
vector<int>a[114514];
int u[114514],v[114514],w[114514],n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		a[u[i]][v[i]]=w[i];
	}
}