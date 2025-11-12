#include <bits/stdc++.h>
#define int long long 
using namespace std;

struct side
{
	int from;
	int to;
	int cost;
	friend operator <(side A, side B)
	{
		return A.cost < B.cost;
	}
};

//priority_queue <side> q;
side sidelist[2000000];

int n, m, k;
//vector <side> graph[20000];

int father[20000];

int get_top(int A)
{
	if (father[A] == A) return A;
	return father[A] = get_top(father[A]);
}

int same(int A, int B)
{
	return get_top(A) == get_top(B);
}

int merge(int A, int B)
{
	father[get_top(A)] = get_top(B);
	return 0;
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		side newside;
		cin >> newside.from >> newside.to >> newside.cost;
		//graph[newside.from].push_back(newside);
		//swap(newside.from, newside.to);
		//graph[newside.from].push_back(newside);
		sidelist[i] = newside;
	}
	//return 0;
	int ntail = m;
	for (int i = 0; i < k; i++)
	{
		int zerocity = 0;
		int cost0 = 0;
		cin >> cost0;
		int costlist[20000];
		for (int j = 1; j <= n; j++)
		{
			cin >> costlist[j];
			if (costlist[j] == 0)
			{
				zerocity = j;
			}
		}
		for (int j = 1; j <= n; j++)
		{
			side newside;
			newside.from = zerocity;
			newside.to = j;
			newside.cost = costlist[j];
			sidelist[m++] = newside;
		}
	}
	
	sort(sidelist, sidelist + m);

	for (int i = 0; i <= n; i++)
	{
		father[i] = i;
	}
	
	int get = 1;
	int cost = 0;
	//return 0;
	for (int i = 0; i < m; i++)
	{
		if (!same(sidelist[i].from, sidelist[i].to))
		{
			merge(sidelist[i].from, sidelist[i].to);
			cost += sidelist[i].cost;
			get++;
		}
		if(get == n)
			break;
	}
	cout << cost << endl;
	
	return 0;
}
/*
5 8 0
1 1 2
1 3 6
1 2 3 
1 4 100
3 4 1
4 5 2
2 3 3
2 4 0
*/
