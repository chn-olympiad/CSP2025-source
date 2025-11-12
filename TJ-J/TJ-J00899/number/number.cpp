#include<bits/stdc++.h>
using namespace std;
int cnt[20];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(auto & x : s){
		if(x >='0' && x <= '9'){
			cnt[x-'0']++;
		}
	}
	
	for(int i = 9 ; i >= 0 ; i--){
		for(int j = 1; j <= cnt[i]; j++){
			cout << i ;
		}
	}
	
	
	
	return 0;
} 
