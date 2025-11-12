#include <bits/stdc++.h>
using namespace std;

bool cmp (int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n, m, Long, ascore;
	cin >> n >> m;
	Long = n * m;
	int score[Long + 10] = {};
	for (int i = 1; i <= Long; i++)
		cin >> score[i];
	ascore = score[1];
	sort(score + 1, score + Long + 1, cmp);
	int id;
	for (int i = 1; i <= Long; i++) {
		if (score[i] == ascore)
			id = i;
	}
	int resultm, resultn;

	if (id % n == 0) {
		resultm = id / n;
	} else {
		resultm = id / n + 1;
	}

	if (resultm % 2 == 1) {
		if (id % n != 0)
			resultn = id % n;
		else
			resultn = n;
	} else {
		if (id % n != 0)
			resultn = n + 1 - id % n;
		else
			resultn = 1;
	}

	cout << resultm << " " << resultn;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
