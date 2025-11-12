#include<bits/stdc++.h> 
using namespace std;
int n,m,a[2000][2000],s,e,w,ans,g,h,d[100000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>g;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=9999999;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>s>>e>>w;
		a[s][e]=w;
		a[e][s]=w;
	}
	for(int i=1;i<=g;i++){
		cin>>h;
		for(int j=1;j<=n;j++){
			cin>>d[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i!=j&&i!=k&&j!=k){
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)
				ans=max(ans,a[i][j]);
        }
    }
    cout<<ans;
    return 0;
}