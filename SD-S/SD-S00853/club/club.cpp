#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100100][5],f[300][300][300],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			for(int j=min(n/2,i);j>=0;j--){
				for(int k=min(n/2,i-j);k>=0;k--){
					for(int l=min(n/2,i-j-k);l>=0;l--){
						f[j+1][k][l]=max(f[j+1][k][l],f[j][k][l]+a[i][1]);
						f[j][k+1][l]=max(f[j][k+1][l],f[j][k][l]+a[i][2]);
						f[j][k][l+1]=max(f[j][k][l+1],f[j][k][l]+a[i][3]);
					}
				}
			}
		}
		for(int j=n/2;j>=0;j--){
			for(int k=n/2;k>=0;k--){
				ans=max(ans,f[j][k][n-j-k]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
