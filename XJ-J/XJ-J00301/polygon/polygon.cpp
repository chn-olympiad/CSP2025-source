#include<bits/stdc++.h>
using namespace std;
const int N = 5000+5;
const int mod =  998244353;
int n;
long long a[N];
long long sum[N],maxn[N];
int ans = 0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		sum[i]= sum[i-1] + a[i];
		maxn[i] = max(maxn[i-1],a[i]);
	}
	for(int i = 1;i <= n;i++){
		for(int j = i + 2;j <= n;j++){
			if(sum[j] - sum [i-1] > maxn[j]){
				ans++;
				ans %= mod;
			}
		}
	}
	cout << ans;
	return 0;
}

