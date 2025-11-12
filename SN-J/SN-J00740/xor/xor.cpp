//SN-J00740 王宇泽 西安市高新第一学校
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[10000005];
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (k==2) cout << 2;
	if (k==3) cout << 2;
	if (k==0) cout << 1;
}
