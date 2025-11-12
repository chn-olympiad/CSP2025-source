#include<bits/stdc++.h>
using namespace std;
const int N = 11;
int tong[N];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s; cin >> s;
//	cout << s.size();
//	return 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i]>='0'&&s[i]<='9'){
			tong[s[i]-'0']++;
		}
	}
	bool flag=false;
	for(int i = 9; i >= 0; i--){
		if(tong[i]!=0){
			if(i!=0) flag=true;
			else{
				if(!flag){
					cout << 0;
					return 0;
				}
			}
			while(tong[i]--) cout << i;
		}
	}
}
