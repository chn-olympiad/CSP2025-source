#include <bits/stdc++.h>
using namespace std;

string s;
long long t[10];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	for(long long i = 0; i < sizeof(s)/sizeof(s[0]); i++){
		if(s[i] >= '0' &&s[i] <= '9'){
			t[s[i] - '0']++;
		}
	}
	
	
	for(int i = 9; i >= 0; i--){
		for(long long j = 0; j < t[i]; j++){
			cout << i;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
