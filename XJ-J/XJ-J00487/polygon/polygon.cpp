#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int arr[5010];
int sum[5010];
typedef long long ll;
ll ans;

inline ll cnm(int n1,int m1){
	ll tmp=1;
	for (int i=n1-m1+1;i<=n1;i++){
		tmp=tmp*i%mod;
	}
	for (int i=2;i<=m1;i++){
		tmp/=i;
	}
	return tmp;
}
inline ll f(int d){
	d=n-d;
	ll cnt=0;
	for (int i=1;i<=d;i++){
		cnt=(cnt+cnm(d,i))%mod;
	}
	return cnt;
}
void dfs (int d,int maxn,ll sum){
	if (d==n+1){
		ans=(ans+1)%mod;
		return ;
	}
	if (sum>=maxn*2&&d!=1){
		ans+=f(d)%mod;
		return ;
	}
	dfs(d+1,max(maxn,arr[d]),sum+arr[d]);
	dfs(d+1,maxn,sum);
}
int main (){
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	scanf ("%d",&n);
	for (int i=1;i<=n;i++){
		cin >>arr[i];
	}
	if (n<3){
		cout <<0;
		exit(0);
	}
	sort(arr+1,arr+1+n,greater<int>());
	dfs(1,0,0)
	cout <<ans%mod;
//	n=8;
//	cout  <<f(4);
	
	fclose (stdin);
	fclose (stdout);
	return 0;
}
