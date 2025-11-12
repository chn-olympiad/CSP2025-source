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
ll lis[N];
ll n, m, a1, nth;

void seat(ll nth){
	ll rx, ry;
	rx = (nth - 1) / n + 1;
	ry = (nth - 1) % n + 1;
	if(rx % 2 == 0) ry = n + 1 - ry;
	cout << rx <<' '<< ry <<'\n';
}

bool cmp(ll x, ll y){
	return x > y;
}

int main(){
	freopen("seat.in" ,"r", stdin);
	freopen("seat.out","w", stdout);
	n = read();
	m = read();
	fff(i, 1, n * m){
		lis[i] = read();
	}
	a1 = lis[1];
	sort(lis + 1, lis + n * m + 1, cmp);
	fff(i, 1, n * m){
//		cerr << lis[i] <<' ';
		if(lis[i] == a1){
			nth = i;
		}
	}
	seat(nth);
}

/*

2 2
99 100 97 98

2 3
1 2 3 4 5 6

2 3
4 2 1 3 5 6

2 3




*/

