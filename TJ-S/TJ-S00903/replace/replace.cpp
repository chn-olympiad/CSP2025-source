#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
int n, q;
map <string, string> mp;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		string s, ss;
		cin >> s >> ss;
		mp[s] = ss;
	}
	while(q --){
		string t, tt;
		cin >> t >> tt;
		int lt = t.size(), ltt = tt.size();
		if(lt != ltt){
			cout << 0 << "\n";
			continue;
		}
		if(lt > 2000 && ltt > 2000){
			int p = 0, q = 0;
			for(int i = 0;i < lt;i++){
				if(t[i] == 'b'){
					p = i;
				}else if(tt[i] == 'b') q = i; 
			}
			if(p == q){
				int cnt = 0;
				string s = t.substr(0, p);
				for(int i = p;i < lt;i++){
					s += t[i];
					if(mp[s] == s) cnt ++;
				}
				cout << cnt << "\n";
			}else{
				int px = max(p, q);
				p = min(p, q);
				q = px;
				int cnt = 0;
				for(auto xx : mp){
					string s = xx.first, ss = xx.second;
					if(s == ss) continue;
					int pp = 0, qq = 0, ls = s.size();
					for(int i = 0;i < ls;i++){
						if(s[i] == 'b') pp = i;
						if(ss[i] == 'b') qq = i;
					} 
					int ppx = max(pp, qq);
					pp = min(pp, qq);
					qq = ppx;
					if(pp <= p && ls - qq <= lt - q) cnt ++;
				}	
				cout << cnt << "\n";
			}
		}else{
			int l = lt - 1, r = 0;
			for(int i = 0;i < lt;i++){
				if(t[i] != tt[i]){
					l = i;
					break;
				}
			}
			for(int i = lt - 1;i >= 0;i--){
				if(t[i] != tt[i]){
					r = i;
					break;
				}
			}
			int cnt = 0;
			for(int i = 0;i <= l;i++){
				string s = "", ss = "";
				for(int j = i;j < lt;j++){
					s += t[j], ss += tt[j];
					if(j < r) continue;
					if(mp[s] == ss) cnt ++;
				}
			} 
			cout << cnt << "\n";			
		}
	}
	return 0;
}

