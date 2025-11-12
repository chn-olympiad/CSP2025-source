#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

map<string, string> m;
vector<string> x1, x2, z1, z2;

int main(){
	
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		string x, y;
		cin >> x >> y;
		m[x] = y;
	}
	
	while(q--){
		string s1, s2;
		cin >> s1 >> s2;
		if(s1.size() != s2.size()){
			cout << "0\n";
			continue;
		}
		x1.clear();
		x2.clear();
		z1.clear();
		z2.clear();
		string sx1 = "", sx2 = "", sz1 = "", sz2 = "";
		for(int i = 0; i < s1.size(); i++){
			x1.push_back(sx1);
			x2.push_back(sx2);
			sx1 += s1[i];
			sx2 += s2[i];
		}
		for(int i = s1.size() - 1; i >= 0; i--){
			z1.push_back(sz1);
			z2.push_back(sz2);
			sz1 = s1[i] + sz1;
			sz2 = s2[i] + sz2;
		}
		
//		for(auto i : x1) cout << i << " "; cout << "\n";
//		for(auto i : x2) cout << i << " "; cout << "\n";
//		for(auto i : z1) cout << i << " "; cout << "\n";
//		for(auto i : z2) cout << i << " "; cout << "\n";
		int ans = 0;
		for(int i = 0; i < s1.size(); i++){
			string t1 = "", t2 = "";
			for(int j = i; j < s1.size(); j++){
				t1 += s1[j], t2 += s2[j];
			//	if(m[t1] == t2) cout << x1[i] + m[t1] + z1[z1.size() - i] << " " << x2[i] + t2 + z2[z2.size() - i] << "\n";
				if(x1[i] + m[t1] + z1[s1.size() - j- 1] == x2[i] + t2 + z2[s1.size() - j-1]) ans++;
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}
