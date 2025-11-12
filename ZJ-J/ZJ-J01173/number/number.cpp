#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long

using namespace std;

char str[1000008];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> str;
	sort(str, str + strlen(str), greater<char>());
	for (int i = 0; str[i]; i++) {
		if (str[i] < 'a') {
			cout << str + i << "\n";
			break;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

