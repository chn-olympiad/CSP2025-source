#include <bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N = 1e5 + 10;
int m, n;
int MOD = 998244353;
int a[N],b[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	long long tt = 1;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++){
		cin >> b[i];
	}
	for(int i = 1;i <= n;i ++){
		tt = (tt * i) % MOD;
	}
	cout << tt;
	return 0;
}