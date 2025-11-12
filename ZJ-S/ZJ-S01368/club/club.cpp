#include <bits/stdc++.h>
#define PII pair <int, int>
#define PIP pair <int, PII>
#define LL long long
#define DB double
#define ST string

#define fr(x, y, z) for(int x = (y); x <= (z); x ++ )
#define dfr(x, y, z) for(int x = (y); x >= (z); x -- )

using namespace std;

const int N = 1e5 + 10;
int T, n, res;
PII a[N][5];

priority_queue <PIP> q[3];
void work(int x, int sk)
{
	fr(k, sk, 2)
	{
		int nc = a[x][k + 1].first - a[x][k].first;
		int j = a[x][k].second;
		if((int)q[j].size() == n / 2)
		{
			if(q[j].top().first > nc)
			{
				PIP t = q[j].top();
				q[j].pop();
				
				q[j].push({nc, {x, k}});
				
				res += t.first;
				work(t.second.first, t.second.second + 1);
				
				break;
			}
			else res += nc;
		}
		else 
		{
			q[j].push({nc, {x, k}});
			break;
		}
	}
}

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	
	while(T -- )
	{
		cin >> n;
		fr(i, 1, n) fr(j, 0, 2)
			cin >> a[i][j].first, a[i][j].second = j;
		
		res = 0;
		fr(i, 1, n)
		{
			sort(a[i], a[i] + 2 + 1, [](PII x, PII y){
				return x.first > y.first; });
			
			res += a[i][0].first;
		}
		
//		cout << "LST:\n";
		fr(j, 0, 2) 
		{
//			cout << j << ':';
			while(q[j].size())
			{
//				cout << q[j].top().second << ' ';
				q[j].pop();
			}
//			cout << '\n';
		}
			
//		cout << "RES:";
		fr(i, 1, n) work(i, 0);
//		, cout << res << ' ';
		
		cout << res << '\n';
	}

	return 0;
}

