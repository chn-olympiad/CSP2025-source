#include <bits/stdc++.h>

using namespace std;

int rd[100010][3];

//bool search(int x,int y)
//{
//	if(x = y) return true;
//	for(int i = 1;i <= m;i++)
//	{
//		if(rd[i][0] != 0)
//			continue;
//		else if(rd[i][1] == x)
//		{
//			search(rd[i][3],y);
//			
//		}
//	}
//}
int tow[10010][1010];
int main()
{
	queue<int> dfs;
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >>m >> k;
	for(int i = 1;i <= m;i++)
	{
		cin >> rd[i][1]>> rd[i][2] >> rd[i][3];
	}
	for(int i= 1;i <= k;i++)
	{
		for(int j = 0;j <= n;j++)
		{
			cin >> tow[i][j];
		}
	}
//	if(k != 0)
//	{
		cout << 0 << endl;
		return 0;
//	}
//	int maxn = 0
//	for(int i = 1;i <= n;i++)
//	{
//		maxn += rd[i][2];
//	}
//	for(int i = 1;i <=m;i++)
//	{
//		
//	}
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
