#include<bits/stdc++.h>
using namespace std;
#define FINISH
int sum[10];
int main(){
#ifdef FINISH
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
#endif
	string s;
	cin >> s;
	for (int i = 0; i <= s.length(); i++){
		if (isdigit(s[i])){
			sum[s[i] - 48]++;
		}
	}
	for (int i = 9; i >= 0; i--){
		while(sum[i]--){
			putchar(i - '0');
		}
	}
	return 0;
}