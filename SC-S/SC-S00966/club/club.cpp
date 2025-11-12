//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//#define endl '\n'
//
//const int MAXN = 1e5 + 50;
//struct Node{
//	int num;
//	int id;
//};
//Node a[MAXN];
//
//int sum1 = 0, sum2 = 0, sum3 = 0, ans = 0;
//int x[MAXN], y[MAXN], z[MAXN];
//
//void fz(int x, int y, int z, int i)
//{
//	if(max(x, max(y, z)) == x)
//	{
//		a[i].num = x;
//		a[i].id = 1;
//		return;
//	}
//	if(max(x, max(y, z)) == y)
//	{
//		a[i].num = y;
//		a[i].id = 2;
//		return;
//	}
//	if(max(x, max(y, z)) == z)
//	{
//		a[i].num = z;
//		a[i].id = 3;
//		return;
//	}
//}
//
//bool cmp(Node p, Node q)
//{
//	return p.num > q.num;
//}
//
//
//
//void check(int d)
//{
//	for(int i = 1; i < d; i ++)
//	{
//		if(a[i].id == 1)
//		{
//			int cmmp = a[i].num - max(x[i], z[i]);
//			if(cmmp < a[d].num - max(y[d], z[d]))
//			{
//				ans = ans - a[i].num + max(z[i], y[i]);
//				if(max(z[i], y[i]) == z[i])
//				{
//					sum3 ++;
//				}
//				else
//				{
//					sum2 ++;
//				}
//			}
//			return;
//		}
//		if(a[i].id == 2)
//		{
//			int cmmp = a[i].num - max(x[i], z[i]);
//			if(cmmp < a[d].num - max(x[d],z[d]))
//			{
//				ans = ans - a[i].num + max(x[i], z[i]);
//				if(max(x[i], z[i]) == x[i])
//				{
//					sum1 ++;
//				}
//				else
//				{
//					sum3 ++;
//				}
//			}
//			return;
//		}
//		if(a[i].id == 3)
//		{
//			int cmmp = a[i].num - max(x[i], z[i]);
//			if(cmmp < a[d].num - max(x[d],y[d]))
//			{
//				ans = ans - a[i].num + max(x[i], y[i]);
//				if(max(x[i], y[i]) == x[i])
//				{
//					sum1 ++;
//				}
//				else
//				{
//					sum2 ++;
//				}
//			}
//		}
//		return;
//	}
//}
//
//signed main(){
//	
//	
////	freopen("club.in", "r", stdin);
////	freopen("club.out", "w", stdout);
//
//	
//	int t;
//	cin >> t;
//	
//	while(t--){
//		
//		int n;
//		cin >> n;
//		for(int i = 1; i <= n; i ++)
//		{
//			cin >> x[i] >> y[i] >> z[i];
//			fz(x[i], y[i], z[i], i);
//		}
//		                                	//输入
//		sort(a + 1,a + n + 1,cmp);
//		
//		for(int i = 1; i <= n; i ++)
//		{
//			if(a[i].id == 1 && sum1 + 1 <= n / 2)
//			{
//				sum1 ++;
//				ans += a[i].num;
//			}
//			else if(a[i].id == 1 && sum1 + 1 > n / 2)
//			{
//				if(y[i] > z[i] && sum2 + 1 <= n / 2)
//				{
//					sum2 ++;
//					ans += y[i];
//				}
//				else if(sum2 + 1 > n / 2)
//				{
//					sum3 ++;
//					ans += z[i];
//				}
//			}
//			if(a[i].id == 2 && sum2 + 1 <= n / 2)
//			{
//				sum2 ++;
//				ans += a[i].num;
//			}
//			else if(a[i].id == 2 && sum2 + 1 > n / 2)
//			{
//				if(x[i] > z[i] && sum1 + 1 <= n / 2)
//				{
//					sum1 ++;
//					ans += x[i];
//				}
//				else if(sum1 + 1 > n / 2)
//				{
//					sum3 ++;
//					ans += z[i];
//				}
//			}
//			if(a[i].id == 3 && sum3 + 1 <= n / 2)
//			{
//				sum3 ++;
//				ans += a[i].num;
//			}
//			else if(a[i].id == 3 && sum3 + 1 > n / 2)
//			{
//				if(x[i] > y[i] && sum1 + 1 <= n / 2)
//				{
//					sum2 ++;
//					ans += y[i];
//				}
//				else if(sum1 + 1 > n / 2)
//				{
//					sum2 ++;
//					ans += y[i];
//				}
//			}
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}
/***

1
2
10 9 8
4 0 0

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
***/
//
//#include <bits/stdc++.h>
//using namespace std;
//
//
//#define int long long
//#define endl '\n'
//
//
//const int MAXN = 1e5;
//int t, n, ans;
//
//
//struct Node{
//	int num;
//	int id;
//};
//Node a[MAXN];
//int x[MAXN], y[MAXN], z[MAXN];
//
//
//bool cmp(Node p, Node q)
//{
//	return p.num > q.num;
//}
//
//
//void fz(int x, int y, int z, int i)
//{
//	if(max(x, max(y, z)) == x)
//	{
//		a[i].num = x;
//		a[i].id = 1;
//		return;
//	}
//	if(max(x, max(y, z)) == y)
//	{
//		a[i].num = y;
//		a[i].id = 2;
//		return;
//	}
//	if(max(x, max(y, z)) == z)
//	{
//		a[i].num = z;
//		a[i].id = 3;
//		return;
//	}
//
//
//signed main(){
//	
//	
////	freopen("club.in", "r", stdin);
////	freopen("club.out", "w", stdout);
//
//
//	cin >> t;
//	while(t --)
//	{
//		cin >> n;
//		for(int i = 1; i <= n; i ++)
//		{
//			cin >> x[i] >> y[i] >> z[i];
//			fz(x[i], y[i], z[i]);
//		}
//	}
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int MAXN = 1e5 + 50;
struct Node{
	int num;
	int id;
};
Node a[MAXN];

void fz(int x, int y, int z, int i)
{
	if(max(x, max(y, z)) == x)
	{
		a[i].num = x;
		a[i].id = 1;
		return;
	}
	if(max(x, max(y, z)) == y)
	{
		a[i].num = y;
		a[i].id = 2;
		return;
	}
	if(max(x, max(y, z)) == z)
	{
		a[i].num = z;
		a[i].id = 3;
		return;
	}
}

bool cmp(Node p, Node q)
{
	return p.num > q.num;
}

int x[MAXN], y[MAXN], z[MAXN];

signed main(){
	
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	
	int t;
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
		for(int i = 1; i <= n; i ++)
		{
			cin >> x[i] >> y[i] >> z[i];
			fz(x[i], y[i], z[i], i);
		}
		                                	//输入
		sort(a + 1,a + n + 1,cmp);
		int sum1 = 0, sum2 = 0, sum3 = 0, ans = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(a[i].id == 1 && sum1 + 1 <= n / 2)
			{
				sum1 ++;
				ans += a[i].num;
			}
			else if(a[i].id == 1 && sum1 + 1 > n / 2)
			{
				if(y[i] > z[i] && sum2 + 1 <= n / 2)
				{
					sum2 ++;
					ans += y[i];
				}
				else if(sum2 + 1 > n / 2)
				{
					sum3 ++;
					ans += z[i];
				}
			}
			if(a[i].id == 2 && sum2 + 1 <= n / 2)
			{
				sum2 ++;
				ans += a[i].num;
			}
			else if(a[i].id == 2 && sum2 + 1 > n / 2)
			{
				if(x[i] > z[i] && sum1 + 1 <= n / 2)
				{
					sum1 ++;
					ans += x[i];
				}
				else if(sum1 + 1 > n / 2)
				{
					sum3 ++;
					ans += z[i];
				}
			}
			if(a[i].id == 3 && sum3 + 1 <= n / 2)
			{
				sum3 ++;
				ans += a[i].num;
			}
			else if(a[i].id == 3 && sum3 + 1 > n / 2)
			{
				if(x[i] > y[i] && sum1 + 1 <= n / 2)
				{
					sum2 ++;
					ans += y[i];
				}
				else if(sum1 + 1 > n / 2)
				{
					sum2 ++;
					ans += y[i];
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/***

1
2
10 9 8
4 0 0

***/