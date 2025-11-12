#include <bits/stdc++.h>
using namespace std;
int n, m;
struct node
{
	int pos;
	int x;
}a[105];
node c[12][12];
bool cmp(node l, node r)
{
	return l.x > r.x;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
	{
		cin >> a[i].x;
		a[i].pos = i;
	}
	int s = n * m;
	sort(a + 1, a + s + 1,cmp);
	int flag = 1;
	int p = 1;
	for(int i = 1;i <= m;i++)
	{
		if(flag == 1)
		{
			for(int j = 1;j <= n;j++)
			{
				if(a[p].pos == 1)
				{
					cout << i << " " << j;
					return 0;
				}
				p += 1;
			}
			flag = 0;
		}
		else if(flag == 0)
		{
			for(int j = n;j >= 1;j--)
			{
				if(a[p].pos == 1)
				{
					cout << i << " " << j;
					return 0;
				}
				p += 1;
			}
			flag = 1;
		}
	}
	return 0;
}
