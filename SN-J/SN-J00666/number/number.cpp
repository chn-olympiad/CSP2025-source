#include <bits/stdc++.h>

using namespace std;

string s;

vector<char> num;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	char ch = '0';
	while (ch <= 'z' && ch >= '0') {
		ch = getchar();
		if(isdigit(ch)) num.push_back(ch);
	}
	
	sort(num.begin(), num.end());
	
	int len = num.size();
	for (int i = len - 1; i >= 0; i--) {
		putchar(num[i]);
	}
	return 0;
}
