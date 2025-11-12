#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][5],f[N][5],dp[N][5],k,d[4]; 
void ch(int a,int b,int c){
	int mx=max(a,max(b,c)),mn=min(a,min(b,c));
	if(mx==a){
		d[1]=1;
		if(c>b){
			d[2]=3;
			d[3]=2;
		}
		else{
			d[2]=2;
			d[3]=3;
		}
	}
	else{
		if(mx==b){
			d[1]=2;
			if(c>a){
				d[2]=3;
				d[3]=1;
			}
			else{
				d[2]=1;
				d[3]=3;
			}
		}
		else{
			d[1]=3;
			if(a>b){
				d[2]=1;
				d[3]=2;
			}
			else{
				d[2]=2;
				d[3]=1;
			}
		}		
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		k=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dp[1][1]=a[1][1];
		dp[1][2]=a[1][2];
		dp[1][3]=a[1][3];
		f[1][1]=f[1][2]=f[1][3]=1;
		for(int i=2;i<=n;i++){
			ch(dp[i-1][1],dp[i-1][2],dp[i-1][3]);
			for(int j=1;j<=3;j++){
				if(d[1]==j){
					if(f[i-1][j]==k){
						dp[i][j]=dp[i-1][d[2]]+a[i][j];
						f[i][j]=f[i-1][j];
					}
					else{
						dp[i][j]=dp[i-1][d[1]]+a[i][j];
						f[i][j]=f[i-1][j]+1;
					}
				}
				else{
					dp[i][j]=dp[i-1][d[1]]+a[i][j];
					f[i][j]=max(1,f[i-1][j]-1);
				}
			}
		}
		cout<<max(dp[n][3],max(dp[n][1],dp[n][2]))<<"\n";
	}
	return 0;
}
