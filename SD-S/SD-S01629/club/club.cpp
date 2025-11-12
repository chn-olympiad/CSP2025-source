#include<bits/stdc++.h>
using namespace std;
const long long N = 1e5+50;
long long n;
struct node
{
	long long a,b,c;
	long long op;
}val[N];
long long T;
long long cnta,cntb,cntc;
long long ans;
long long da[N];//1 val
long long cnt=0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
		memset(da,0,sizeof(da));
		cnta = 0;
		cntb = 0;
		cntc = 0;
		ans = 0;
		for(int i = 1;i <= n;i++)
		{
			cin >> val[i].a >> val[i].b >> val[i].c;
		}
		for(int i = 1;i <= n;i++)
		{
			if(val[i].a >= val[i].b && val[i].a >= val[i].c)
			{
				ans += val[i].a;
				val[i].op = 1;
				cnta++;
			}
			else if(val[i].b >= val[i].a && val[i].b >= val[i].c)
			{
				ans += val[i].b;
				val[i].op = 2;
				cntb++;
			}
			else
			{
				ans += val[i].c;
				val[i].op = 3;
				cntc++;
			}
		}
		cnt = 0;
		if(cnta > (n/2))
		{
			for(int i = 1;i <= n;i++)
			{
				if(val[i].op == 1)
				{
					long long tb=val[i].b-val[i].a;
					long long tc=val[i].c-val[i].a;
					if(tb > tc)
					{
						da[++cnt] = tb;
					}
					else
					{
						da[++cnt] = tc;
					}
				}
			}
			sort(da+1,da+1+cnta);
			for(int i = cnt;i >= 1 && cnta > (n/2);i--)
			{
				ans += da[i];
				cnta--;
			}
		}
		else if(cntb > (n/2))
		{
			for(int i = 1;i <= n;i++)
			{
				if(val[i].op == 2)
				{
					long long ta=val[i].a-val[i].b;
					long long tc=val[i].c-val[i].b;
					if(ta > tc)
					{
						da[++cnt] = ta;
					}
					else
					{
						da[++cnt] = tc;
					}
				}
			}
			sort(da+1,da+1+cntb);
			for(int i = cnt;i >= 1 && cntb > (n/2);i--)
			{
				ans += da[i];
				cntb--;
			}
		}
		else if(cntc > (n/2))
		{
			for(int i = 1;i <= n;i++)
			{
				if(val[i].op == 3)
				{
					long long ta=val[i].a-val[i].c;
					long long tb=val[i].b-val[i].c;
					if(ta > tb)
					{
						da[++cnt] = ta;
					}
					else
					{
						da[++cnt]= tb;
					}
				}
			}
			sort(da+1,da+1+cntc);
			for(int i = cnt;i >= 1 && cntc > (n/2);i--)
			{
				ans += da[i];
				cntc--;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

