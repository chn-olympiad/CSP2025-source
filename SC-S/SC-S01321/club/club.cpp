# include<bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;
int n, cnt[N], ans;
priority_queue<int, vector<int>, greater<int>> q[3];
struct node
{
	int x, id;
	pair<int, int> arr[3];
} t[N];

int cmp(node a, node b)
{
	return a.x > b.x;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int TT; cin >> TT;
	while(TT -- )
	{
		cin >> n;
		pair<int, int> a[3];
		for(int i = 1;i <= n;i ++ ) 
		{
			cin >> a[0].first >> a[1].first >> a[2].first;
			a[0].second = 0, a[1].second = 1, a[2].second = 2;
			sort(a, a + 3);
			node tmp; tmp.id = i;
			tmp.x = a[2].first;
			for(int j = 0;j < 3;j ++ ) tmp.arr[j] = a[j];
			t[i] = tmp;
		}
		sort(t + 1, t + n + 1, cmp);
		for(int i = 1;i <= n;i ++ )
		{
			int k = t[i].arr[2].second;
			if(cnt[k] < n / 2)
			{
				ans += t[i].arr[2].first;
				cnt[k] ++ ;
				q[k].emplace(t[i].arr[2].first - t[i].arr[1].first);
			}
			else
			{
				int tmp = t[i].arr[2].first - t[i].arr[1].first;
				if(!q[k].empty())
				{
					if(q[k].top() <= tmp)
					{
						ans += t[i].arr[2].first; 
						ans -= q[k].top(); 
						q[k].pop();
						q[k].emplace(t[i].arr[2].first - t[i].arr[1].first);
					}
					else
					{
						ans += t[i].arr[1].first;
						cnt[t[i].arr[1].second] ++ ;
					}
				}
			}
		}
		cout << ans << "\n";
		for(int i = 0;i < 3;i ++ ) cnt[i] = 0;
		while(!q[0].empty()) q[0].pop();
		while(!q[1].empty()) q[1].pop();
		while(!q[2].empty()) q[2].pop();
		ans = 0;
	}
	return 0;
}