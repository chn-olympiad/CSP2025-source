#include<bits/stdc++.h>
using namespace std;
int a[1000010], c;
string s;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	cin >> s;
	int len = s.size(), ans = 0;
	for(int i = 0; i < len; i++){
		if(s[i] >= 48 && s[i] <= 57){
			c = s[i] - '0';
			a[c]++;
		}
	}
	for(int k = 9; k >= 0; k--){
		for(int i = 1; i <= a[k]; i++){
			cout << k;
		}
	}
	return 0;
} 
