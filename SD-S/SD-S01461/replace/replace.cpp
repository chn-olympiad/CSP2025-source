#include <bits/stdc++.h>
//kmp×Ö·û´® 
using namespace std;
struct pss{
	string f;
	string s;
};
int n, q;
pss a[200010], b[200010];
void init(){
	for(int i = 0; i < n; ++ i){
		a[i].f = b[i].f;
	}
}
bool fin(string old, string ne){
	for(int i = 0; i < n; ++ i){
		if(a[i].f == old && a[i].s == ne){
			a[i].f = "";
			return true;
		}
	}
	return false;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 0; i < n; ++ i){
		cin >> a[i].f >> a[i].s;
		b[i].f = a[i].f;
		b[i].s = a[i].s;
	}
	while(q --){
		init();
		pss now;
		int ans = 0;
		cin >> now.f >> now.s;
		if(now.f.size() != now.s.size()){
			cout << 0 << endl;
			continue;
		}
		bool y = 0, brk = 0;
		string dif = "", ne = "";
		while(brk = 0){
			for(int i = 0; i < now.f.size(); ++ i){
				if(now.f[i] != now.s[i]){
					dif += now.f[i];
					ne += now.s[i];
				}
				else if(now.f[i] == now.s[i] && dif != ""){
					if(!fin(dif, ne)){
						brk = 1;
						break;
					}
					dif = "";
					ne = "";
				}
			}
			if(!brk) ans ++;
		}
		cout << ans << endl;
	}
	return 0;
}

