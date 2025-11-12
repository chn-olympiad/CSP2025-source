#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10; 
struct STU{
	int a,b,c;
	int final;
}a[N];
/*
题意： 
n(n % 2 == 0)个人，3个部门
每个人对三个部门的满意度为a[1],a[2],a[3]
同时每个部门人数不超过n / 2 ，求有最大满意度的调度方案

贪心：
设立三个数组，分别为所有人对这三个部门的满意度的集合
把人员加入部门-》找到对满意度贡献最大的人
 	·问题：若有人同时对多个部门贡献最大 
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

bool cmp(STU a,STU b)
{
	return a.a > b.a;
}
bool cmp2(STU a,STU b)
{
	return a.b > b.b;
}
bool cmp3(STU a,STU b)
{
	return a.c > b.c;
}

int main()
{
	ios::sync_with_stdio(),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i].a >> a[i].b >> a[i].c,a[i].final = 0;
		//对每个部门的满意度排序(大到小) 
		int cnt_a = 0,cnt_b = 0,cnt_c = 0;//各个部门的人数
		int ans = 0;	
		//先根据每个人对A部门的满意度选择
		//若这个人对B部门的贡献最大，则先不选
		sort(a + 1,a + n + 1,cmp);
		for(int i = 1;i <= n;i++)
		{
			if(a[i].a > a[i].b && a[i].a > a[i].c && cnt_a <= n / 2)
			{
				ans += a[i].a;
				a[i].final = 1;
				cnt_a++;
			}
		} 
//		cout << ans << endl;
		sort(a + 1,a + n + 1,cmp2); 
		for(int i = 1;i <= n;i++)
		{
			if(a[i].final == 0)
			{
				if(a[i].b > a[i].c && cnt_b <= n / 2)
				{
					ans += a[i].b;
					a[i].final = 1;
					cnt_b++;
				}
			}
		}
//		cout << ans << endl;
		sort(a + 1,a + n + 1,cmp3);  
		for(int i = 1;i <= n;i++)
		{
			if(a[i].final == 0 && cnt_c <= n / 2) 
			{
				a[i].final = 1;
				ans += a[i].c;
				cnt_c++;
			}
		}
//		for(int i = 1;i <= n;i++)
//		{
//			cout << a[i].a << ' ' << a[i].b << ' ' << a[i].c << " final: " << a[i].final << endl; 
//		}
		cout << ans << endl;
//		cout << "cnt:" << cnt_a << ' ' << cnt_b << " " << cnt_c << endl;
 	}
	return 0;
}
