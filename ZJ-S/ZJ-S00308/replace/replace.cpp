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
ll n, q, res;

char str1, str2;

ll hsh(string &s, ll l, ll r){
	ll res = 0;
	fff(i, l, r){
		res += s[i] * 0x0d000721ll;
		res ^= res >> 5;
		res ^= res << 13;
		res ^= res >> 46;
	}
	return res;
}

struct ps{
	string s1, s2;
	ll y, yp;
	ll lx, ly, n;
	void rd(){
		cin >> s1 >> s2;
		n = s1.size();
		if(s1 != s2){
			for(lx = 0; s1[lx] == s2[lx]; lx++);
			for(ly = lx; ly < n && s1[ly] != s2[ly]; ly++);
			y = hsh(s1, lx, ly - 1);
			yp= hsh(s2, lx, ly - 1);
		}
//		cerr << lx <<' '<< ly <<' '<< y <<' '<< yp <<'\n';
	}
}pss[N], t;

int main(){
	freopen("replace.in" ,"r", stdin);
	freopen("replace.out","w", stdout);
	n = read();
	q = read();
	fff(i, 1, n){
		pss[i].rd();
	}
	fff(i, 1, q){
		res = 0;
		t.rd();
		fff(j, 1, n){
			if(pss[j].y == t.y && pss[j].yp == t.yp){
//				fff(k, 0, n - 1){
//				}
				res++;
			}
		}
		cout << res <<'\n';
	}
	return 0;
}

/*







*/

