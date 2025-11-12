#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define dbug(x) (void)(cerr << #x << " = " << x << endl)

const int N = 5086 , mod = 998244353;
ll a[N] , cnt;

int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out", "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	ll n;
	cin >> n;
	for(ll i = 1;i <= n;i++){
		cin >> a[i];
	}

	for(ll i = 1;i < (1 << n);i++){
		ll sum = 0 , maxn = INT_MIN,temp = 0;
		for(ll j = 1;j <= n;j++){
			if((1 << (j - 1)) & i){
				sum += a[j];
				temp++;
				maxn = max(maxn , a[j]);
			}
		}
		if(sum > maxn * 2 && temp >= 3){
			cnt = (cnt + 1) % mod;
		}
	}
	cout << cnt;



	return ~~(0 ^ 0);
}
