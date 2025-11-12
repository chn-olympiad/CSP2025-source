#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
//#include <ctime>
using namespace std;
// center char, list<true char, center char's position in true char> 
map<string, vector<pair<string, int> > > m;
int main(){
	//int t = clock();
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; ++i){
		string s1, s2;
		cin >> s1 >> s2;
		int l = 0, r = s1.size() - 1;
		for (; l < s1.size() && s1[l] == s2[l]; ++l);
		for (; r >= 0 && s1[r] == s2[r]; --r);
		string cts = s1.substr(l, r - l + 1);
		pair<string, int> tmp;
		tmp.first = s2, tmp.second = l;
		m[cts].push_back(tmp);
	}
	//cerr << clock() - t;
	for (int i = 0; i < q; ++i){
		string s1, s2;
		cin >> s1 >> s2;
		if (s1.size() != s2.size()){
			printf("0\n");
			continue;
		}
		int ans = 0;
		int l = 0, r = s1.size() - 1;
		for (; l < s1.size() && s1[l] == s2[l]; ++l);
		for (; r >= 0 && s1[r] == s2[r]; --r);
		string cts = s1.substr(l, r - l + 1);
		//cout << cts << l << r << endl;
		for (int j = 0; j < m[cts].size(); ++j){
			if (m[cts][j].second <= l && m[cts][j].first == s2.substr(l - m[cts][j].second, m[cts][j].first.size())){
				//cout << m[cts][j].first << ' ' << s2.substr(l - m[cts][j].second, m[cts][j].first.size()) << endl;
				++ans;
			}
		}
		//cerr << m[cts].size() << endl;
		/*
		2 2
xabcx xadex
bc de
xabcx xadex
		*/
		printf("%d\n", ans);
		//cout << ans << endl;
	}
	return 0;
}