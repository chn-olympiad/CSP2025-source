#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long
using namespace std;

int n, m;
struct node {
	int id, date;
} arr[50];

bool cmp(node a, node b){
	return a.date > b.date;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	fast;
	cin >> n >> m;
	for (int i = 1;i <= n * m;i ++){
		cin >> arr[i].date;
		arr[i].id = i;
	}
	sort(arr + 1, arr + 1 + n * m, cmp);
	int c = 1, r = 1;
	if (arr[1].id == 1){
		cout << 1 << " " << 1 << endl;
		return 0;
	}
	bool f = false;
	int idx = 1;
	while (arr[idx ++].id != 1){
		if (!f){
			c ++;
			if (c > n){
				c = n;
				r ++;
				f = !f;
			}
		} else {
			c --;
			if (c < 1){
				c = 1;
				r ++;
				f = !f;
			}
		}
	}
	cout << r << " " << c << endl;
	return 0;
}
