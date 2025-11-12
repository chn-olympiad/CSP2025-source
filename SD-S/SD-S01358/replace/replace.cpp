#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[1005],s2[1005];
string t1,t2; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> s1[i] >> s2[i];
	while(q--){
		cin >> t1 >> t2;
		if(t1.size() != t2.size()){
			puts("0");
			continue;
		}
		int ans = 0;
		for(int i = 0;i < t1.size();i++){
//			for(int j = i;j < t1.size();j++){
				for(int k = 1;k <= n;k++){
					bool flag = 1;
					string s = "";
					for(int l = i;l <= s1[k].size();l++) if(t1[l] != s1[k][l-i]) flag = 0;
					for(int l = 0;l < t1.size();l++){
						if(l < i) s += t1[l];
						if(l >= i&&l < i+s1[k].size()) s += s2[k][l-i];
						if(l >= i+s1[k].size()) s += t1[l];
//						cout << s << " ";
					}
//					for(int l = 0;l < s1[k].size()&&flag;l++){
//						if(l < i&&t1[l] != t2[l]) flag = 0;
//						if(l >= i&&l < i+s1[k].size()&&(s2[k][l-i] != t2[l]||s1[k][l-i] != t1[l])) flag = 0;
//						if(l >= i+s1[k].size()&&t1[l] != t2[l]) flag = 0;
//					}
//					if(i == 1&&k == 1) cout << s2[k][0] << " " << t2[i] << " " << s1[k][0] << " " <<  t1[0] << " ";
					if(s == t2&&flag){
						ans++;
//						cout << i << " " << k << endl;
					}
//					cout << endl << s << " " << i << " " << k << endl << endl;
				}
//			}
		}
		cout << ans << endl;
	}
}
 
