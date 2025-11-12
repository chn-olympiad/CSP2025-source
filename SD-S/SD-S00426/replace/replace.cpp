#include <iostream>
using namespace std;
string s1[200005] , s2[200005];
int main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	int n , q ; cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++) cin >> s1[i] >> s2[i];
	for(int i = 1 ; i <= q ; i ++){
		string x , y ; cin >> x >> y;
		int ans = 0;
		for(int j = 1 ; j <= n ; j ++){
			if(x.size() < s1[j].size()) continue;
			for(int k = 0 ; k <= x.size() - s1[j].size() ; k ++){
				if(x.substr(k , s1[j].size()) == s1[j]){
					string tmp = x.substr(0 , k) + s2[j] + x.substr(k + s1[j].size() , (x.size() - k - s1[j].size()));
					if(tmp == y) ++ ans;
				}
			}
		} cout << ans << endl;
	}
	return 0;
} 
