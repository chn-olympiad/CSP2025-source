#include <bits/stdc++.h>
using namespace std;
//priority_queue<int,vector<int>,less<int> >q;
long long a[5100],dp[5100][5100],b[100000],n,c[5100];
const long long mod=998244353; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=i;j++){
//			c[i][j]=c[i][j-1]
//		}
//	}
	for(int i=3;i<=n;i++){
		for(int j=3;j<=i;j++){
			dp[i][j]+=dp[i-1][j];
			long long maxx=0,anss=1,ansss=1;
			for(int k=1;k<=i;k++){
				if(b[k]>a[i]){
					maxx=k;
				}
			}
			for(int k=1;k<=maxx;k++){
				anss*=k;
			}
			for(int k=1;k<=i;k++){
				anss/=k;
			}
			anss%=mod;
			dp[i][j]+=anss;
			dp[i][j]=dp[i][j]%mod;
		} 
	}
	long long ans=0;
	for(int i=3;i<=n;i++){
		ans+=dp[n][i];
	}
	cout<<ans<<endl;
	return 0;
}
