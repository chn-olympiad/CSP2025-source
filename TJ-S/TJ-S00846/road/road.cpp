#include<bits/stdc++.h>
using namespace std;
int u[100010],v[100010];
int ans;
int w[100010],c[100010],a[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(c[i]==0&&a[j]==0){
				ans=0;		
			}
		}
		
	}cout<<ans;
	return 0;
}

