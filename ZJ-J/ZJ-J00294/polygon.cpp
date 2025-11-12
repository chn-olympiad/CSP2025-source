#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5000];
vector<long long> q;
long long ans;
bool check(long long maxn,long long sum){
	return sum>maxn*2;
}
void dfs(long long cur_cnt,long long cur_pos,long long maxn,long long sum){
	if(cur_cnt>=3&&check(maxn,sum)) ans++;
	if(cur_pos==n) return;
	for(long long i=cur_pos+1;i<=n;i++){
		dfs(cur_cnt+1,i,max(maxn,a[i]),sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	if(n>20){
		long long ans2=0;
		for(long long m=3;m<=n;m++){
			long long nl=1,ml=1;
			for(long long i=n;i>=m+1;i--) nl*=i;
			for(long long i=(n-m);i>=1;i--) ml*=i;
			ans2+=nl/ml;
		}
		printf("%lld",ans2);
		return 0;
	}
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(0,0,0,0);
	printf("%lld",ans%998244353);
	return 0;
}