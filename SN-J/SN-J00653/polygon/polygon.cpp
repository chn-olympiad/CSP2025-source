#include <iostream>
#include <vector>
using namespace std;

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	vector<int> arr;
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> tmp;
		arr.push_back(tmp);
	}
	int result = 0;
	for (int i = 0; i < n; i++){
		int temp = 0;
		for (int j = i; j < n; j++){
			temp += arr[j];
			if (temp > arr[j]*2) result += 1;
		}
	}
	
	cout << result << endl;
	
	return 0;
}
