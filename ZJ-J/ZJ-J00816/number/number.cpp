#include <bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	cin.tie();cout.tie();
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= 'a' && s[i] <= 'z')
			continue;
		else
			a[int(s[i] - '0')] += 1;
	}
	for(int i = 9;i >= 0;i--){
		if(a[i] != 0){
			for(int j = 0;j < a[i];j++)
				cout << i;
		}
	}
	return 0;
}
