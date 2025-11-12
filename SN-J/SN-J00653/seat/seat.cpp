#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	vector<int> arr;
	int n, m, R;
	cin >> n >> m;
	for (int i = 0; i < n*m; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	R = arr[0];
	sort(arr.begin(), arr.end());
	int c = 1;
	int r = 1;
	for (int i = n*m-1; i >= 0; i--) {
		if (arr[i] == R) break;
		if (r == n) {
			c++;
			if (c%2 == 0 && arr[i-1] != R) r += 1;
			continue;
		}
		if (c%2 == 1) r+=1;
		else if (c%2 == 0 && arr[i-1] != R) r == 1;
	}
	if (r > n){
		c += 1;
		r -= n;
	}
	cout << c << ' ' << r << endl;
	
	return 0;
}
