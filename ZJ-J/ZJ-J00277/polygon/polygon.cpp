#include<bits/stdc++.h>
using namespace std;
long long n,k,f[5001],ans=0,arr[5001],one=0;
const long long mod=998244353;
long long c(){
	long long sum=1;
	for(int i=1;i<=n;i++){
		sum*=2;
		sum%=mod;
	}
	long long res1=n%mod;
	long long res2=(n*(n-1)/2)%mod;
	long long ask=(sum-res1-res2-1)%mod;
	return ask;
}

void dfs(int b,int s,int w){
	if(b==s){
		long long sum=0,maxn=-1;
		for(int i=1;i<=s;i++){
			sum+=arr[i];
			maxn=max(maxn,arr[i]);
		}
		if(2*maxn<sum){
			ans++;
			ans%=mod;
		}
	}
	for(int i=w;i<n;i++){
		arr[s+1]=f[i];
		dfs(b,s+1,i+1);
		arr[s+1]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>f[i];
		if(f[i]==1)one++;
	}
	if(one==n){
		ans=c();
	}
	else{
		for(int i=3;i<=n;i++){
		dfs(i,0,0);
		}
	}
	
	cout<<ans;
	return 0;
}
