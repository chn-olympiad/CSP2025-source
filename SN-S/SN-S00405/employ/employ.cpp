#include<bits/stdc++.h>
#define p 998244353
#define ll long long
using namespace std;
ll n,m,a[505],c[505],A[505][505],C[505][505],s[505],dp[2][505][505],u=0,v=1,ans;//前i天,总共有j个没被录取，有k个没填，h个1变0 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		a[i]=x-'0';
	}
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			C[i][j]%=p;
		}
	}
	A[0][0]=1;
	for(int i=1;i<=n;i++){
		A[i][0]=1;
		for(int j=1;j<=i;j++){
			A[i][j]=A[i][j-1]*(i-j+1);
			A[i][j]%=p;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		s[c[i]]++;
	}
	for(int i=1;i<=n;i++){
		s[i]+=s[i-1];
	}
	dp[u][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			for(ll k=0;k<=i;k++){
				if(dp[u][j][k]==0){
					continue;
				}
				//cout<<i<<" "<<j<<" "<<k<<" "<<h<<" "<<dp[i][j][k][h]<<endl;
				int h=s[j]+k-i;
				if(h!=0){
					for(int o=0;o<=min(k,s[j+1]-s[j]);o++){
						dp[v][j+1][k-o]+=((((dp[u][j][k]*C[s[j+1]-s[j]][o])%p)*h)%p)*A[k][o];
						dp[v][j+1][k-o]%=p;
					}
				}					
				if(a[i+1]==0){
					for(int o=0;o<=min(k+1,s[j+1]-s[j]);o++){
						dp[v][j+1][k+1-o]+=((dp[u][j][k]*C[s[j+1]-s[j]][o])%p)*A[k+1][o];
						dp[v][j+1][k+1-o]%=p;
					}
				}
				else{
					dp[v][j][k+1]+=dp[u][j][k];
					dp[v][j][k+1]%=p;
				}
				dp[u][j][k]=0;
			}
		}
		swap(u,v);
	}
	for(int j=0;j<=n-m;j++){
		for(int k=0;k<=n;k++){
			int h=s[j]+k-n;
			if(h!=0){
				continue;
			}
			ans+=dp[u][j][k]*A[k][k];
			ans%=p;
		}
	}
	cout<<ans<<endl;
}
