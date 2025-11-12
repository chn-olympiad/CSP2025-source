#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int l[11];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int len = s.size();
	int cnt = 1;
	for(int i = 0; i <= len - 1; i ++){
		if(s[i] >= '0' && s[i] <= '9'){
			l[s[i] - 48]++;
		}
	}
	for(int k = 9; k >= 0; k--){
		for(int i = 1; i <= l[k]; i++){
			printf("%d", k);
		}
	}
	return 0;
}
