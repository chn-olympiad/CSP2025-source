#include <bits/stdc++.h>
using namespace std;
int a[101];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//2 2
//99 100 97 98
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> a[i];
	int r = a[1],pos;
//	cout << r << " ";
	sort(a + 1,a + n * m + 1,cmp);
//	for(int i = 1;i <= n * m;i++) cout << a[i] << " ";
	for(int i = 1;i <= n * m;i++)
	{
		if(a[i] == r)
		{
			pos = i;
			break;
		}
	}
//	cout << pos << endl << endl;
	int x = 1,y = 1;
	bool f = 0;
	for(int i = 1;i < pos;i++)
	{
//		cout << x << " " << y << endl;
		if(!f)
		{
			if(x + 1 > n) y++,f = 1;
			else x++;
		}
		else
		{
			if(x - 1 < 1) y++,f = 0;
			else x--;
		}
	}
	cout << y << " " << x;
	return 0;
}
//3 3
//94 95 96 97 98 99 100 93 92
//#Shang4Shan3Ruo6Shui4
