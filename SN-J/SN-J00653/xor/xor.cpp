#include <iostream>
#include <vector>
using namespace std;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	unsigned int n, k;
	cin >> n >> k;
	vector<int> arr;
	int tmp;
	for (int i = 0; i < n; i++){
		cin >> tmp;
		arr.push_back(tmp);
	}
	int result = 0;
	for (int i = 0; i < n; i++){
		if (arr[i] == k) {
			result += 1;
			continue;
		}
		int temp = 0;
		for (int j = i; j < n; j++)	{
			temp ^= arr[j];
			if (temp == k) {
				result += 1;
				i = j;
				break;
			}
		}
	}
	cout << result << endl;
	
	return 0;
}
