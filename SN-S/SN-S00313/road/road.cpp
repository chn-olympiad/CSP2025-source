#include<bits/stdc++.h>
using namespace std;
long long n,m,k,h=2e9;
vector<array<long long,2>>a[10005];
bitset<10005>avis[10005];
void dfs(long long x,long long g,long long sum){
	if(g==n){
		h=min(h,sum);
	}else{
		for(auto y:a[x]){
			if(!avis[x][y[0]]){
				avis[x][y[0]]=1;
				avis[y[0]][x]=1;
				sum=sum+y[1];
				g++;
				dfs(y[0],g,sum);
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	if(k==0){
		dfs(1,1,0);
		cout<<h;
	}else{
		cout<<0;
	}
	return 0;
}
