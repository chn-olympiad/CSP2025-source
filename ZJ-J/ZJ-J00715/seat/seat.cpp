#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m;
struct Node
{
	int sum, i;
	bool operator < (const Node &w) const
	{
		return sum < w.sum;
	}
}a[N];
queue<Node> q;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= (n * m); i ++)
		scanf("%d", &a[i].sum), a[i].i = i;
	sort(a + 1, a + 1 + (n * m));
	for (int i = (n * m); i >= 1; i --)
		q.push(a[i]);
	int ans_n = 1, ans_m = 1;
	bool flag = false;
	while (!q.empty())
	{
		Node st = q.front();
		q.pop();
		if (st.i == 1)
			break;
		if (!flag)
		{
			ans_m ++;
			if (ans_m > m)
			{
				ans_m = m;
				ans_n ++;
				flag = true;
			}
		}
		else
		{
			ans_m --;
			if (ans_m < 1)
			{
				ans_m = 1;
				ans_n ++;
				flag = false;
			}
		}
	}
	printf("%d %d\n", ans_n, ans_m);
	return 0;
}
