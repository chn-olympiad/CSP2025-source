#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LYT ios::sync_with_stdio(0),cin.tie(0)
#define N 5000010

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i =1;i <= n;i++){
		int x;
		cin >> x;
	}
	int sum = 1;
	for(int i =1;i <= n;i++){
		sum  = (sum * i) % 998244353;
	}
	cout << sum << "\n"; 
	return 0;
}
