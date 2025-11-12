#include<bits/stdc++.h>
using namespace std;
int t, n;
long long sum;
struct node{
	int a, b;
	bool max_a;
	bool operator < (const node &other)	const{
		if (max_a != other.max_a)	return max_a;
		if (max_a == 1)	return a > other.a;
		if (b == other.b)	return a > other.a;
		return b < other.b;
	}
}p[100005];
int main()	{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--)	{
		cin >> n;
		sum = 0;
		for (int i = 1; i <= n; ++i)	{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			sum += c;
			p[i].a = a - c;
			p[i].b = b - c;
			p[i].max_a = (p[i].a > p[i].b) ? 1 : 0;
		}
		sort(p + 1, p + n + 1);
		int l = 1, r = n;
		while (l <= r)	{
			if ((p[l].a < 0 || l == n / 2 + 1) && (p[r].b < 0 || r == n / 2))	break;
			if ((p[l].a >= p[r].b || r == n / 2) && l <= n / 2 && p[l].a >= 0)	{
				sum += p[l].a;
				l++;
			}
			else if (r > n / 2 && p[r].b >= 0)	{
				sum += p[r].b;
				r--;
			}
		}
		while (r - l >= n / 2)	{
			if (p[l].a >= p[r].b && l <= n / 2 || r == n / 2)	{
				sum += p[l].a;
				l++;
			}
			else if (p[l].a < p[r].b && r > n / 2 || l == n / 2 + 1)	{
				sum += p[r].b;
				r--;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
