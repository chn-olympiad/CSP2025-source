#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int Mod=998244353;
int a1,n,a[N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a1=max(a[i],a1);
	}
	if(a1==1){
		long long dp[N];
		dp[1]=dp[2]=0;
		for(int i=3;i<=n;i++){
			dp[i]=(2*dp[i-1]+(i-2)*(i-1)/2)%Mod;
		}
		cout<<dp[n];
		goto end;
	}
	for(int i=1;i<=pow(2,n);i++){
		int x=i,c=n,maxx=0,sum=0;
		while(x!=0){
			int k=x%2;
			x/=2;
			maxx=max(a[c]*k,maxx);
			sum+=a[c]*k;
			c--;
		}
		if(sum>2*maxx) ans=(ans+1)%Mod;
	}
	cout<<ans;
	end:;
	return 0;
}