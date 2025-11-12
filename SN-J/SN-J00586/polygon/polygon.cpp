#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[5005],f[5005],num[10005];
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	num[a[1]+a[2]]=1;
	for(int i=3;i<=n;i++){
		int sum=0;
		for(int j=2;j<=a[i];j++) sum+=num[j],sum%=mod;
		f[i]=((ksm(2,i-1)-i+mod)%mod-sum+mod)%mod;
		for(int j=5000;j>=a[i]+1;j--) num[j]+=num[j-a[i]],num[j]%=mod;
		for(int j=1;j<i;j++) num[a[j]+a[i]]++,num[a[j]+a[i]]%=mod;
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans+=f[i],ans%=mod;
	cout<<ans;
	return 0;
}
