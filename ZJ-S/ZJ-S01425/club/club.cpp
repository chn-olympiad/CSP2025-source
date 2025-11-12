#include<bits/stdc++.h>
using namespace std;

int T;

struct node
{
	int club_1,club_2,club_3,id;
}a[100001];

bool cmpclub1(node x,node y)
{
	return x.club_1 > y.club_1;
}
bool cmpclub2(node x,node y)
{
	return x.club_2 > y.club_2;
}
bool cmpclub3(node x,node y)
{
	return x.club_3 > y.club_3;
}
int vis[100001];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	
	while(T --)
	{
		
		memset(a,0,sizeof(a));
		
		int vis_maxclub[100001]; // 对于每个人来说满意值最大的社团 
		int vis_same[100001][4]; // 对于相同满意度
		memset(vis_maxclub,0,sizeof(vis_maxclub));
		memset(vis,1,sizeof(vis));
		for(int i = 0 ;i <= 100000; i ++)
		{
			for(int j = 0; j <= 3; j ++)
			{
				vis_same[i][j] = 0;
			}
		}
		
		int n;
		cin >> n;
		
		for(int i = 1; i <= n; i ++)
		{
			a[i].id = i;
			cin >> a[i].club_1 >> a[i].club_2 >> a[i].club_3;
			
			if((a[i].club_1 == a[i].club_2 && a[i].club_2 == a[i].club_3) || (a[i].club_1 == a[i].club_2 && a[i].club_1 > a[i].club_3) || (a[i].club_1 == a[i].club_3 && a[i].club_1 > a[i].club_2) || (a[i].club_2 == a[i].club_3 && a[i].club_2 > a[i].club_1))
			{
				vis_maxclub[i] = -1;
				if(a[i].club_1 == a[i].club_2 == a[i].club_3)
				{
					vis_same[i][1] = 1;
					vis_same[i][2] = 1;
					vis_same[i][3] = 1;
				}
				
				if(a[i].club_1 == a[i].club_2)
				{
					vis_same[i][1] = 1;
					vis_same[i][2] = 1;
				}
				
				if(a[i].club_1 == a[i].club_3)
				{
					vis_same[i][1] = 1;
					vis_same[i][3] = 1;
				}
				
				if(a[i].club_2 == a[i].club_3)
				{
					vis_same[i][2] = 1;
					vis_same[i][3] = 1;
				}
			}
			else
			{
				if(a[i].club_1 > a[i].club_2 && a[i].club_1 > a[i].club_3)
				{	
					vis_maxclub[i] = 1;
				}
				if(a[i].club_2 > a[i].club_1 && a[i].club_2 > a[i].club_3)
				{
					vis_maxclub[i] = 2;
				}
				if(a[i].club_3 > a[i].club_2 && a[i].club_3 > a[i].club_1)
				{
					vis_maxclub[i] = 3;
				}
				//cout << vis_maxclub[i] << " ";
			}
		}
		
		if(n == 2)
		{
			int luck = 0;
			for(int i = 1; i <= 3;i ++)
			{
				for(int j = 1; j <= 3;j ++)
				{
					if(i != j)
					{
						int x,y;
						if(i == 1)
						{
							x = a[1].club_1;
						}
						if(i == 2)
						{
							x = a[1].club_2;
						}
						if(i == 3)
						{
							x = a[1].club_3;
						}
						if(j == 1)
						{
							y = a[2].club_1;
						}
						if(j == 2)
						{
							y = a[2].club_2;
						}
						if(j == 3)
						{
							y = a[2].club_3;
						}
						luck = max(luck,x + y);
					}
				}
			}
			cout << luck << endl;
			continue;
		}
//		for(int i = 1; i <= n;i ++)
//		{
//			cout << vis_maxclub[i] << " ";
//		}
//		cout << endl;
		
		// 初始化
		
		int ans = 0;
		
		int cnt_club1 = 0,cnt_club2 = 0,cnt_club3 = 0;
		
		int pp = 1;
		//先判断对于一部门来说选取哪几个
		sort(a + 1,a + n + 1,cmpclub1);
		
		//cout << a[a[2].id].club_1 << endl;
		
		
		
		for(int i = 1; i <= n;i ++)
		{
			if(cnt_club1 == n / 2)
			{
				pp = 0;
			}
			if(vis_maxclub[a[i].id] == 1 && vis[a[i].id] && pp)
			{
				vis[a[i].id] = 0;
				cnt_club1 ++;
				ans += a[i].club_1;
				//cout << a[i].id << " " << a[a[i].id].club_1 << " " << 1 << endl;
				//	cout << a[i].club_1 << " ";
				//cout << i << " " << 1 << endl;
			}
		}
		
		sort(a + 1,a + n + 1,cmpclub2);
//		for(int i = 1; i <= n;i ++)
//		{
//			cout << a[i].id << " ";
//		}
//		cout << endl;
		
//		for(int i = 1; i <= n;i ++)
//		{
//			cout << a[a[i].id].club_2 << " ";
//		}
//		cout << endl;
		pp = 1;
		for(int i = 1; i <= n; i ++)
		{
			if(cnt_club2 == n / 2)
			{
				pp = 0;
			}
			if(vis_maxclub[a[i].id] == 2 && vis[a[i].id] && pp)
			{
				vis[a[i].id] = 0;
				cnt_club2 ++;
				ans += a[i].club_2;
				//cout << i << " " << 2 << endl;
			}
		}
		
		//cout << cnt_club2 << endl;
		
		sort(a + 1,a + n + 1,cmpclub3);
		pp = 1;
		for(int i = 1; i <= n;i ++)
		{
			if(cnt_club3 == n / 2)
			{
				pp = 0;
			}
			
			if(vis_maxclub[a[i].id] == 3 & vis[a[i].id] && pp)
			{
				vis[a[i].id] = 0;
				cnt_club3 ++;
				ans += a[i].club_3;
				//cout << i << " " << 3 << endl;
			}
		}
		
		cout << ans << endl;
		
		
	}
	
	return 0;
}
