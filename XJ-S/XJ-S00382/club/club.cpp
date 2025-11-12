#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Human
{
	int a;
	int b;
	int c;
	int maxn, maxi;
	int minn, mini;
	int lastn, lasti;
};

int t, a[100010], b[100010], c[100010];
Human people[100010];

bool cmp(Human x, Human y)
{
	return x.maxn > y.maxn;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
	while (t > 0)
	{
		int n;
		cin >> n;
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		memset(c, 0, sizeof c);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i] >> b[i] >> c[i];
			people[i].a = a[i];
			people[i].b = b[i];
			people[i].c = c[i];
			if (a[i] > b[i] && a[i] > b[i])
		}
		sort(people, people + n);
		int a_count = 0, b_count = 0, c_count = 0, answer;
		for (int i = 0; i < n; i++)
		{
			if (people[i].maxi == 0 && a_count < n / 2)
			{
				a_count++£»
				answer += people[i].maxn;
			}
		}
		cout << 0 << endl; 
		t--;
	} 
    return 0;
}
