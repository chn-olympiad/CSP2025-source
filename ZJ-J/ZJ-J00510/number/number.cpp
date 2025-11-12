#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int n;
int t[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> (s+1);
	n = strlen(s+1);
	for(int i = 1;i <= n;i++){
		if('0' <= s[i] && s[i] <= '9') t[s[i] - '0']++;
	}
	for(int i = 9;i >= 0;i--){
		for(int j = 1;j <= t[i];j++) cout << i;
	}
	cout << endl;
	
	return 0;
}