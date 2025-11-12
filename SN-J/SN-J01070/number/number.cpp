#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
using namespace std;

int main() {
	string str;
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	str.resize(1e6+5);
	scanf("%s", (char*)str.data());
	vector<int> numbers;
	for (char ch : str) {
		if ('0' <= ch && ch <= '9') {
			numbers.push_back(ch - '0');
		}
	}
	sort(numbers.begin(), numbers.end(), [](int a, int b) {
		return a > b;
	});
	for (int number : numbers) {
		printf("%d", number);
	}
	printf("\n");
	
	return 0;
}
