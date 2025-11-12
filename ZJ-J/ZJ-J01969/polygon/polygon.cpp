#include<bits/stdc++.h>
using namespace std;
long long int mod=998244353;
int n,a[110000],sum[110000];
long long ans;
void dfs(int step,int mi,long long int sum){
	if(step==mi){
		if(sum>a[mi]){
			ans++;
			ans%=mod;
		}
		return ;
	}
	dfs(step+1,mi,sum+a[step]);
	dfs(step+1,mi,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(sum[i-1]>a[i])
			dfs(1,i,0);
	}
	cout<<ans;
	return 0;
}
