#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#define MAXN 5001
using namespace std;
int n, a[MAXN];
set<vector<int> > st;
void dfs(int num, int sum, int maxn, int idx, vector<int> vec)
{
	if (num >= 3 && sum > 2 * maxn)
	{
		st.insert(vec);
		// cerr << num << " " << sum << " " << maxn << " " << idx << endl;
		// for (int  i = 0; i < vec.size(); i++)
		// 	cerr << vec[i] << " ";
		// cerr << endl;
	}
	if (idx >= n)
		return ;
	for (int i = idx + 1; i <= n; i++)
	{
		vector<int> vec0(vec);
		vec0.push_back(i);
		dfs(num + 1, sum + a[i], max(maxn, a[i]), i, vec0);
		dfs(num, sum, maxn, i, vec);
	}
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	dfs(0, 0, 0, 0, vector<int>());
	// set<vector<int> > :: iterator it;
	// for (it = st.begin(); it != st.end(); it++)
	// {
	// 	for (int i = 0; i < (*it).size(); i++)
	// 		cerr << (*it).at(i) << " ";
	// 	cerr << endl;
	// }
	printf("%d\n", (int)st.size());
	return 0;
}