#include <bits/stdc++.h>
using namespace std;
char s1[1100][2010],s2[1100][2010];
char t1[2010],t2[2010];
int siz1[1100],siz2[1100];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	std::ios::sync_with_stdio(0); 
	int n,q;
	cin >> n >> q; 
	if(n <= 100 && q <= 100){
		for(int i = 1; i <= n; i++){
			cin >> s1[i]+1 >> s2[i]+1;
			siz1[i] = strlen(s1[i]+1);
			siz2[i] = strlen(s2[i]+1);
		}
		
		for(int i = 1; i <= q; i++){
			int ans = 0;
			cin >> t1+1 >> t2+1;
			int len = strlen(t1+1);
			for(int j = 1; j <= n; j++){
				for(int l = 1; l + siz1[j] - 1<= len; l++){
					bool b = 1;
					for(int r = 1; r <= siz1[j]; r++){
						if(t1[r+l-1] != s1[j][r] || t2[r+l-1] != s2[j][r]){
							b = 0;
							break;
						}
					}
					if(b){
						for(int i = 1; i < l; i++){
							if(t1[i]!=t2[i]) b = 0;
						}
						for(int i = l + siz1[j]; i <= len; i++){
							if(t1[i]!=t2[i]) b = 0;
						}
						if(b) ans++;
					}
				}
			}
			cout << ans << endl;
		}		
	}else{
		
	}

	return 0;
} 
