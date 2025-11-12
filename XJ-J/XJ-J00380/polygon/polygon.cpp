#include <bits/stdc++.h>

using namespace std;

int n;
long long a[5050],ans,maxn,cnt;
long long N = 998244353;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	if (n<=2) ans = 0;
	else if (n==3){
		for (int i=1;i<=n;i++){
			maxn = max(maxn,a[i]);
			cnt += a[i];
		}
		maxn = maxn*2;
		if (cnt > maxn)ans = 1;
		else ans = 0;
	}else{
		for (int i=1;i<=n;i++){
			maxn = max(maxn,a[i]);
		}
		if (maxn == 1){
			
		}
	}
	cout << ans%N;
	return 0;
}
