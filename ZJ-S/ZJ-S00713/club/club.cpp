#include<bits/stdc++.h>
using namespace std;
int n;
int a[100025][5];
long long t[25][25][25]={0};
void getans(){
	memset(t,0,sizeof(t));
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++) cin>>a[i][j];
	}for(int i=1;i<=n;i++){
		for(int j=n/2;j>=0;j--){
			for(int k=n/2;k>=0;k--){
				for(int l=n/2;l>=0;l--){
					if(j+k+l>n) continue;
					if(j>0) t[j][k][l]=max(t[j][k][l],t[j-1][k][l]+a[i][1]);
					if(k>0) t[j][k][l]=max(t[j][k][l],t[j][k-1][l]+a[i][2]);
					if(l>0) t[j][k][l]=max(t[j][k][l],t[j][k][l-1]+a[i][3]);
				}
			}
		}
	}long long ans=0;
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			if(i+j<n/2) continue;
			ans=max(ans,t[i][j][n-i-j]);
		}
	}cout<<ans<<endl;
}int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int x=1;x<=t;x++) getans();
	return 0;
}
