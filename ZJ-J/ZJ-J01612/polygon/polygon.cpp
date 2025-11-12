#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[5005],f[50005][4],maxn=0;
const int mod=998244353;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
	}
	maxn++;
	sort(a+1,a+1+n);
	int sum=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=0;j--){
			for(int k=3;k>=1;k--){
				if(j>a[i]&&k>=2){
//					if(f[j][k]!=0)cout<<i<<" "<<j<<" "<<k<<" "<<f[j][k]<<endl;
					ans=(ans+f[j][k])%mod;
				}
				f[min(j+a[i],maxn)][min((int)3,k+1)]=(f[min(maxn,j+a[i])][min((int)3,k+1)]+f[j][k])%mod;
			}
		}
		f[a[i]][1]+=1;
		sum+=a[i];
		sum=min(sum,maxn);
	}
//	for(int i=1;i<=sum;i++){
//		ans=(ans+f[i][3])%mod;
//	}
	cout<<ans;
	return 0;
}