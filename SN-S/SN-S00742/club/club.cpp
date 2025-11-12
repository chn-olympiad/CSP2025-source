//陈安旭 西安滨河学校 SN-S00742 
#include <bits/stdc++.h>
using namespace std;

long long t , n , yi , er , san , qup;
struct rl{
	long long yihao , erhao , sanhao , biaoji = 0;
}a[100010];



signed main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> t;
	while (t--)
	{
		qup = 0;
		cin >> n;
		yi = n / 2;
		er = n / 2;
		san = n / 2;
		for (long long i = 1;i <= n;i++)
		{
			cin >> a[i].yihao >> a[i].erhao >> a[i].sanhao;
			if (max(a[i].yihao , a[i].sanhao , a[i].erhao) == a[i].yihao && yi!= 0)
			{
				a[i].biaoji = 1;
				yi--;
				qup += a[i].yihao;
			}
			if (max(a[i].yihao , a[i].sanhao , a[i].erhao) == a[i].yihao && er!= 0)
			{
				a[i].biaoji = 1;
				er--;
				qup += a[i].erhao;
			}
			if (max(a[i].yihao , a[i].sanhao , a[i].erhao) == a[i].yihao && san!= 0)
			{
				a[i].biaoji = 1;
				san--;
				qup += a[i].sanhao;
			}
		}
		for (long long i = 1;i <= n;i++)
		{
			if (a[i].biaoji != 1)
			{
				if (max(a[i].yihao , a[i].sanhao , a[i].erhao) == a[i].yihao)
				{
					if (max(a[i].erhao , a[i].sanhao) == a[i].erhao && er > 0)
					{
						qup += a[i].erhao;
					}
					if (max(a[i].erhao , a[i].sanhao) == a[i].sanhao && san > 0)
					{
						qup += a[i].sanhao;
					}
				}
				if (max(a[i].yihao , a[i].sanhao , a[i].erhao) == a[i].erhao)
				{
					if (max(a[i].yihao , a[i].sanhao) ==  a[i].yihao && yi > 0)
					{
						qup += a[i].yihao;
					}
					if (max(a[i].yihao , a[i].sanhao) == a[i].sanhao && san > 0)
					{
						qup += a[i].sanhao; 
					}
				}
			}
		}
		cout << qup;	
	}
	return 0;
}
