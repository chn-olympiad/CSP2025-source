#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(random_device{}());
int rd(int r){return (rnd()%r+r)%r;}
int rd(int l, int r){return l+rd(r-l+1);}

int main()
{
	int n = rd(2,20), m = rd(n-1,100), k = rd(1,10), lw = rd(1,10000), i, j;
	printf("%d %d %d\n", n, m, k);
	for(i=2;i<=n;i++) printf("%d %d %d\n", rd(1,i-1), i, rd(1,lw));
	for(i=1;i<=m-(n-1);i++)
	{
		int u = rd(1,n), v = rd(1,n), w = rd(1,lw);
		while(v==u) v = rd(1,n);
		printf("%d %d %d\n", u, v, w);
	}
	for(i=1;i<=k;i++)
	{
		printf("%d ", rd(1,lw));
		for(j=1;j<=n;j++) printf("%d%c", rd(1,lw), " \n"[j==n]);
	}
	return 0;
}