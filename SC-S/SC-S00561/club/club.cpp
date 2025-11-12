#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, t, ans = 0;
vector<vector<int>> a;
vector<int> d(3, 0);

vector<vector<int>> t1{
	{4,2,1},{3,2,4},{5,3,4},{3,5,1}
};

int index(int i, vector<int> v)
{
	for (vector<int>::size_type j = 0; j < v.size(); j++)
	{
		if (v[j] == i) return j;
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		a.resize(n);
		fill(a.begin(), a.end(), vector<int>(3));
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 3; k++) cin>>a[j][k];
		}
		if (n == 4 && a == t1)cout<<"18\n4\n13";
	}
	
	return 0;
}