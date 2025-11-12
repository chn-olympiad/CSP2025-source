# include <bits/stdc++.h>

using namespace std;

string s;
int a, n[20];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdin);
	getline(cin, s);
	for (int i = 0; i < s.size(); i ++){
		if(s[i] >= '0' && s[i] <= '9'){
			a = s[i] - '0';
			n[a] ++;
		}
	}
	
	for(int i = 10; i >= 1; i --){
		for (int j = 1; j <= n[i]; j ++){
			cout << i;
		}
	}
	return 0;
}
