#include <bits/stdc++.h>

#define N ((int)2e5 + 10)
#define L ((int)2.5e6 + 10)

using namespace std;

int n, q;
string t1, t2;

int lst1[L], lst2[L];
inline void kmp(int lst[], const string &s) {
	lst[0] = 0;
	
	int j = 0;
	for(int i = 1;i <= s.size();i++) {
		while(j != 0 && s[i] != s[j]) {
			j = lst[j - 1];
		}
		
		if(s[i] == s[j]) {
			j++;
		}
		lst[i] = j;
	}
#ifdef XYX
	cout << s << endl;
	for(int i = 0;i < s.size();i++) {
		cout << lst[i];
	}
	cout << "\n\n";
#endif
} 

unordered_map<string, string> mp;

int main() {
#ifdef XYX
#else 
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
#endif 
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
//	kmp(lst, "bc#xabcx");
//	kmp(lst, "de#xadex");
	
	cin >> n >> q;
	for(int i = 1;i <= n;i++) {
		cin >> t1 >> t2;
		mp[t1] = t2;
	}
	
	while(q--) {
		cin >> t1 >> t2;
		
		int ans = 0;
		for(int i = 0;i < t1.size();i++) {
			string d1 = "", d2 = "";
			for(int j = i;j < t1.size();j++) {
				d1 += t1[j];
				d2 += t2[j];
				
				if(mp.find(d1) != mp.end() && mp[d1] == d2) {
					++ans;
				}
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