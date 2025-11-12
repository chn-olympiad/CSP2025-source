#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
string s1[N], s2[N]; 

int n, q; 
int ans;

namespace Case1{
	bool suf[N];
	
	string t1, t2;
	
	void init(){
		for (int i = 0; i < t1.size(); i++){
			suf[i] = false;
		}	
		
		suf[t1.size()] = true;
		
		for (int i = t1.size() - 1; i >= 0; i--){
			if (t1[i] != t2[i]) break;
			
			suf[i] = true;
		}
		
		ans = 0;
		
		return;
	}
	
	void work(){
		
		while(q--){
			cin >> t1;
			cin >> t2;
			
			if (t1.size() != t2.size()){
				puts("0");
				continue;
			}
			
			init();
			
			for (int i = 1; i <= n; i++){
				for (int j = 0; j < t1.size(); j++){
					if (!suf[j + s1[i].size()]){
						if(t1[j] != t2[j]) break;
						continue;
					}
					for (int len = 0; len < s1[i].size(); len++){
						if (t1[j + len] != s1[i][len]) break;
						if (t2[j + len] != s2[i][len]) break;
						
						if (len == s1[i].size() - 1){
							ans++;
						}
					}
					
					if(t1[j] != t2[j]) break;
				}
			}
			
			printf("%lld\n", ans);					
		}
	} 
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	scanf("%lld%lld", &n, &q);
	
	for (int i = 1; i <= n; i++){
		cin >> s1[i];
		cin >> s2[i];
	}
	
	Case1::work();
	
	return 0;
}