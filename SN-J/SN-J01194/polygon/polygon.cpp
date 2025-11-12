#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5825],dp[10025],cnt,sum,mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		scanf("xd",&a[i]);
		}
		sort(a+1,a+1+n);
		if(n<=3){
			if(n==3){
				if((a[i]+a[2])a[3]){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
			}
		}else if(n<=500){
			for(int i=n;i>0;i++){
				memset(dp,0,sizeof(dp));
				dp[0]=1;
				for(int k=a[i]+a[j];k=a[j];k--){
					dp[k]+=dp[k-a[j]];
				}
			}
			for(int k=a[i],k<=10000;k--){
				ans+=dp[k];
			}
		}
	cout<<ans;
	return 0;
}
