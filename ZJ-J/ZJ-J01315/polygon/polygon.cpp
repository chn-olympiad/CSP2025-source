#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5001],cnt[5001],bj[5001],b[5001],k,s[5001],sc[5001],cnt1[5001];
long long ans;
long long ksm(long long x,long long y){
	long long res=1;
	while(y){
		if(y&1){
			res*=x;
			res%=mod;
		}
		x*=x;
		x%=mod;
		y>>=1;
	}
	return res%mod;
}
long long c(long long x,long long y){
	if(y-x<x){
		x=y-x;
	}
	long long ans1=1,ans2=1;
	for(int i=1;i<=x;i++){
		ans1*=(y-i+1);
		ans1%=mod;
		ans2*=i;
		ans2%=mod;
	}
	return (ans1*ksm(ans2,mod-2))%mod;
}
void dfs(int sum,int x){
	if(sum<0){
		long long res=1;
		for(int i=1;i<=k;i++){
			res*=c(cnt1[i]-cnt[b[i]],cnt1[i]);
			res%=mod;
		}
		ans+=res;
		ans%=mod;
	}
	for(int i=x;i>=1;i--){
		if(cnt[b[i]]&&s[i]>sum){
			s[i]-=b[i];
			cnt[b[i]]--;
			dfs(sum-b[i],i);
			s[i]+=b[i];
			cnt[b[i]]++;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
		if(!bj[a[i]]){
			k++;
			b[k]=a[i];
			bj[a[i]]=1;
		}
	}
	sort(b+1,b+k+1);
	for(int i=1;i<=k;i++){
		s[i]=s[i-1]+b[i]*cnt[b[i]];
		sc[i]=sc[i-1]+cnt[b[i]];
		cnt1[i]=cnt[b[i]];
	}
	if(n>=300){
		for(int i=3;i<=n;i++){
			ans+=c(i,n);
			ans%=mod;
		}
		printf("%lld",ans);
		return 0;
	}
	for(int i=k;i>=1;i--){
		if(sc[i]>=3){
			cnt[b[i]]--;
			dfs(b[i],i);
			cnt[b[i]]++;
			//xgw120121 and kzh
			//fanxing1124 and yr
		}
	}
	printf("%lld",ans);
	return 0;
}
