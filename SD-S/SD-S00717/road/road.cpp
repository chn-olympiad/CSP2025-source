#include<bits/stdc++.h>
using namespace std;
const long long N = 1e18;
struct node
{
	int x,y;
	long long w;
	friend bool operator <(const node a,const node b)
	{
		return a.w < b.w;
	}
};
node e[10050];
int v[10050];
long long a[10050];
long long n,m,k,z,c,cnt,ans;
int x,y;
long long fa[10050];
void init()
{
	for(int i = 0;i <= n;i++)fa[i] = i;
	return;
}
int _find(int x)
{
	if(fa[x] == x)return x;
	else 
	{
		fa[x] = _find(fa[x]);
		return fa[x];
	}
}
void _merge(int x,int y)
{
	int fx = _find(x);
	int fy = _find(y);
	fa[fx] = fy;
	return;
}
long long kr(int zh)
{
	ans = 0;
	cnt = 0;
	init();
	sort(e + 1,e + c + 1);
	for(int i = 1;i <= c;i++)
	{
		if(_find(e[i].x) == _find(e[i].y))continue;
		cnt++;
		_merge(e[i].x,e[i].y);
		ans += e[i].w;
		if(cnt == zh)return ans;
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)a[i] = N;
	for(int i = 1;i <= m;i++)
	{
		cin >> x >> y >> z;
		e[++c] = {x,y,z};
	}
	for(int i = 1;i <= k;i++)
	{
		cin >> x;
		for(int j = 1;j <= n;j++)
		{
			cin >> z;
			a[j] = min(a[j],z);
		}
	}
	long long minn = kr(n - 1);
	for(int i = 1;i <= n;i++)
	{
		e[++c] = {0,i,a[i]};
	}
	minn = min(minn,kr(n));
	cout << minn << "\n";
	return 0;
}
/*

4 3 1
1 2 4
2 3 4
3 4 4
0 0 0 0 0

4 4 2
1 4 1
2 3 7
4 2 5
4 3 4
0 6 8 2 3
0 1 6 2 4

5 5 2
1 2 2
1 3 3
2 3 1
3 4 1
2 5 3
0 4 4 6 9 4
0 5 7 4 4 4

5 5 2
1 2 999999999
1 3 999999999
2 3 999999998
3 4 999999999
2 5 999999999
0 1000000000 1000000000 1000000000 1000000000 1000000000
0 1000000000 1000000000 1000000000 1000000000 1000000000

5 5 2
1 2 999999999
1 3 999999999
2 3 999999998
3 4 999999999
2 5 999999999
0 999999997 1000000000 1000000000 1000000000 1000000000
0 1000000000 1000000000 1000000000 1000000000 1
没时间了 
*/

