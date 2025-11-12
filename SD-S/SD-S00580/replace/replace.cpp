#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a , b) memset(a , b , sizeof a)
using namespace std;
const int N = 2e5+10;
const int M = 5e6+10;
ll n , m;
struct Node{
	string a , b;
	string o;
	ll len;
	bool f = 0;
	bool operator<(const Node&GFX) const{
		return len < GFX.len;
	}
}lis[N];
//bool cmp(Node& x , Node& y) {
//	return x.len < y.len;
//}
//unordered_map<string , string> mp;
ll t[M] , nxt[M];
string x , y;
string ta , tb;

void qtqw(string& a , string& b , ll len , ll& l , ll &r) {
	l = 0;
	for(int i = 0 ; i < len ; i++) {
		if(a[i] != b[i]) {
			l = i;
			break;
		}
	}
	r = l;
	for(int i = l + 1 ; i < len ; i++) {
		if(a[i] != b[i]) {
//			cout << i << ' ';
			r = i;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) {
		cin >> x >> y;
		ll l ; ll r;
		if(x != y) {
			qtqw(x , y , x.size() , l , r);
			ll q = 0;
			lis[i].o = x;
			for(int p = l ; p <= r ; p++) {
				lis[i].a += x[p];
				lis[i].b += y[p];
				q++;
			}
//			cout << l << ' ' << r;
			lis[i].len = lis[i].a.size();
		}
		else {
			lis[i].f = 1;
		}
			
	}
	sort(lis + 1 , lis + 1 + n);
	ll j = 1;
	for(int i = 1 ; i <= n ; i++) {
		if(lis[i].len ^ j) {
			nxt[j] = lis[i].len;
			t[lis[i].len] = i;
			j = lis[i].len;
		}
	}
	nxt[j] = lis[n].len;
	if(t[lis[n].len] == 0) t[lis[n].len] = n;
	nxt[lis[n].len] = n+1;
	t[n+1] = n+1;
//	for(int i = 1 ; i <= 5 ; i++) {
//		cout << t[i] << ' ';
//	}
	for(int i = 1 ; i <= m ; i++) {
		cin >> x >> y;
		ll al = x.size();
		if(al ^ y.size()) {
			cout << 0 << '\n';
			continue;
		}
		ll l = 0 , r = 0;
		qtqw(x , y , al , l , r);
		ll bl = (r - l + 1);
		if(!t[bl]) {
			cout << 0 << '\n';
			continue;
		}
//		cout << al << ' ' << bl << '\n';
		ll q = 0;
		for(int p = l ; p <= r ; p++) {
			ta += x[p];
			tb += y[p];
			q++;
		}
		ll ans = 0;
		for(int i = t[bl] ; i < t[nxt[bl]] ; i++) {
			if(lis[i].a == ta && lis[i].b == tb && (~x.find(lis[i].o))) ans++;
			if(lis[i].f) ans++; 
//			cout << lis[i].a << ' ' << ta << '\n';
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
1 1
d a
ad aa

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

1 1
ad bd
a b
*/
