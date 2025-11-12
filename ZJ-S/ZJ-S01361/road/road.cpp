#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[11][10001],c[11],v[1000001],s=1e9;
vector <int> e[1000001],w[1000001];
void f(int t,int o){
	int fl=1;
	for(int i=1;i<=n;i++){
		if(!v[i]){
			fl=0;
			break;
		} 
	}
	if(fl) s=min(s,o);
	for(int i=0;i<e[t].size();i++){
		if(!v[e[t][i]]){
			v[e[t][i]]=1;
			f(e[t][i],o+w[t][i]);
			v[e[t][i]]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,p;
		cin>>u>>v>>p;
		e[u].push_back(v);
		e[v].push_back(u);
		w[u].push_back(p);
		w[v].push_back(p);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	v[1]=1;
	f(1,0);
	cout<<s;
	return 0;
}
