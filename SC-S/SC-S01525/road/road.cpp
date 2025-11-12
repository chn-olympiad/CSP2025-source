#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int>>> e;
int f[100005];

int fa(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=fa(f[x]);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		e.push_back({z,{x,y}});
	}
	int i=0,ans=0;
	sort(e.begin(),e.end());
	while(n!=1){
		int u=fa(e[i].second.first);
		int v=fa(e[i].second.second);
		if(u!=v){
			f[u]=f[v];
			n--;
			ans+=e[i].first;
		}
		i++;
	}
	cout<<ans;
	return 0; 
}
//16