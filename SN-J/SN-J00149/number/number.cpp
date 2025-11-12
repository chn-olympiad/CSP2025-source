#include <iostream>
#include <cstdio>
using namespace std;

string x;
int num[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> x;
	for (int i = 0;i < x.length();i++) {
		if (x[i] >= '0' && x[i] <= '9') {
			num[x[i] - 48]++;
		}
	}
	
	for (int i = 9;i >= 0;i--) {
		for (int j = 0;j < num[i];j++) {
			printf("%d", i);
		}
	}
	
	return 0;
}
