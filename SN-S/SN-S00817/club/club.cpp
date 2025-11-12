#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

const int N = 1e5+5;

struct node
{
	int id, val, nxt, cur_a, nxt_a;
	bool operator<(const node x) const
	{
		return (val-nxt) > (x.val-x.nxt);
	}	
};

int t, n, ans;
int a[N][4];
//bool vis[N][4];
priority_queue<node> q[4]; 

bool add(node x, int pos)
{
	int tmp;
	
	if(q[pos].size()+1 <= (n/2))
	{
		q[pos].push(x);
//		vis[x.id][pos] = 1;
	}
	else
	{
		node y = q[pos].top();
		if(y.val-y.nxt < x.val-x.nxt)// can replace
		{
			q[pos].pop();
			q[pos].push(x);
//			vis[x.id][pos] = 1;
			for(int i = 1; i <= 3; i++)// find nxt
			{
				if(i != y.cur_a && i != y.nxt_a)
				{
					tmp = i;
					break;
				}
			}
			y.val = y.nxt;
			y.cur_a = y.nxt_a;
			y.nxt = a[y.id][tmp];
			y.nxt_a = tmp;
			add(y, y.cur_a);
		}
		else
			return false;
	}
	return true;
}

void solve()
{
	int i, j, mx, nmx, tmp;
	node x;
	
	ans = 0;
	
	cin >> n;
	for(i = 1; i <= n; i++)
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	for(i = 1; i <= n; i++)
	{
		mx = 0;
		for(j = 1; j <= 3; j++)
			if(a[i][j] >= a[i][mx])
				mx = j;
		nmx = 0;
		for(j = 1; j <= 3; j++)
			if(j != mx && a[i][j] >= a[i][nmx])
				nmx = j;
		x = {i, a[i][mx], a[i][nmx], mx, nmx};
		if(!add(x, mx))
		{
			for(j = 1; j <= 3; j++)
				if(j != mx && j != nmx)
				{
					tmp = j;
					break;
				}
			x = {i, a[i][nmx], a[i][tmp], nmx, tmp};	
//			vis[i][mx] = 1;
			add(x, nmx);
		}
	}
	while(!q[1].empty())
	{
		ans += q[1].top().val;
		q[1].pop();
	}
	while(!q[2].empty())
	{
		ans += q[2].top().val;
		q[2].pop();
	}
	while(!q[3].empty())
	{
		ans += q[3].top().val;
		q[3].pop();
	}
	cout << ans << endl;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> t;
	while(t--)
		solve();
	
	return 0;	
} 
