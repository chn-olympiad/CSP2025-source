#include<bits/stdc++.h>
using namespace std;
#define int long long
int tong[15];
signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for(int i = 0;i < s.length();i++){
		char tmp = s[i];
		if('0' <= tmp && '9' >= tmp){
			tong[(tmp-'0')]++;
		}
	}
	bool printed = 0;
	for(int i = 9;i >= 0;i--){
		if(tong[i]){
			if(i){
				printed = 1;
				while(tong[i]--){
					cout << i;
				}
			}else{
				if(printed){
					while(tong[i]--){
						cout << i;
					}
				}
			}
		}
	}
	if(!printed){
		cout << 0 << endl;
	}else{
		cout << endl;
	}
	return 0;
}
