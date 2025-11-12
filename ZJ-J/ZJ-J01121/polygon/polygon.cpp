#include <bits/stdc++.h>
using namespace std;
long long n,ans,a[5010],s,sum[5010],k;
const int mod=998244353;
void dfs(long long x,long long sum,long long ma,long long gen){
	if(x==n+1){
		if(sum>ma*2&&gen>=3) ans++;
		return ;
	}
	dfs(x+1,sum,ma,gen);
	dfs(x+1,sum+a[x],max(ma,a[x]),gen+1);
}
long long cal(long long x,long long y){
	long long sum1=1,sum2=1;
	for(int i=y;i>=y-x+1;i--) sum1*=i;
	for(int i=1;i<=x;i++) sum2*=i;
	return sum1/sum2;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	if(n<=20){
		dfs(1,0,0,0);
		cout<<ans%mod;		
	}
	else if(a[n]==1){
		for(int i=3;i<=n;i++) s+=cal(i,n),s%=mod;
		cout<<s;
	}
	else{
		for(long long i=3;i<=n;i++)
			for(long long l=1;l<=i;l++)
				for(long long r=l+2;r<=i;r++){
					s=sum[r]-sum[l-1];
					if(s>a[r]*2) ans++; 
					ans%=mod;
				}
		cout<<ans%mod;
	}
	return 0;
}