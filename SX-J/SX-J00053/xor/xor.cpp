#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define dbug(x) (void)(cerr << #x << " = " << x << endl)

const int N = 50 * 10086;
ll a[N], sum[N];
ll n,k;

inline bool check(ll l ,ll r){
	ll temp = sum[r] ^ sum[l - 1];
	if(temp == k) return 1;
	return 0;
}

int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out", "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);


	cin >> n >> k;
	for(ll i = 1;i <= n;i++){
		cin >> a[i];
		sum[i] = sum[i-1] ^ a[i];
	}
	// 我的直觉告诉我，这是 O(n) 的。
	ll pos = 0 , cnt = 0;
	for(ll r = 1;r <= n;r++){
		for(ll l = pos + 1;l <= r;l++){
			if(check(l , r)){
				//cout << l << " " << r << endl;
				pos = r;
				cnt++;
				break;
			}
		}
	}

	cout << cnt;

	return 0;
}
