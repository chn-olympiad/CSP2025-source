#include <iostream>
#include <cstdio>
#include <algorithm>
int t;
using namespace std;
struct node{
	int a,b,c;
	int ma,mi,mn;
	int ga,gi,gn;
}z[100005];
bool cmp(node x, node y)
{
	if (x.a==0&&x.b==0||x.a==0&&x.c==0||x.b==0&&x.c==0)
		return x.mn < y.mn;
	return x.ma > y.ma;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--)
	{
		
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> z[i].a >> z[i].b >> z[i].c;
			z[i].ma = max(max(z[i].a,z[i].b),z[i].c);
				z[i].ga = 1;
			if (z[i].ma == z[i].b)
				z[i].ga = 2;
			if (z[i].ma == z[i].a)
				z[i].ga = 3;
			z[i].mn = min(min(z[i].a,z[i].b),z[i].c);
				z[i].gn = 1;
			if (z[i].mn == z[i].b)
				z[i].gn = 2;
			if (z[i].mn == z[i].a)
				z[i].gn = 3;
			if (z[i].ga != 1 && z[i].gn != 1)
			{
				z[i].gi = 1;
				z[i].mi = z[i].a;
			}
			if (z[i].ga != 2 && z[i].gn != 2)
			{
				z[i].gi = 2;
				z[i].mi = z[i].b;
			}
			if (z[i].ga != 3 && z[i].gn != 3)
			{
				z[i].gi = 3;
				z[i].mi = z[i].c;
			}
		}
		sort (z+1,z+n+1,cmp);
		int p[5]={},manyi = 0;
		for (int i = 1; i <= n; i++)
		{
			if (p[z[i].ga] < n/2)
			{
				p[z[i].ga]++;
				manyi += z[i].ma;
			}
			else if (p[z[i].gi] < n/2)
			{
				p[z[i].gi]++;
				manyi += z[i].mi;
			}
			else if (p[z[i].gn] < n/2)
			{
				p[z[i].gn]++;
				manyi += z[i].mn;
			}
		}
		cout << manyi << endl;
	}                  
	return 0;
}