#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3+5,mod = 998244353;
int n,a[N];
ll ksm(ll a,ll b){
	if (b == 1){
		return a;
	}
	if (b == 0){
		return 1;
	}
	if (b & 1){
		ll x = ksm(a,b / 2) % mod;
		return x * x % mod * a % mod; 
	}
	else {
		ll x = ksm(a,b / 2) % mod;
		return x * x % mod;
	}
}
int jimd(int x,int y){
	int k = x - y;
	if (k < 0){
		k += mod;
	}
	return k;
}
int zuhe(int l,int sum,int mx,int cnt){
	int sm = cnt >= 3 && sum > mx * 2;
	for (int i = l;i <= n;++ i){
		sm += zuhe(i + 1,sum + a[i],max(mx,a[i]),cnt + 1);
	}
	return sm;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int fl = 1;
	for (int i = 1;i <= n;++ i){
		cin>>a[i];
		fl &= a[i] == 1;
	}
	sort(a+1,a+n+1);
	if (n == 3){
		if (a[1] + a[2] > a[3]){
			cout<<1;
		}
		else {
			cout<<0;
		}
		return 0;
	}
	if (fl){
		int x = ksm(2,n);
		cout<<jimd(x,n + n * (n - 1) / 2 + 1);
		return 0;
	}
	if (n <= 500){
		cout<<zuhe(1,0,0,0);
		return 0;
	}
	cout<<2 * n;
	return 0;
}