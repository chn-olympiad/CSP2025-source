#include <bits/stdc++.h>
using namespace std;
const int N=1e2 + 5;
int n, m, x, y, a[N];
inline int read()
{
	int x=0, f=1; char ch = getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1; ch = getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch = getchar();}
	return x * f;
}
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(); m=read(); 
	for (int i=1; i<=n*m; i++) a[i] = read();
	int tmp = a[1], p;
	sort(a+1,a+1+n*m, cmp);
	for (int i=1; i<=n*m; i++)
	{
		if (a[i] == tmp){
			p=i;
			break;
		}
	}
//	cout << p << endl;
	int y = p / n, x;
	if (p%n) y++;
//	cout << y << endl;
	if (y&1)
	{
		if (p%n==0) 
		{
			x = m;
		}
		else
		{
			x = p-(y-1)*n;
		}
	}
	else
	{
		if (p%n==0) 
		{
			x = 1;
		}
		else
		{
			x = p-(y-1)*n;
			x = m-x+1;
		}
	}
	printf("%d %d", y, x);
	return 0;
}
