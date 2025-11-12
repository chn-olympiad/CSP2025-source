#include<iostream>
#include<algorithm>
using namespace std;
struct stu
{
	long long x[5],mx1,mx2,mx3;
}a[100005];
int c[5];
struct sstu
{
	long long x,id;
}b[100005];
bool cmp(sstu u,sstu v)
{
	return u.x < v.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while(T--)
	{
		long long n,ans = 0;
		cin >> n;
		c[1] = 0,c[2] = 0,c[3] = 0;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i].x[1] >> a[i].x[2] >> a[i].x[3];
			long long maxn = max(a[i].x[1],max(a[i].x[2],a[i].x[3]));
			if(a[i].x[1] == maxn)
			{
				a[i].mx1 = 1;
				long long maxn2 = max(a[i].x[2],a[i].x[3]);
				if(a[i].x[2] == maxn2) a[i].mx2 = 2,a[i].mx3 = 3;
				else a[i].mx2 = 3,a[i].mx3 = 2;
				c[1]++,ans += a[i].x[1];
			}
			else if(a[i].x[2] == maxn)
			{
				a[i].mx1 = 2;
				long long maxn2 = max(a[i].x[1],a[i].x[3]);
				if(a[i].x[1] == maxn2) a[i].mx2 = 1,a[i].mx3 = 3;
				else a[i].mx2 = 3,a[i].mx3 = 1;
				c[2]++,ans += a[i].x[2];
			}
			else if(a[i].x[3] == maxn)
			{
				a[i].mx1 = 3;
				long long maxn2 = max(a[i].x[1],a[i].x[2]);
				if(a[i].x[1] == maxn2) a[i].mx2 = 1,a[i].mx3 = 2;
				else a[i].mx2 = 2,a[i].mx3 = 1;
				c[3]++,ans += a[i].x[3];
			}
		}
		for(int w = 1;w <= 3;w++)
		{
			if(c[w] > n / 2)
			{
				int m = 0;
				for(int i = 1;i <= n;i++)
				{
					if(a[i].mx1 == w) b[++m] = {a[i].x[a[i].mx1] - a[i].x[a[i].mx2],i};
				}
				sort(b + 1,b + m + 1,cmp);
				for(int i = 1;i <= c[w] - n / 2;i++)
				{
					ans -= b[i].x,c[a[b[i].id].mx2]++;
					a[b[i].id].mx1 = a[b[i].id].mx2,a[b[i].id].mx2 = a[b[i].id].mx3;
				}
				c[w] = n / 2;
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
