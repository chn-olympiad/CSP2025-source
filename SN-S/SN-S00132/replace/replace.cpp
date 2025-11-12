//tyy tyz 8z03
#include <bits/stdc++.h>
using namespace std;
int n , m , qwz1[200005] , qwz2[200005] , hwz1[200005] , hwz2[200005];
pair <string , string> s1[200005] , s2[200005];
int main ()
{
	freopen ("replace.in" , "r" , stdin);
	freopen ("replace.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++)
	{
		cin >> s1[i].first >> s1[i].second;
		for (int j = 0;j < s1[i].first.size ();j ++)
			if (s1[i].first[j] != s1[i].second[j]) hwz1[i] = j;
		for (int j = s1[i].first.size () - 1;j >= 0;j --)
			if (s1[i].first[j] != s1[i].second[j]) qwz1[i] = j;
	}
	for (int i = 1;i <= m;i ++)
	{
		cin >> s2[i].first >> s2[i].second;
		if (s2[i].first.size () != s2[i].second.size ()) continue;
		for (int j = 0;j < s2[i].first.size ();j ++)
			if (s2[i].first[j] != s2[i].second[j]) hwz2[i] = j;
		for (int j = s2[i].first.size () - 1;j >= 0;j --)
			if (s2[i].first[j] != s2[i].second[j]) qwz2[i] = j;
	}
	for (int i = 1;i <= m;i ++)
	{
		if (s2[i].first.size () != s2[i].second.size ())
		{
			cout << "0\n";
			continue;
		}
		int cnt = 0;
		for (int j = 1;j <= n;j ++)
			if (qwz2[i] >= qwz1[j] && hwz2[i] - qwz2[i] == hwz1[j] - qwz1[j])
			{
				bool flag = 1;
				for (int k = 0;k < s1[j].first.size ();k ++)
					if (k + qwz2[i] - qwz1[j] < s2[i].first.size () && s1[j].first[k] == s2[i].first[k + qwz2[i] - qwz1[j]] && s1[j].second[k] == s2[i].second[k + qwz2[i] - qwz1[j]]) continue;
					else
					{
						flag = 0;
						break;
					}
				cnt += flag;
			}
		cout << cnt << "\n";
	}
	return 0;
}
