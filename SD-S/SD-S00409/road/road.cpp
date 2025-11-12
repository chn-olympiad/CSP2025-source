#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>

using namespace std;

int n,m,k;
long long ans;
long long c[20],a[100005][10];
bool ff = 0;

struct {
	int u,v,w;
}d[100005];

bool cmp()
{
	
}

int da(int a,int b)
{
	
}

void initInput()
{
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		cin >> d[i].u >> d[i].v >> d[i].w;
	}
}

void handle()
{
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	initInput();
	handle();

	return 0;
}

