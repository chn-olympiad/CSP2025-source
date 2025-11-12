//SN-J00100  刘尚尧  渭南初级中学 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110][110];
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			cin >> a[i][j];
		}
	}
	cout << n << m;
	return 0;
}
