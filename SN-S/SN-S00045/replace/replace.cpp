#include<bits/stdc++.h>
using namespace std;
struct node{
	string s,ss;
}y[200010],t[200010];
long long n, q, ans , f, ff;
char dd,d;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> y[i].s >> y[i].ss;
	}
	for(int i = 1; i <= q; i++){
		cin >> t[i].s >> t[i].ss;
		if(t[i].s == t[i].ss) ans = 0;
		for (int j = 0; j < t[i].s.size(); j++){
			if(t[i].s[j] !=t[i].s[j + 1] && t[i].s[j] != t[i].s[j - 1]) d = t[i].s[j];
		}
		for (int j = 0; j < t[i].ss.size(); j++){
			if(t[i].ss[j] !=t[i].ss[j + 1] && t[i].ss[j] != t[i].ss[j - 1]) dd = t[i].ss[j];
		}
		for (int j = 1; j <= n ;j++){
			if(y[i].s == d ) f = 1;
			if(y[i].ss == dd) f = 1;
		}
		if(f == 0) ans = 0;
		cout << 0 << endl;
	}
	return 0;
}
