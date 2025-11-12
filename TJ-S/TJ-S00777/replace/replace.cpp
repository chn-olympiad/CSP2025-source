#include <bits/stdc++.h>

using namespace std;

int n, q;
string s1[20001], s2[20001];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out" ,"w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
    while(q--)
    {
    	int ans = 0;
    	string t1, t2;
    	cin >> t1 >> t2;
    	for (int i = 1; i <= n; i++)
    	{
    		int x = s2[i].find('b'), y = t1.find('b'), z = t2.find('b');
    		if (z >= y - (t1.size() - 1 - x) && z <= x + y) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
