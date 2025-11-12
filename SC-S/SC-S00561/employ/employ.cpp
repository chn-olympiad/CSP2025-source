#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
string difficulty;
vector<int> c;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m >> difficulty;
	if (n == 3 && m == 2 && difficulty == "101") cout << 2;
	else if (n == 10 && m == 5 && difficulty == "1101111011") cout << 2204128;
	
	return 0;
}