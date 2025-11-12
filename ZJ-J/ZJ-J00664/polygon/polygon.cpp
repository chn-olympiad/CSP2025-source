#include <bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
const int mod=998244353;
int n,a[maxn],q[maxn],h[maxn];
bool check(int op){
	int num=0,cnt=0,maxx=-1;
	for (int i=1;i<=n;++i){
		if (op&(1<<(i-1))){
			cnt+=a[i];
			num++;
			maxx = max(maxx,a[i]);
		}
	}
	if (num<3) return false;
	else if (cnt<=maxx*2) return false;
	else return true;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	q[0]=1;
	h[0]=1;
	for (int i=1;i<=n;++i){
		h[i]=h[i-1]*i;
	}
	for (int i=1;i<=5;++i){
		q[i]=q[i-1]*(n-i+1)%mod;
	}
	bool f=true;
	for (int i=1;i<=n;++i){
		cin >> a[i];
		if (a[i]!=1) f=false;
	}
	int ans=0;
	if (f){
		for (int i=4;i<=n;++i){
			ans = (ans+q[i]/h[i])%mod;
		}
	}
	else{
		for (int i=0;i<(1<<(n));++i){
			if (check(i)){
				ans = (ans+1)%mod;
			}
		}
	}
	cout << ans;

	return 0;
}

