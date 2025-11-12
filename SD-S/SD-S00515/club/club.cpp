#include <algorithm>
#include <array>
#include <fstream>
#include <vector>

int regc(const std::array<int, 3>& t) {
	int tmp[3]{t[0], t[1], t[2]};
	std::sort(tmp, tmp + 3);
	return tmp[2] - tmp[1];
}

int main() {
	using namespace std;
	ifstream cin("club.in");
	ofstream cout("club.out");
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		auto arr = new array<int, 3>[n];
		vector<int> used[3];
		int res = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
			int mx = max_element(arr[i].begin(), arr[i].end()) - arr[i].begin();
			res += arr[i][mx];
			used[mx].push_back(i);
		}
		auto process = [&] (int id) {
			if(used[id].size() <= n / 2)
				return;
			sort(used[id].begin(), used[id].end(), [&] (int a, int b) {
					return regc(arr[a]) > regc(arr[b]);
			});
			while(used[id].size() > n / 2)
			{
				auto now = arr[used[id].back()];
				int mx = *max_element(now.begin(), now.end()) - regc(now);
				for(int i = 0; i < 3; i++)
					if(i != id && now[i] == mx)
					{
						res -= regc(now);
						used[i].push_back(used[id].back());
						used[id].pop_back();
					}
			}
		};
		process(0);
		process(1);
		process(2);
		cout << res << endl;
		delete[] arr;
	}
	return 0;
}
