#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct stu
{
	ll a,b,c;
} num[100005];
ll ax,bx,cx;
ll ans;
bool cmp1(stu x,stu y)
{
	return x.a < y.a;
}
bool cmp2(stu x,stu y)
{
	return x.b < y.b;
}
bool cmp3(stu x,stu y)
{
	return x.c < y.c;
}
int main()
{
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while (T--)
	{
		ll n;
		cin >> n;
		ll upp = n / 2;
		for (int i = 1;i <= n;i++)
		{
			cin >> num[i].a >> num[i].b >> num[i].c;
			ll maxx = max(num[i].a,max(num[i].b,num[i].c));
			if (maxx == num[i].a)
			{
				ans += maxx;
				ax++;
			}
			else if (maxx == num[i].b)
			{
				ans += maxx;
				bx++;
			}
			else
			{
				ans += maxx;
				cx++;
			}
		}
		if (ax > upp)
		{
			sort(num + 1,num + n + 1,cmp1);
			for (int i = 1;i <= n;i++)
			{
				if (ax <= upp)
					break;
				int maxx = max(num[i].b,num[i].c);
				if (maxx == num[i].b && bx <= upp)
				{
					ans -= num[i].a;
					ans += num[i].b;
					ax--;
					bx++;
				}
				else 
				{
					ans -= num[i].a;
					ans += num[i].b;
					ax--;
					bx++;
				}
			}
		}
		else if (bx > upp)
		{
			sort(num + 1,num + n + 1,cmp2);
			for (int i = 1;i <= n;i++)
			{
				if (bx <= upp)
					break;
				int maxx = max(num[i].a,num[i].c);
				if (maxx == num[i].a && ax <= upp)
				{
					ans -= num[i].b;
					ans += num[i].a;
					bx--;
					ax++;
				}
				else 
				{
					ans -= num[i].b;
					ans += num[i].c;
					bx--;
					cx++;
				}
			}
		}
		else if (cx > upp)
		{
			sort(num + 1,num + n + 1,cmp3);
			for (int i = 1;i <= n;i++)
			{
				if (cx <= upp)
					break;
				int maxx = max(num[i].a,num[i].b);
				if (maxx == num[i].a && ax <= upp)
				{
					ans -= num[i].c;
					ans += num[i].a;
					cx--;
					ax++;
				}
				else 
				{
					ans -= num[i].c;
					ans += num[i].b;
					cx--;
					bx++;
				}
			}
		}
		cout << ans << endl;
		ans = 0;
		ax = 0;
		bx = 0;
		cx = 0;
	}
	return 0;
}
