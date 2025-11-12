#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

map <int, vector <pair <string, string> > > res;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
	{
		string s1, s2;
		cin >> s1 >> s2;
		if (s1 == s2) continue;
		int l = 0, r = (int)s1.size();
		for (int i = 0; i < (int)s1.size(); ++i)
		{
			if (s1[i] != s2[i]) break;
			++l;
		}
		for (int i = (int)s1.size() - 1; i >= 0; --i)
		{
			if (s1[i] != s2[i]) break;
			--r;
		}
		string new_s1, new_s2;
		for (int i = l; i < r; ++i)
		{
			new_s1 += s1[i];
			new_s2 += s2[i];
		}
		res[(int)new_s1.size()].push_back({new_s1, new_s2});
	}
	
	while(q--)
	{
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size())
		{
			cout << 0 << endl;
			continue;
		}
		int l = 0, r = t1.size();
		for (int i = 0; i < n; ++i)
		{
			if (t1[i] != t2[i]) break; 
			++l;
		}
		for (int i = t1.size() - 1; i >= 0; --i)
		{
			if (t1[i] != t2[i]) break;
			--r;
		}
		string new_t1, new_t2;
		for (int i = l; i < r; ++i)
		{
			new_t1 += t1[i];
			new_t2 += t2[i];
		}
		int len = r - l;
		if (res.find(len) == res.end())
		{
			cout << 0 << endl;
			continue;
		}
		int ans = 0;
		if (res.find(len) == res.end())
		{
			cout << 0 << endl;
			continue;
		}  
		for (int i = 0; i < (int)res[len].size(); ++i)
		{
			if (new_t1 == res[len][i].first && new_t2 == res[len][i].second) ++ans;
		}
		cout << ans << endl;
	}
	return 0;
}

