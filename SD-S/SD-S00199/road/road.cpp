#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000005],w[1000005],v[1000005];
int c[1000005],a[10005][10005];
bool b[1000005];
int cnt=1;
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i]>>a[i][j];
		} 
	}
	if(k==0){
		for(int i=1;i<=m;i++){
			cnt+=w[i];
		}
		for(int i=1;i<=m;i++){
			for(int j=2;j<=m;j++){
				if(u[i]==u[j]&&i!=j||u[i]==v[j]||v[i]==u[j]&&i!=j){
					int maxn=max(w[i],w[j]);
					cnt-=maxn;
				}
			}
			
		}
		cout<<cnt;
	}
	return 0;
}
