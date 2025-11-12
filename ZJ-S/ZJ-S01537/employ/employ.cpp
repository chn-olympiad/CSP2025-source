#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int nm[10000010];
int tong[10000010];
int t[1000010];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n;
	cin >> m >> n;
	string s;
	cin >> s;
	for(int i = 1;i <= m;i++)
	{
		cin >> nm[i];
		tong[nm[i]]++;
	}
	sort(nm+1,nm+n+1);
	int cmp = 0;
	t[0] = 0;t[1] = tong[1];
	for(int i = 1;i <= 1000000;i++)
	{
		t[i] = tong[i] + tong[i-1] - 1;
	}
	for(int i = 1;i <= 1000000;i++)
	{
		if(t[i] != 0)
		{
			cmp != t[i];
			if(cmp > 998244353)
			cmp = cmp % 998244353;
		}
	}
	cout << cmp % 998244353;

	return 0;
}
//#include <bits/stdc++.h>
//using namespace std;
//
//struct stu
//{
//	int a1,a2,a3,id;
//	
//};
//stu bg[1000010];
//int f1[100010];
//int f2[100010];
//int f3[100010];
//
//bool cmp1(int x,int y)
//{
//	return x.a1 > y.a1;
//}
//bool cmp2(stu x,stu y)
//{
//	return  x.a2 > y.a2;
//}
//bool cmp3(stu x,stu y)
//{
//	return  x.a3 > y.a3;
//}
//int sea(int x)
//{
//	
//}
//int main()
//{
//	//freopen("club1.in","r",stdin);
//	//freopen("club.out","w",stdout);
//	int t;
//	cin >> t;
//	for(int l = 1;l <= t;l++)
//	{
//		int n;cin >> n;
//		for(int i = 1;i <= n;i++)
//		{
//			cin >> bg[i].a1 << bg[i].a2 << bg[i].a3;
//			bg[i].id = i;
//		}
//		
//	} 
//	return 0;
//}
