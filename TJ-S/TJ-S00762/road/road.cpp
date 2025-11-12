#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000105],v[1000105],w[1000105],c[15],a[15][100005],l[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		l[i]=10000;
	}
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			
			cin>>a[i][j];
			l[j]=min(l[j],a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<l[i]<<endl;
	}
	if(k==0){
		int sum=0,k=0;
		int o[100005]={0};
		for(int i=1;i<=n;i++){
			int maxn=10000;
			if(o[i]==0){
				for(int j=1;j<=m;j++){
					if(u[j]==i||v[j]==i){
						if(maxn>w[j]){
							k=j;
							maxn=w[j];
						}
						
					}
				}
				o[u[k]]=1;
				o[v[k]]=1;
				sum+=maxn;
			}
		}
		cout<<sum<<endl;
	}else{
		int sum=0,k=0;
		int o[100005]={0};
		for(int i=1;i<=n;i++){
			int maxn=10000;
			if(o[i]==0){
				for(int j=1;j<=m;j++){
					if(u[j]==i||v[j]==i){
						if(maxn>w[j]){
							k=j;
							maxn=w[j];
						}
						
					}
				}
				o[u[k]]=1;
				o[v[k]]=1;
				sum+=maxn;
			}
		}
		cout<<sum<<endl;
	}
	
	
	
	return 0;
} 
