#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int, int>
#define fi first
#define se second
#define pb emplace_back
using namespace std;
const int MAXN = 1e5 + 7;

inline int read()
{
	int x = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
		{
			w = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	
	return w * x;
}

int qa[MAXN], qb[MAXN], qc[MAXN];
int visa[MAXN], visb[MAXN], visc[MAXN];

struct Node{
	int a, b, c;
}pi[MAXN];

bool cmp(Node x, Node y)
{
	if(x.a != y.a)
	{
		return x.a > y.a;
	}
	else if(x.b != y.b)
	{
		return x.b > y.b;
	}
	else
	{
		return x.c > y.c;
	}
}

bool cmp1(int a, int b)
{
	return a > b; 
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t = read();
	
	while(t--)
	{
		int n = read();
		
//		vector<int> qa(n+1);//第一维是abc第二维是人 
//		vector<int> qb(n+1);
//		vector<int> qc(n+1);
		
		memset(qa, 0, sizeof(qa));
		memset(qb, 0, sizeof(qb));
		memset(qc, 0, sizeof(qc));
		bool f1 = 1, f2 = 1;
		for(int i = 1;  i <= n;  i++)
		{
			int ta = read(), tb = read(), tc = read();
			qa[i] = ta, qb[i] = tb, qc[i] = tc;
			pi[i].a = ta, pi[i].b = tb, pi[i].c = tc;
			if(tb != 0 || tc != 0)
			{
				f1 = 0;
			}
			if(tc != 0)
			{
				f2 = 0;
			}
		}
		if(f1)
		{
			sort(qa + 1, qa + n + 1);
			int sum = 0;
			for(int i = n;  i > n/2;  i--)
			{
				sum += qa[i];
			}
			cout<<sum<<endl;
			continue;
		}
//		else if(f2)
//		{
////			
//		}
		else if(n == 2)
		{
			int ans1 = qa[1] + qb[2];
			int ans2 = qa[1] + qc[2];
			int ans3 = qb[1] + qa[2];
			int ans4 = qb[1] + qc[2];
			int ans5 = qc[1] + qa[2];
			int ans6 = qc[1] + qb[2];
			cout<<max(ans1, max(ans2, max(ans3, max(ans4, max(ans5, ans6)))));
		}
		else
		{
//			sort(pi + 1, pi + n + 1, cmp);
			sort(qa + 1, qa + n + 1, cmp1);
			sort(qb + 1, qb + n + 1, cmp1);
			sort(qc + 1, qc + n + 1, cmp1);
			int sum1 = 0, sum2 = 0, sum3 = 0;
//			vector<int> amax(n+1);
//			vector<int> bmax(n+1);
//			vector<int> cmax(n+1);
			for(int i = 1;  i <= n / 2;  i++)
			{
				sum1 += qa[i];
				sum2 += qb[i];
				sum3 += qc[i];
			}
			
			int t;
			int maxx = max(sum1, max(sum2, sum3));
			if(sum1 == maxx)
			{
				t = 1;
			}
			else if(sum2 == maxx)
			{
				t = 2;
			}
			else
			{
				t = 3;
			}
//			cout<<t<<endl;
			int ans = maxx;
			
			if(t == 1)
			{
				for(int i = n/2 + 1;  i <= n;  i++)
				{
					if(pi[i].b >= pi[i].c)
					{
						ans+=pi[i].b;
					}
					else
					{
						ans+=pi[i].c;
					}
				}
			}
			else if(t == 2)
			{
				for(int i = n / 2 + 1;  i <= n;  i++)
				{
					if(pi[i].a >= pi[i].c)
					{
						ans+=pi[i].a;
					}
					else
					{
						ans+=pi[i].c;
					}
				}
			}
			else if(t == 3)
			{
				for(int i = n / 2 + 1;  i <= n;  i++)
				{
					if(pi[i].a >= pi[i].b)
					{
						ans+=pi[i].a;
					}
					else
					{
						ans+=pi[i].b;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
