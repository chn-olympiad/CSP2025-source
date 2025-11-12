#include <bits/stdc++.h>
#include <string>
using namespace std;

int n,q;
map<string,string> dir;
set<int> mlen;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;
	for(int i = 1; i <=n; i++){
		string s1,s2;
		cin >> s1 >> s2;
		mlen.insert(s1.size());
		dir[s1] = s2;
	}
	string s1,s2,tmp,tmp2;
	int ans = 0;
	while(q--){
		ans = 0;
		cin >>s1 >>s2;
		
		for(auto item : dir){
			int l = s1.find(item.first);
			if(l >= s1.size())continue;
			bool is = 0;
			for(int i = 0 ; i < s1.size(); i++){
				if(i >= l && i <= l+item.first.size()-1){
					if(item.second[i-l] != s2[i]){
						is = 1;
						break;
					}
				}
				else{
					
					if(s1[i] != s2[i]){
						is = 1;
						break;
					}
				}
			}
			if(!is)ans++;
		}
		
		cout << ans << '\n';
	}
		
	return 0;
}

