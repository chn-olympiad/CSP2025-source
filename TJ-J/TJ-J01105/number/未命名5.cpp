#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int cnt = 0, ans = 0;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++){
		if (s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			cnt++;
			a[cnt] = s[i]-'0';
		}
	}
	
	for (int i = 1; i <=cnt; i++){
		for (int j = 1; j <= i; j++){
			if (a[j] < a[i]){
				int n = a[i];
				a[i] = a[j]; 
				a[j] = n;
			}
		}
	}
	
	if (s.length() == 1){
		cout << s[0];
	}
	else{
		for (int i = 1; i <= cnt; i++){
			cout << a[i];
		}
	}
	
	return 0;
}
