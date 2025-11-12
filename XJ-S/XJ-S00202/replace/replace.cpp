#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3],t[3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		cin >> s[i][1] >> s[i][2];
	while(q--){
		cin >> t[1] >> t[2];
		string x,y,z;
		int ans=0;
		for(int len = 1; len <= t[1].size(); len++){
			for(int i = 0; i+len-1 < t[1].size(); i++){
				int j = i+len-1;
				for(int k = 1; k <= n; k++){
					int xb=0;
					bool flag=false;
					for(int v = i; v <= j; v++,xb++){
						if(t[1][v]!=s[k][1][xb]){
							flag=false;
							break;
						}
					}
					xb=0;
					if(flag){
						for(int v = i; v <= j; v++,xb++){
							if(t[2][v]!=s[k][2][xb]){
								flag=false;
								break;
							}
						}
						if(flag) ans++;
					}
				}
			} 
		}
		cout << ans << endl;
	}
	return 0;
} 
