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

const ll N = 3000022;
ll lis[N], ham[N];
ll n, res;

int main(){
	freopen("polygon.in" ,"r", stdin);
	freopen("polygon.out","w", stdout);
	n = read();
	fff(i, 1, n){
		lis[i] = read();
	}
	fff(i, 1, (1 << n) - 1){
		ham[i] = ham[i & (i - 1)] + 1;
		if(ham[i] < 3 || ham[i] > n)continue;
		ll s = 0, m = 0;
		fff(k, 1, n){
			if(i & (1 << (k - 1))){
				s += lis[k];
				m = max(m, lis[k]);
			}
		}
		if(s > m * 2){
			res++;
		}
	}
	cout << res;
}

/*







*/

