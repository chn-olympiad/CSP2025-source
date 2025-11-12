#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 100010, M = 1000010;
int n, m, fa[N], tail, k;
struct node{
 long long x, y, c;	
}d[M];

struct node2{
	int x[N];
	long long c;
}ct[20];
int find(int x)
{
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}

int lian()
{
	int s = find(1);
	for(int i = 2; i <= n; i ++ )
		if(find(i) != s) return 0;
	return 1;
}

void add(int xx, int yy, long long zz)
{
	d[++tail].x = xx;
	d[tail].y = yy;
	d[tail].c = zz;
}

bool cmp(node aa,node bb)
{
	return aa.c < bb.c;
}

long long chu()
{
	for(int i = 1; i <= n; i ++ )
		fa[i] = i;
	
	sort(d+1, d+tail+1, cmp);
	
	long long ans = 0;
	
	int head = 0;
	while(lian() == 0)
	{
		head ++;
		int xx = find(d[head].x), yy = find(d[head].y);
		if(xx != yy)
		{
			ans += d[head].c;
			fa[xx] = yy;
		}
	}
	return ans;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++ )
		{
			int x, y, z;
			cin >> x >> y >> z;
			add(x, y, z);
		}
	
	//接下来要做的就是，在更新边的同时去掉以前不要的边啊啊啊好麻烦
	if(k == 0)
	{
		cout << chu();
		return 0;
	} 
	int aas = 0;
	int t = 1;
	for(int i = 1; i <= k; i ++ )
		{
			cin >> ct[i].c;
			aas += ct[i].c;
			for(int j = 1; j <= n; j ++ )
				{
					cin >> ct[i].x[j];
				}
			if(ct[i].c != 0)
			{
				t = 0;
			}
		}
		for(int i = 1; i <= k; i ++ )
		{
			for(int j = 1; j <= n; j ++ )
			for(int l = j+1; l <= n; l ++)
					add(j, l, ct[i].x[j]+ct[i].x[l]);
		}
	
		cout << aas + chu();
	return 0;//Ren5Jie4Di4Ling5%
 }

