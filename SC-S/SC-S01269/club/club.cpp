#include <bits/stdc++.h>
using namespace std;
struct stu
{
	int x,id;
};
stu a[100005][5],b[100005],c[100005];
int cnt[100005];
bool cmp(stu A,stu B)
{
	if(A.x == B.x)
	{
		return A.id < B.id;
	}
	return A.x < B.x;
}
bool cmp2(stu A,stu B)
{
	if(A.x == B.x)
	{
		return A.id < B.id;
	}
	return A.x < B.x;
}
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
		for(int i = 1; i <= n; i++)
		{
			cnt[i] = 0;
		}
		bool flag1 = 1;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i][1].x >> a[i][2].x >> a[i][3].x;
			if(a[i][3].x != 0 || a[i][2].x != 0)
			{
				flag1 = 0;
			}
			a[i][1].id = 1;
			a[i][2].id = 2;
			a[i][3].id = 3;
			sort(a[i] + 1,a[i] + 3 + 1,cmp);
			b[i].x = a[i][1].x;
			b[i].id = i;
		}
		sort(b + 1,b + n + 1,cmp2);
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(cnt[a[b[i].id][1].id] >= n / 2)
			{
				ans += a[b[i].id][2].x;
			}
			else
			{
				ans += a[b[i].id][1].x;
				cnt[a[b[i].id][1].id]++;
			}	
		}
		if(flag1 == 1)
		{
			int k = 0;
			for(int i = 1; i <= n; i++)
			{
				c[i] = a[i][1];
			}
			sort(c + 1,c + n + 1);
			for(int i = n / 2 + 1; i <= n; i++)
			{
				k += c[i];
			}
			cout << k << endl;
		}
		cout << ans << endl;
	}
    return 0;
}