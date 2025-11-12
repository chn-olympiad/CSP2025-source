#include<bits/stdc++.h>
#define ll long long
#define fff(i, a, b) for(ll i = a; i <= b; ++i)

using namespace std;

int innum(int x){
	return '0'<= x && x <='9';
}
ll read(){
	ll c = getchar(), res = 0, f = 1;
	for(; !innum(c); c = getchar()) if(c =='-') f = -1;
	for(;  innum(c); c = getchar()) res = res * 10 + c -'0';
	return res * f;
}

const ll N = 500022;
ll lis[N], s[N], dp[N], d[N];
ll n, k, tot, res;

//int c[N * 32][2], dn[n * 32];

map<ll, ll> mp;

int main(){
	freopen("xor.in" ,"r", stdin);
	freopen("xor.out","w", stdout);
	n = read();
	k = read();
	fff(i, 1, n){
		lis[i] = read();
		s[i] = s[i - 1] ^ lis[i];
//		d[i] = s[i];
	}
//	sort(d + 1, d + n + 2);
//	fff(i, 1, n){
//		cerr << i <<' '<< lis[i] <<' '<< s[i] <<'\n';
//	}
	mp[0] = 0x3f3f3f3f;
	fff(i, 1, n){
		ll j = mp[s[i] ^ k];
		if(j){
			if(j == 0x3f3f3f3f){
				dp[i] = 1;
			} else {
				dp[i] = dp[j] + 1;
			}
		}
		mp[s[i]] = i;
		dp[i] = max(dp[i], dp[i - 1]);
		res = max(res, dp[i]);
//		cerr << i <<' '<< j <<' '<< (s[i] ^ k) <<' '<< mp[s[i] ^ k] <<' '<< dp[i] <<'\n';
	}
	cout << res;
}

/*

4 2
2 1 0 3





*/

