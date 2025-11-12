#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int m = 1;
	int ans = 0;
	int l = s.size();
	for(int i = 1; i <= l; i++){
		if(s[i] % 2 == 1 || s[i] % 2 == 0){
			if(s[i] <= 10){
				ans = s[i];
				break;
			}else{
				ans = s[i];
				if(ans > m){
					
				}
			}
		}
	}
	for(int i = 1; i <= l; i++){
		if(ans > m){
			ans = s[i];
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
