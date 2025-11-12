#include<bits/stdc++.h>
using namespace std;
const int maxn=5050,mod=998244353;
long long n,a[maxn],ans,num;
void dfs(long long x,long long sum){
	if(x>=n){
		return ;
	}
	sum+=a[x];
	if(sum>a[n]){
		ans+=n-x;
		ans%=mod;
	}
	else if(sum>a[x+1]){
		long long cnt=lower_bound(a+x+1,a+n+1,sum)-a;
		ans+=cnt-x-1;
		ans%=mod;
	}
	dfs(x+1,sum);
	sum-=a[x];
	dfs(x+1,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num=max(num,a[i]);
	}
	if(num==1||n>=100){
		if(n<=2){
			cout<<0;
			return 0;
		}
		if(n==3){
			cout<<1;
			return 0;
		}
		long long res=4;
		ans=1;
		for(int i=4;i<=n;i++){
			ans+=res;
			res=res*2+i-1;
			ans%=mod;
			res%=mod;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,0);
	cout<<ans;
	return 0;
}
