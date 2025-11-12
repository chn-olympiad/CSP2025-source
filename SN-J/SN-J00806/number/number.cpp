#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int num[10];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(char c : s){
		if(c >= '0' && c <= '9') ++num[c - '0'];
	}
	for(int i = 9; i >= 0; i--){
		for(int j = 1; j <= num[i]; j++)
			cout << i;
	}
	return 0;
}
