#include<bits/stdc++.h>
using namespace std;
long long a[210][10],dp[210][210][210],q[300010],w[100010],e[100010],n,t,mx,x,y,z;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		mx=0;
		cin>>n;
		if(n<=200){
			memset(dp,0,sizeof(dp));
			for(long long i=1;i<=n;i++){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
			}	
			if(n==2){
				cout<<max(max(max(a[1][1]+a[2][2],a[1][1]+a[2][3]),a[1][2]+a[2][1]),max(a[1][2]+a[2][3],max(a[1][3]+a[2][1],a[1][3]+a[2][2])))<<"\n";
				continue;
			}
			for(long long i=1;i<=n;i++){
				for(long long k=1;k<=i;k++) dp[i][0][k]=max(dp[i-1][0][k-1]+a[i][2],dp[i-1][0][k]+a[i][3]);
				for(long long j=1;j<=i;j++) dp[i][j][0]=max(dp[i-1][j-1][0]+a[i][1],dp[i-1][j][0]+a[i][3]);
				for(long long j=1;j<=min(i,n/2);j++){
					for(long long k=1;k<=min(i,n/2);k++){
						if(i-j-k>n/2) continue;
						dp[i][j][k]=max(max(dp[i-1][j][k-1]+a[i][2],dp[i-1][j][k]+a[i][3]),dp[i-1][j-1][k]+a[i][1]);
					}
				}
			}
			for(long long i=0;i<=n/2;i++){
				for(long long j=0;j<=n/2;j++){
					if(n-i-j>n/2) continue;
					mx=max(mx,dp[n][i][j]);
				}
			}
			cout<<mx<<"\n";
		}
		else{
			x=0;
			y=0;
			z=0;
			for(long long i=1;i<=n;i++){
				cin>>q[i]>>w[i]>>e[i];
				x=max(x,q[i]);
				y=max(y,w[i]);
				z=max(z,e[i]);
			}
			if(y==0&&z==0){
				sort(q+1,q+n+1);
				x=0;
				for(long long i=n;i>n/2;i--){
					x+=q[i];
				}
				cout<<x<<"\n";
			}
			else if(z==0){
				sort(q+1,q+n+1);
				sort(w+1,w+n+1);
				x=0;
				for(long long i=n;i>n/2;i--){
					x+=q[i];
					x+=w[i];
				}
				cout<<x<<"\n";
			}
			else{
				for(long long i=1;i<=n;i++){
					q[i+n]=w[i];
				}
				for(long long i=1;i<=n;i++){
					q[i+n+n]=e[i];
				}
				x=0;
				sort(q+1,q+n+n+n+1);
				for(long long i=n*3;i>n*2;i--){
					x+=q[i];
				}
				cout<<x<<"\n";
			}
		}	
	}
	
	return 0;
}