#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

string s;
int a[100] = {};

int main(){
	
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9') a[s[i] - '0']++;
	}
	
	bool flag = false;
	for(int i = 9; i >= 0; i--){
		if(i == 0 && !flag){
			cout << 0 << "\n";
			break;
		}
		if(a[i]){
			for(int j = 1; j <= a[i]; j++) cout << i;
			flag = true;
		}
	}
	
	return 0;
}

