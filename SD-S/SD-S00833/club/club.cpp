//#include <bits/stdc++.h>
//using namespace std;
//bool cmp1(ren aa,ren bb)
//{
//	return (aa.a > bb.a) ? 1 : 0;
//}
//bool cmp2(ren aa,ren bb)
//{
//	return (aa.b > bb.b) ? 1 : 0;
//}
//bool cmp3(ren aa,ren bb)
//{
//	return (aa.c > bb.c) ? 1 : 0;
//}
//const int maxn = 1e5+5;
//struct ren
//{
//	int a,b,c,f;
//} R[maxn];
//
//long long sum1,sum2,sum3;
//int main()
//{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
//	int t;
//	cin >> t;
//	while(t--)
//	{
//		int n;
//		cin >> n;
//		int x = n / 2;
//		for(int i = 1;i <= n;i++)
//		{
//			cin >> R[i].a >> R[i].b >> R[i].c;
//			R[i].f = i;
//		}
//		if(n == 2)
//		{
//			ans = max(max(R[1].a + R[2].b,R[1].a + R[2].c),max(max(R[1].b + R[2].a,R[1].b + R[2].c),max(R[1].c + R[2].a,R[1].c + R[2].b));
//			cout << ans << endl;
//			ans = 0;
//			continue;
//		}
////		sort(R + 1,R + 1 + n,cmp1);
////		//int flag1[x+1];
////		for(int i = 1;i <= x;i++)
////		{
////			sum1 += R[i].a;
////		}
////		
////		sort(R + 1,R + 1 + n,cmp2);
////		//int flag1[x+1];
////		for(int i = 1;i <= x;i++)
////		{
////			sum2 += R[i].b;
////		}
////		
////		sort(R + 1,R + 1 + n,cmp3);
////		//int flag1[x+1];
////		for(int i = 1;i <= x;i++)
////		{
////			sum3 += R[i].c;
////		}
////		ans += max(max(sum1,sum2),sum3);
////		if()
//		sort(R + 1,R + 1 + n,cmp1);
//		
//	}
//
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return (a > b) ? 1 : 0;
}
const int maxn = 1e5+5;
int a[maxn],b[maxn],c[maxn];
long long sum1,sum2,sum3;
long long ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int x = n / 2;
		
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		ans = 0,sum1 = 0,sum2 = 0,sum3 = 0;
		
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i] >> b[i] >> c[i];
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		
		if(n == 2)
		{
			ans = max(max(a[1] + b[2],a[1] + c[2]),max(a[2] + b[1],a[2] + c[1]));
			cout << ans << endl;
			ans = 0;
			continue;
		}
		
		for(int i = 1;i <= x;i++)
		{
			sum1 += a[i];
			sum2 += b[i];
			sum3 += c[i];
		}
		ans += max(max(sum1,sum2),sum3);
		if(sum1 >= sum2 && sum1 >= sum3)
		{
			sum1 = 0,sum2 = 0,sum3 = 0;
			n = n - x - 1;
			for(int i = 1;i <= n;i++)
			{
				//sum1 += a[i];
				sum2 += b[i];
				sum3 += c[i];
			}
			ans += max(sum2,sum3);
			if(sum2 > sum3)
				ans += c[1];
			else if(sum2 == sum3)
				ans += max(b[1],c[1]);
			else
				ans += b[1];
			cout << ans << endl;
			continue;
		}
		
		else if(sum2 >= sum1 && sum2 >= sum3)
		{
			sum1 = 0,sum2 = 0,sum3 = 0;
			n = n - x - 1;
			for(int i = 1;i <= n;i++)
			{
				sum1 += a[i];
				//sum2 += b[i];
				sum3 += c[i];
			}
			ans += max(sum1,sum3);
			if(sum1 > sum3)
				ans += c[1];
			else if(sum1 == sum3)
				ans += max(a[1],c[1]);
			else
				ans += a[1];
			cout << ans << endl;
			continue;
		}
		else if(sum3 >= sum2 && sum3 >= sum2)
		{
			sum1 = 0,sum2 = 0,sum3 = 0;
			n = n - x - 1;
			for(int i = 1;i <= n;i++)
			{
				sum1 += a[i];
				sum2 += b[i];
				//sum3 += c[i];
			}
			ans += max(sum2,sum1);
			if(sum2 > sum1)
				ans += a[1];
			else if(sum2 == sum1)
				ans += max(b[1],a[1]);
			else
				ans += b[1];
			cout << ans << endl;
			continue;
		}
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
