#import <iostream>
using namespace std;
int n, m;
int sum[n * m];

int main() {
	cin >> n >> m;
	for (int x = 0; x < n * m, x++) {
		cin >> sum[x];
	}
	cout << n << " " << m << endl;
}