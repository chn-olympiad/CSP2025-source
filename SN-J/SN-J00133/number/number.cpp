//刘泽辰 SN-J00133 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
string s;
int box[10];

int main() {
	freopen("number4.in", "r", stdin);
	freopen("number4.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i]>='0' && s[i]<='9') {
			int x = int(s[i]) - '0';
			box[x]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		if (box[i] != 0) {
			for (int j = 1; j <= box[i]; j++) {
				cout << i;
			}
		}
	}
	return 0;
}
