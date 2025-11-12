#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[1005],u[1005],v[1005],s[1005][1005],ans;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		if(u[i]>v[i])swap(u[i],v[i]);
		s[u[i]][v[i]]=w[i];
		ans+=w[i];
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;int sum=0;
		for(int j=1;j<=n;j++){
			cin>>w[j];
			for(int k=1;k<j;k++){
				int x=w[k]+w[j];
				
				if(s[k][j]>x){
					ans-=s[k][j]-x;
					s[k][j]=x;
				}else if(s[k][j]==0){
					ans+=x;
					s[k][j]=x;
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(s[i][j]&&s[j][k]&&s[i][k]){
					ans-=max(s[i][j],max(s[i][k],s[j][k]));
					if(s[i][j]>s[i][k]){
						if(s[i][j]>s[j][k])s[i][j]=0;
						else if(s[i][k]>s[j][k])s[i][k]=0;
						else s[j][k]=0;
					}else{
						if(s[i][k]>s[j][k])s[i][k]=0;
						else if(s[i][j]>s[j][k])s[i][j]=0;
						else s[j][k]=0;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}