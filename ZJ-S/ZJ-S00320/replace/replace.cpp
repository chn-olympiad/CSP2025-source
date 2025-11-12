#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
const int N = 200005;
int n, q;
struct node{
	string a, b;
} p[N];
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> p[i].a >> p[i].b;
	}
	while(q--){
		string a, b;
		cin >> a >> b;
		string x = a, y = b;
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j + p[i].a.size() <= a.size(); j++){
				if(a.substr(j, (p[i].a).size()) == p[i].a && a.replace(j, (p[i].a).size(), p[i].b) == b){
					ans++;
					break;
				}
				a = x, b = y;
			}
		}
		cout << ans << "\n";
	}
	return 0;	
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
const int N = 200005;
int n, q;
struct node{
	string s[3];
	int l;
} p[N];
pair < int, int > F(string a, string b){
	int l, r;
	for(l = 0; l < min(a.size(), b.size()); l++){
		if(a[l] != b[l]) break;
	}
	for(r = 0; r < min(a.size(), b.size()); r++){
		if(a[a.size()-r-1] != b[b.size()-r-1]) break;
	}
	return {l, r};
}
string Substr(string a, int l, int len){
	string res = "";
	for(int i = l; i <= len && (i + len - 1 <= a.size()); i++) res += a[i];
	return res;
}
signed main(){
//	freopen("replace.in", "r", stdin);
//	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		string a, b;
		cin >> a >> b;
		pair < int, int > t = F(a, b);
		p[i].l = t.first;
		p[i].s[0] = a;
		p[i].s[1] = a.substr(t.first, a.size()-t.second-t.first);
		p[i].s[2] = b.substr(t.first, b.size()-t.second-t.first);
	}
	while(q--){
		string a, b;
		cin >> a >> b;
		pair < int, int > t = F(a, b);
		p[0].l = t.first;
		p[0].s[0] = a;
		p[0].s[1] = a.substr(t.first, a.size()-t.second-t.first);
		p[0].s[2] = b.substr(t.first, b.size()-t.second-t.first);
		int ans = 0;
		for(int i = 1; i <= n; i++){
			if(p[i].s[1] != p[0].s[1] || p[i].s[2] != p[0].s[2]) continue;
			string aaa = Substr(p[0].s[0], p[0].l - p[i].l, (p[i].s[0]).size());
			if(aaa == p[0].s[0]) ans++;
			cout << i<< "\n";
		}
		cout << ans << "\n";
	}
	return 0;	
}
*/