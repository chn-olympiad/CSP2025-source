#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n;
LL res;
int cnt1, cnt2, cnt3;

int max(int x, int y, int z)
{
	return max(x, max(y, z));
}
int min(int x, int y, int z)
{
	return min(x, min(y, z));
}
int mid(int x, int y, int z)
{
	return x + y + z - max(x, y, z) - min(x, y, z);
}
struct Node
{
	int a, b, c, d;
	bool operator < (const Node &w) const
	{
		return d >= w.d;
	}
}node[N]; 

void work()
{
	res = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
	memset(node, 0, sizeof node);
	scanf("%d", &n);
	int x, y, z;
	
	for(int i = 1; i <= n; i ++) 
	{
		scanf("%d%d%d", &x, &y, &z);
		node[i] = {x, y, z, max(x, y, z) - mid(x, y, z)};
	}
	sort(node + 1, node + n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int a = node[i].a, b = node[i].b, c = node[i].c;
		if(a == max(a, b, c))
		{
			if(cnt1 < n / 2) cnt1 ++, res += a;
			else if(b == mid(a, b, c)) cnt2 ++, res += b;
			else cnt3 ++, res += c;  
		}
		else if(b == max(a, b, c))
		{
			if(cnt2 < n / 2) cnt2 ++, res += b;
			else if(a == mid(a, b, c)) cnt1 ++, res += a;
			else cnt3 ++, res += c;  
		}
		else if(c == max(a, b, c))
		{
			if(cnt3 < n / 2) cnt3 ++, res += c;
			else if(b == mid(a, b, c)) cnt2 ++, res += b;
			else cnt1 ++, res += a;  
		}	
	}
	cout << res << endl;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	cin >> t;
	while(t --) work();
	
	return 0;
}
