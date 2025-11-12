#include<bits/stdc++.h>
using namespace std;

int arr[225];
int res;

int my_n,my_m;

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> my_n >> my_m;
	for(int i = 1; i <= my_n * my_m; ++i) {
		cin >> arr[i];
	}
	res = arr[1];
	sort(arr + 1,arr + 1 + my_n * my_m);
	reverse(arr + 1,arr + 1 + my_n * my_m);
	for(int i = 1; i <= my_n * my_m; ++i) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	for(int i = 1; i <= my_n * my_m; ++i) {
		if(arr[i] == res) {
			cout << i / my_n + i % my_n << ' ';
			if(i % my_m == 0) cout << my_m;
			else cout << i % my_m;
			return 0;
		}
	}
	return 0;
} 
