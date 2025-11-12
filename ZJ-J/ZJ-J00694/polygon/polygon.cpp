#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 5000+100;
const int mod = 998244353;
int n;
LL a[N];
bool vis[N];
unsigned LL ans = 0;
void dfs(LL sum, LL maxn, LL p, int t){
	if(p >= 3){
		if(maxn*2 < sum) ans++;
		ans %= mod;
	}
	for(int i = t; i <= n; i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(sum+a[i], max(maxn, a[i]), p+1, i+1);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	LL maxt = -1;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		maxt = max(maxt, a[i]);
	}
	if(maxt == 1){
		for(int i = 3; i <= n; i++){
			unsigned LL t = 1;
			for(int j = n, k = 1; k <= i; j--, k++){
				t *= j;
				t /= k;
			}
			ans = (ans+t)%mod;
		}
		cout<<ans;
		return 0;
	} 
	dfs(0, 0, 0, 1);
	cout<<ans;
	return 0;
}
