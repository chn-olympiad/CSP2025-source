#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string s;
int a[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[int(s[i] - '0')]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= a[i]; j++) {
			cout << i;
		}
	}
	return 0;
}

/*
#Shang4Shan3Ruo6Shui4
*/
