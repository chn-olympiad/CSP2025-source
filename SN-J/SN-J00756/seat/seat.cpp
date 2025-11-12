// SN-J00756 王昭云 西安市曲江第一学校
#include <bits/stdc++.h>

using namespace std;

int n,m,r,c;

struct student
{
	int score,id;
}a[105];

bool cmp(student a,student b)
{
	return a.score > b.score;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n * m;i++)
	{
		scanf("%d",&a[i].score);
		a[i].id = i;
	}
	sort(a + 1,a + m * n + 1,cmp);
	for(int i = 1;i <= n * m;i++)
	{
		if(a[i].id == 1)
		{
			c = r = 0;
			c = ceil((double)i / n);
			if(c % 2 == 1)
			{
				r = i % n;
				if(r == 0)
					r = n;
			}
			else
			{
				r = m - i % n + 1;
				if(r == 0)
					r = 1; 
			}
		}
	}
	cout << c << ' ' << r;
	return 0;
}
