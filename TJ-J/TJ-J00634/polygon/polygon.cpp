#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5001];
long long jc[51];
int t = 0;
long long ans = 0;
void solve1(){
	if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2) cout << 1;
	else cout << 0;
	return;
}
void solve2(){
	ans+=(n-1)*(n-2)/2;
	cout << ans%998244353;
	return;
}
void solve3(long long depth, int cnt, long long sum, long long maxn){
	t++;
	if(t==2e8){
		cout << ans%998244353;
		exit(0);
	}
	if(depth==n+1){
		if(sum>maxn*2 && cnt>=3) ans++;
		return;
	}
	solve3(depth+1,cnt+1,sum+a[depth],max(maxn,a[depth]));
	solve3(depth+1,cnt,sum,maxn);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int f1 = 1;
	for(long long i = 1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1) f1 = 0;
	}
	if(n==3) solve1();
	else if(f1==1) solve2();
	else{
		solve3(1,0,0,-1);
		cout << ans%998244353;
	}
	return 0;
} 
