#include <bits/stdc++.h>
using namespace std;

struct node
{
	int x;
	int y;
};
bool cmp(int x,int y)
{
	return x > y;
}
node p[114];
int n,m;
int a[114];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int lmt = n * m;
	for(int i = 1;i <= lmt;i++)
	{
		cin >> a[i];
	}
	int mb = a[1];
	sort(a + 1,a + lmt + 1,cmp);
	
	int jsq = 0;
	for(int j = 1;j <=m;j++)
	{
		if(j % 2 == 1)
		{
			for(int i = 1;i <= n;i++)
			{
				jsq++;
				//cout << j << " " << i << "  ";
				p[jsq].x = j;
				p[jsq].y = i;
			}
		}
		else
		{
			for(int i = n;i >= 1;i--)
			{
				jsq++;
				//cout << j << " " << i << "  ";
				p[jsq].x = j;
				p[jsq].y = i;
			}
		}
	}
	
	
	for(int j = 1;j <= lmt;j++)
	{
		if(mb == a[j])
		{
			cout << p[j].x << ' ' <<p[j].y << "  ";
			break;
		}
	}
	
//	for(int j = 1;j <= lmt;j++)
//	{
//		cout << p[j].x << ' ' <<p[j].y << "  ";
//	}
	


//	for(int i = 1;i <= lmt;i++)
//	{
//		cout << a[i] << ' ';
//	}
	return 0;
}
