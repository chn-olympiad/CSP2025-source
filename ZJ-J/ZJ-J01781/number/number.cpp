#include<bits/stdc++.h>
using namespace std;
int a[11];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.length();
	for(int i = 0; i < n; i++){
		if(s[i]>='0' && s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	int f = 0;
	for(int i = 9; i >= 0; i--){
		if(i == 0){
			if(f == 1){
				for(int j = 1; j <= a[i]; j++){
					f = 1;
					cout << i;
				}
			}else{
				cout << 0;
			}
		}else{
			for(int j = 1; j <= a[i]; j++){
				f = 1;
				cout << i;
			}
		}
	}
	return 0;
}