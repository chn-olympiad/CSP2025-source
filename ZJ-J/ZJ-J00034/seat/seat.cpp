#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d" ,&n,&m);
	int a1;
	scanf("%d" ,&a1);
	int cnt = 1;
	for(int i = 2;i <= n * m;i++)
	{
		int a;
		scanf("%d" ,&a);
		if (a > a1)
		{
			cnt++;
		}
	}
	int x,y;
	if(cnt % n != 0)
	{
		x = cnt / n + 1;
	}
	else
	{
		x = cnt / n;
	}
	if (x % 2 == 0)
	{
		y = n - (cnt - 1) % n;
	}
	else
	{
		y = (cnt - 1) % n + 1;
	}
	printf("%d %d" ,x,y);
	return 0;
}
