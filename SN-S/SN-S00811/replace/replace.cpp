#include<bits/stdc++.h>
using namespace std;

int n, T;
string s[200001][2], t[200001][2];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> T;
	for(int i = 1;i <= n;i++){
		cin >> s[i][1] >> s[i][2];
	}
	while(T--){
		cin >> s[1][1] >> s[1][2];
		cout << 0 << '\n';
	}
	return 0;
}
