#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int M = 2000006;
const int N = 1e4+10;
const int K = 15;
int c[K];
int a[K][N];
int fa[N];
int n,m,k;
int krut;
vector<ll> ans;
struct Node
{
	int x,y,z;
} edge[M]; 

void init()
{
	for(int i = 1;i<=n;i++)
	{
		fa[i] = i;
	}
}

int fnd(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = fnd(fa[x]);
}

void unite(int x,int y)
{
	int rx = fnd(x),ry = fnd(y);
	if(rx == ry) return ;
	fa[rx] = ry;
}

bool cmp(Node a, Node b)
{
	return a.z < b.z;
}

ll kru()
{
	init();
	int cnt = 0;
	ll res = 0;
	sort(edge+1,edge+1+krut,cmp);
	for(int i = 1;i<=krut;i++)
	{
		int x = edge[i].x;
		int y = edge[i].y;
		int z = edge[i].z;
		
		//cout << x <<"::" << y << ":" << z <<endl;
		int rx = fnd(x);
		int ry = fnd(y); 
		if(rx != ry)
		{
			unite(x,y);
			cnt++;
			res += z;
			//cout << 111 <<endl;
			//if(cnt == n-1) return res;
		}
	}
	return res;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i<=m;i++)
	{
		cin >> edge[i].x >> edge[i].y >> edge[i].z;
	}
	krut = m;
	if(k == 0)
	{
		cout << kru() << "\n";
		return 0;
	}
	bool flag = 1;
	for(int t = 1;t<=k;t++)
	{
		cin >> c[t];
		if(c[t] != 0) flag = 0;
		for(int i = 1;i<=n;i++)
		{
			cin >> a[t][i];
		}
	}
	if(flag)
	{
		for(int i = 1;i<=k;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				if(i == j) continue;
				krut++;
				edge[krut].x = i;
				edge[krut].y = j;
				edge[krut].z = a[i][j];
			}
		}
		//cout << krut << "\n";
		cout << kru() << "\n";
		return 0;
	}
	ans.push_back(kru());
	for(int i = 1;i<=k;i++)
	{
		krut = m;
		for(int j = 1;j<=n;j++)
		{
			if(i == j) continue;
			krut++;
			edge[krut].x = i;
			edge[krut].y = j;
			edge[krut].z = a[i][j];
		}
		ans.push_back(kru() + c[i] + a[i][i]);
	}
	ll fans = 1e18;
	for(ll xx : ans) fans = min(fans,xx);
	cout << fans<< "\n";
	
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/

