#include <bits/stdc++.h>
#define N 200005
using namespace std;
struct kmp {
	string a, rp; int n;
	vector<int> nxt;
	void init(const string& s, const string& srp) {
		a = s, rp = srp;
		n = a.size();
		nxt.reserve(n);
		nxt.push_back(0);
		for(int i=1,j=0 ; i<n ; i++) {
			while(j && a[i] != a[j]) j = nxt[j-1];
			if(a[i] == a[j]) j ++;
			nxt.push_back(j);
		}
	}
	int find(const string& b) {
		for(int i=0,j=0,l=b.size() ; i<l ; i++) {
			while(j && (j == n || b[i] != a[j])) j = nxt[j-1];
			if(b[i] == a[j]) j ++;
			if(j == n) return i-n+1; // return the beginning
		} return -1;
	}
} s[N];
int n, q;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	string str, str1, str2;
	for(int i=0 ; i<n ; i++) {
		cin >> str >> str2;
		s[i].init(str, str2);
	} for(int i=0 ; i<q ; i++) {
		cin >> str >> str2;
		int ans = 0;
		if(str.size() == str2.size()) for(int j=0 ; j<n ; j++) {
			int p = s[j].find(str);
			if(p == -1) continue;
			str1 = str;
			str1.replace(p, s[j].n, s[j].rp);
			if(str1 == str2) ans ++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
