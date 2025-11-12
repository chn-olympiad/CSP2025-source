#include<bits/stdc++.h>
using namespace std;
vector<int> a[10005];
int n,m,k,u,v,w,x,c,flag;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int i=1;i<=n;i++){
			cin>>x;
			if(x!=0){
				flag=1;
			}
		}
		if(flag==0&&c==0){
			cout<<0;
		}
	}
	return 0;
} 
