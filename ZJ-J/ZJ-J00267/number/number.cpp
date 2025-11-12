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

const ll N = 1000022;
ll n, hsh[14];

char str[N];

int main(){
	freopen("number.in" ,"r", stdin);
	freopen("number.out","w", stdout);
	cin >> str;
	for(int i = 0; str[i]; i++){
		if(innum(str[i])){
			hsh[str[i] - '0']++;
		}
	}
	for(int k = 9; k >= 0; k--){
//		cerr <<'='<< hsh[k];
		fff(i, 1, hsh[k]){
			cout << k;
		}
	}
}

/*







*/

