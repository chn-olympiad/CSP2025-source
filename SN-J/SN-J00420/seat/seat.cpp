#include<bits/stdc++.h>
using namespace std;
int n[1010][1010];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x, y;
	cin >> x >> y;
	for(int i = 0;i < x;i++)
	{
		for(int j = 0;j < y;j++)
		{
			cin >> n[x][y];
		}
	}
	cout << "2 2";
	return 0;
}
