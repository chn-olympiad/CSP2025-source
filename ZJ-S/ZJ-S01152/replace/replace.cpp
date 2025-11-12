//Flandre Scarlet
//I felt a little dead
#include<bits/stdc++.h>
using namespace std;
int n, q;
string f, t;
int ml, mr;
int ans;
//used hashmap to be faster
unordered_map<string, unordered_set<string> > sp;
unordered_set<int> vlen;
unordered_map<string, unordered_map<string, int> > w;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin>>n>>q;
	for(int i = 1; i <= n; i++) {
		string s1, s2;
		cin>>s1>>s2;
		vlen.insert(s1.size());
		if(sp.find(s1) == sp.end()) {
			unordered_set<string> tmp;
			sp[s1] = tmp;
		}
		sp[s1].insert(s2);
		if(w.find(s1) == w.end()) {
			unordered_map<string, int> tmp;
			w[s1] = tmp;
		}
		if(w[s1].find(s2) == w[s1].end()) {
			w[s1][s2] = 0;
		}
		w[s1][s2]++;
	}
	
	while(q--) {
		cin>>f>>t;
		
		if(f.size() != t.size()) {
			printf("0\n");
			continue;
		}
		
		ml = 0, mr = f.size() - 1;
		while(ml < f.size() && f[ml] == t[ml]) ml++;
		while(mr > ml && f[mr] == t[mr]) mr--;
		
		ans = 0;
		for(int i : vlen) {
			if(i < mr - ml + 1) {
				continue;
			}
			for(int j = ml; j + i > mr && j >= 0; j--) {
				if(j + i > f.size()) {
					continue;
				}
				string key = f.substr(j, i);
				if(sp.find(key) != sp.end()) {
					for(string val : sp[key]) {
						string tmp = f.substr(0, j);
						tmp += val;
						if(j + i < f.size()) tmp += f.substr(j + i);
						if(tmp == t) {
							ans += w[key][val];
						}
					}
				}
			}
		}
		
		printf("%d\n", ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
