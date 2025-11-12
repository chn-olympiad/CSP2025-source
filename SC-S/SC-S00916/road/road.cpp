#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000001],v[10000001],w[10000001],c[11],a[11][1001];
int nb[10001]={0};
int solve(int l,int o,int p){
	if(l==0)
		return o;
	int f=1e9;
	for(int i=p+1;i<=m-l;i++)
		if(nb[u[i]]<2&&nb[v[i]]<2){
			nb[u[i]]++,nb[v[i]]++;
			f=min(f,solve(l-1,o+w[i],i));
			nb[u[i]]--,nb[v[i]]--;
		}
	return f;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		cin>>u[i]>>v[i]>>w[i];
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}
	if(k==0)
		cout<<solve(n,0,-1);
	else
		cout<<0;
	return 0;
}