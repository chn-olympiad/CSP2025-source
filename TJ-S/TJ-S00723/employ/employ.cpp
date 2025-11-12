#include<bits/stdc++.h>
using namespace std;
//mt_19937 = run
typedef long long ll;
const ll maxn = 2e6 + 5;
const ll mod = 998244353;
ll m,n,one;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		int x;
		cin >> x;
		if(x == 1) one++;
	}
	if(m == 1) cout << m % mod * one % mod;
	else if(m == n) cout << 1;
}
