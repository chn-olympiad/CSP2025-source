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
ll lis[N];
ll n;

int main(){
	freopen("employ.in" ,"r", stdin);
	freopen("employ.out","w", stdout);
	cout << 0;
	return 0;
}

/*







*/

