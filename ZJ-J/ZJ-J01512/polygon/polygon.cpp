#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],b[5005];
long long ans;
bool ok=true;
const long long mod=998244353;
void dfs(long long k,long long sum,long long maxn){
	if (sum>2*maxn){
		ans++;
		ans%=mod;	
	}
	if (k>n) return ;
	for (long long i=b[k-1]+1;i<=n;i++){
		b[k]=i;
		dfs(k+1,sum+a[i],max(a[i],maxn));
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (long long i=1;i<=n;i++){
		scanf("%lld",a+i);
		if (a[i]>1) ok=false;
	}
	if (ok){
		long long ans=1,cnt=0;
		for (long long i=1;i<=n;i++){
			ans=ans*2%mod;
			cnt=(cnt+i)%mod;
		}
		cnt=((cnt-n)%mod+mod)%mod;
		cout<<((ans-n-1-cnt)%mod+mod)%mod<<endl;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}

