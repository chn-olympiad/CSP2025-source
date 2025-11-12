#include <iostream>
#include <cstdio>

using namespace std;

struct stu
{
	int u, v, w;
} a[1000005];

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
}
