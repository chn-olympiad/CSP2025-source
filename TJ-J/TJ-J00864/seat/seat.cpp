#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
	int n,m;
	int mp[105][105];
	int mx=-1;
	int ans[105][105];
	int a[105][105];
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]>mx){
				mx=a[i][j];
				if(mx==100){
					ans[i][j]=mp[i][j++];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<ans[i][j];
		}
	}
	return 0;
}
