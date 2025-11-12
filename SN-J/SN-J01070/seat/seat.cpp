#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> scores;
	int a1;
	for (int i = 0; i < n * m; i++) {
		int a;
		scanf("%d", &a);
		scores.push_back(a);
		if (i == 0) {
			a1 = a;
		}
	}
	sort(scores.begin(), scores.end(), [](int a, int b) {
		return a > b;
	});
	int pos = 0;
	for (int i = 0; i < n * m; i++) {
		if (scores[i] == a1) {
			pos = i;
			break;
		}
	}
	pos++;
	int c = pos / n;
	c++;
	int r = pos % n;
	if (r == 0) {
		c--;
		r = n;
	}
	if (c % 2 == 0) {
		r = n + 1 - r;
	}
	cout << c << " " << r << endl;

	return 0;
}
