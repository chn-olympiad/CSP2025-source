#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct N{
	int u,v,w;
};
vector<N>e[1000005];
int c,a[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;int ans=0;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		e[a].push_back(N{b,c});
		e[b].push_back(N{a,c});
		ans+=c;
	}
	cin>>c;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<ans;
	return 0;
} 
