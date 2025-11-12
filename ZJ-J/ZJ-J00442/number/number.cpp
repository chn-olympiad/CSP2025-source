#include<bits/stdc++.h>
using namespace std;

int N = 1e6+10;
int a[10];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	
	for(int i = 0; i < s.size(); i++){
		if (s[i] >= '0' && s[i] <= '9') a[s[i]-'0']++;
	}
	
	int cnt = 0;
	for(int i = 1; i<=9; i++){
		cnt += a[i];
	}
	if(cnt == 0){
		cout << 0;
		return 0;
	}
	
	for(int i = 9; i>=0; i--){
		while(a[i]){
			cout << i;
			a[i]--;
		}
	}
	
	return 0;
}
