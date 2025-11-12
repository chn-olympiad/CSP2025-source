#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int n, q;
struct node
{
	string s1, s2;
} a[200005];
void solve()
{
	string t1, t2;
	cin >> t1 >> t2;
	if (t1.size() != t2.size())
	{
		cout << "0\n";
		return ;
	}
	int start = 0, end = 0;
	for (int i = 0; i < t1.size(); i++)
	{
		if (t1[i] != t2[i])
		{
			end = i;
			if (t1[i-1] == t2[i-1] && !start)
			{
				start = i;
			}
			else if (t1[i-1] == t2[i-1] && start)
			{
				cout << "0\n";
				return ;
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		string tmp = t1;
		int p = t1.find(a[i].s1);
		while (p != string::npos)
		{
			tmp.replace(p, a[i].s1.size(), a[i].s2);
			if (tmp == t2)
			{
				sum++;
			}
			tmp = t1;
			p = t1.find(a[i].s1, p+1);
		}
	}
	cout << sum << "\n";
	return ;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].s1 >> a[i].s2;
	}
	while (q--)
	{
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
