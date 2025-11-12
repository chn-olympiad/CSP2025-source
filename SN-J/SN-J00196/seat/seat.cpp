//考号：SN-J00196 姓名：吴泽铭 学校：白水县城关第一初级中学 
#include <bits/stdc++.h>
using namespace std;
int b[10005];
int main ()
{
	int n,m,num = 0,r = 0;
	cin >> n >> m;
	for (int i = 1;i <= n*m;++i)
	{
		cin >> b[i];
	}
	r = b[1];
	sort(b+1,b+1+n*m);
	reverse(b+1,b+1+n*m);
	int p,q;
	for (int j = 1;j <= n*m;--j)
	{
		if (r == b[j])
		{
			num = j;
			p = num/n+1;
			if (p %2 != 0)
			{
				q = num%n;
			}
			else
			{
				q = n-num%n;
			}
		}
	}
	cout << p  << " "<< q;
	return 0;
}
