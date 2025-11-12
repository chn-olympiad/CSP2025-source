#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	vector<int> arr;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (48 <= (int)s[i] && (int)s[i] <= 57) arr.push_back((int)s[i] - 48);
	}
	sort(arr.begin(), arr.end());
	
	for (int i = arr.size() - 1; i >= 0; i--) cout << arr[i];
	
	
	return 0;
}
