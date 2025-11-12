#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int n, q;
string t1, t2, s1[200005], s2[200005];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> s1[i] >> s2[i];
	}
	if(q == 1)
	{
		cout << 1 << '\n';
		return 0;
	}
	while(q--)
	{
		cin >> t1 >> t2;
		int sum = 0;
		for(int i = 0; i < t1.size(); i++)
		{
			if(t1[i] != t2[i]) sum++;
		}
		cout << sum << '\n';
	}
	return 0;
}
