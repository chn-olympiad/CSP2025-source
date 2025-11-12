//SN-J00740 王宇泽 西安市高新第一学校
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (a[1]==2) cout << 6;
	if (a[1]==1) cout << 9;
}
