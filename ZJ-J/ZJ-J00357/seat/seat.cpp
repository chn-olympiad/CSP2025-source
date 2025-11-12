#include <bits/stdc++.h>
using namespace std;

struct student{
	int score;
	bool is_R;
};

int n, m;
student a[1000];

bool cmp(student a, student b){
	return a.score > b.score;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++){
		cin >> a[i].score;
		a[i].is_R = false;
	}
	a[1].is_R = true;
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++){
		if (a[i].is_R){
			if (i % (2 * n) <= n){
				cout << ceil(1. * i / n) << " " << ((i % n == 0) ? n : i % (2 * n));
			} else {
				cout << ceil(1. * i / n) << " " << ((i % n == 0) ? n : i % (2 * n)) - n + 1;
			}
			break;
		}
	}
	return 0;
}
