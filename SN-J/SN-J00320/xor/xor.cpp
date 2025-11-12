#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
const int maxn=5e5+10;
const int inf=1e18;
int n,k,maxx=-inf,ans=0;
int a[maxn],sum[maxn];
int dp[maxn];//dp[i]表示从1到i的最多区间数量
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		sum[i]=sum[i]^a[i];
	}
	if(maxx<k){
		cout<<"0";
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[i+1]==1){
				ans++;
				a[i]=-1;
				a[i+1]=-1;
			}
			if(a[i]==0){
				ans++;
				a[i]=-1;
			}
		}
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
				a[i]=-1;
			}
			if(a[i]==1&&a[i+1]==0){
				ans++;
				a[i]=-1;
				a[i+1]=-1;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((sum[i-1]^sum[j])==k){
					ans++;
				}
			}
		}
	}
	cout<<ans;
//////////////////////////////////////////////////////////////////////////////
//	for(int i=1;i<=n;i++){
//		cout<<sum[i]<<" ";
//	}
//	cout<<"\n";
//	int ans=0;
//	else{
//		for(int i=1;i<=n;i++){
//			for(int j=i;j<=n;j++){
//				if((sum[i-1]^sum[j])==k){
//					cout<<"i:"<<i<<"  j:"<<j<<" sum[i-1]^sum[j]:"<<(sum[i-1]^sum[j])<<" k:"<<k<<"\n";
//				}
//			}
//		}
//	}
//	cout<<ans;
//////////////////////////////////////////////////////////////////////////////
	return 0;
}
