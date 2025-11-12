#include<bits/stdc++.h>
using namespace std;
#define N 200001
int n,q,d1,d2,ans;
string s1[N],s2[N],t1,t2;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;++i){
		cin >> s1[i] >> s2[i];
	}
	for(int i = 1;i <= q;++i){
		cin >> t1 >> t2;
		if(t1.size() != t2.size()){
			cout << 0 << endl;
			continue;
		}
		d1 = -1;
		for(int j = 0;j < t1.size();++j){
			if(t1[j] != t2[j]){
				if(d1 == -1) d1 = j;
				d2 = j;
			}
		}
		ans = 0;
		for(int j = 1;j <= n;++j){
			int sl = s1[j].size(),tl = t1.size();
			if(sl < d2 - d1 + 1 || sl > tl) continue;
			for(int k = max(0,d2 - sl + 1);k <= min(d1,tl - sl);++k){
				if(t1[k] == s1[j][0] && t2[k] == s2[j][0]){
					if(s1[j] == t1.substr(k,sl) && s2[j] == t2.substr(k,sl)){
						++ans;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
