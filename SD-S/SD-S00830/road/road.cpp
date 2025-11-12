#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,v,a[105],b[105],k[105],g[105][105],maxx=0;
	cin>>n>>m>>v;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>k[i];
		maxx=max(maxx,k[i]);
	}
	for(int i=1;i<=v;i++){
		for(int j=1;j<=m+1;j++){
			cin>>g[i][j];
		}
	}
	for(int i=1;i<=v;i++){
		if(g[i][1]>=maxx){
			g[i][1]=-1;
		}
		if(g[i][1]==0){
			cout<<0;
			return 0;
		}
	}
	long long ans=0,cnt=0x9f;
	for(int i=1;i<=n;i++){
		cnt=k[i];
		for(int j=1;j<=v;j++){
//			if(g[j][1]=-1){
//				break;
//			}
			cnt=min(cnt,g[j][1]+g[j][a[i]+1]+g[j][b[i]+1]);
//			cout<<g[j][1]+g[j][a[i]+1]+g[j][b[i]+1]<<" ";
		}
		cout<<cnt;
		ans+=cnt;
	}
	cout<<endl<<ans;
	return 0;
}
