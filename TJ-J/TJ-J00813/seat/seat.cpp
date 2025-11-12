#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105;

int n, m;
int p;
int a[N];
int ans_line, ans_row;
int rk = 1;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	//printf("%d %d\n", n, m);
	for(int i = 1; i <= n * m; i++)
	{
		scanf("%d", &a[i]);
	//	printf("%d\n", a[i]);
	}
	for (int i = 2; i <= n * m; i++)
	{
		//printf("%d\n", a);
		if (a[i] >  a[1])
			rk++;
	}
	//printf("%d \n", rk);
	
	int u = rk / n, v = rk % n;
	
	
	if (v==0)
	{
	//	printf("%d %d end_of_line\n", u, v);
		if (u%2==1)
		{
			ans_row = u;
			ans_line = n;
		}
		else
		{
			ans_row = u;
			ans_line = 1;
		}
	}
	else
	{
	//	printf("%d %d\n", u, v);
	//	printf("%d\n", n-v + 1);
		if ((u+1)%2==1)
		{
			ans_row = u+1;
			ans_line = v;
		}
		else
		{
			ans_row = u+1;
			ans_line = n-v+1;
		}
	}
	
	printf("%d %d", ans_row, ans_line);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
