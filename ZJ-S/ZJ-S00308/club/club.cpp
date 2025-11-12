#include<bits/stdc++.h>
#define ll long long
#define fff(i, a, b) for(ll i = a; i <= b; ++i)

using namespace std;

int innum(int x){
	return '0' <= x && x <='9';
}
ll read(){
	ll c = getchar(), res = 0, f = 1;
	for(; !innum(c); c = getchar()) if(c =='-') f = -1;
	for(;  innum(c); c = getchar()) res = res * 10 + c -'0';
	return res * f;
}

const ll N = 1000022;
ll lis[N], dp[225][225][225];
ll n, t, res;

int main(){
	freopen("club.in" ,"r", stdin);
	freopen("club.out","w", stdout);
	t = read();
	fff(_, 1, t){
		n = read();
		res = 0;
		memset(dp, 0, sizeof(dp));
		if(n <= 225) fff(i, 1, n){
			ll a = read(), b = read(), c = read();
			fff(j, 0, n){
				fff(k, 0, n){
					if(j > n / 2 || k > n / 2 || i - j - k > n / 2){
						break;
					}
					if(j){
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a);
					}
					if(k){
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + b);
					}
					if(i - j - k > 0){
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + c);
					}
					res = max(res, dp[i][j][k]);
				}
			}
		}
		if(n > 255){
			n = read();
			res = 0;
			ll s = 0;
			fff(i, 1, n){
				ll a = read(), b = read(), c = read();
				lis[i] = a - b;
				s += a;
			}
			sort(lis + 1, lis + n + 1);
			fff(i, 1, n / 2){
				s -= lis[i];
			}
			res = s;
		}
		cout << res <<'\n';
	}
	return 0;
}

/*

1
6
1 2 0
2 3 0
4 1 0
4 2 0
4 1 0
8 5 0



*/

