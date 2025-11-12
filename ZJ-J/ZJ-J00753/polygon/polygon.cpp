#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000;
const int INF = 998244353;
int ans = 0;
bool isused[MAXN + 100] = {0};
int len;
void add(int l[], int level, int lenmax, int ss, int sset);
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	priority_queue <int> q;
	int n;
	cin >> n;
	int help;
	for(int i = 1; i <= n; i++)
	{
		cin >> help;
		q.push(help);
	}
	int l[MAXN + 100];
	len = q.size();
	int h = 0;
	while(!q.empty())
	{
		h++;
		l[h] = q.top();
		q.pop();
	}
	int lenmax;
	for(int i = 1; i <= len - 2; i++)
	{
		isused[i] = 1;
		lenmax = l[i] * 2;
		add(l, 1, lenmax, l[i], i);
		isused[i] = 0;
	}
	cout << ans << endl;
	return 0;
}
void add(int l[], int level, int lenmax, int ss, int sset)
{
	if(level >= 3 && ss > lenmax)
	{	
		ans++;
		ans %= INF;
	}
	for(int i = sset+1; i <= len; i++)
	{
		if(!isused[i])
		{
			isused[i] = 1;
			add(l, level+1, lenmax, ss+l[i], i);
			isused[i] = 0;
		}
	}
}
