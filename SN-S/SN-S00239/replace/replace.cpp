#include "bits/stdc++.h"
using namespace std;
const int N = 2e5+5;

int n, q;

struct Node{
	string s1, s2;
}g[N];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i=1;i<=n;++i){
		cin >> g[i].s1 >> g[i].s2;
	}
	string ss1, ss2;
	
	for(int i=1;i<=q;++i){
		cin >> ss1 >> ss2;
		int ans = 0; 
		int L1 = ss1.size();
		for(int j=1;j<=n;++j){
			int L = g[j].s1.size();
			for(int l=0;l<=L1-L;++l){
				string s = ss1.substr(l, L), ss;//截下来的字符串， 拼好串 
				if(s == g[j].s1){//能被替换 
					ss = ss1.substr(0, l-0)+g[j].s2+ss1.substr(l+L, ss1.size()-(l+L));
					if(ss == ss2) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
