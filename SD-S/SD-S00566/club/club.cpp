#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 1e5 + 10;
int n,cnt[5];
struct node
{
	int mx,mxx,id,idd,cha;
}a[MX];
bool cmp(node x,node y)
{
	return x.cha > y.cha;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int T;
	cin >> T;
	while(T--)
	{
		memset(cnt,0,sizeof(cnt));
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			a[i].mx = 0,a[i].mxx = 0,a[i].id = 0,a[i].idd = 0,a[i].cha = 0;
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= 3;j++)
			{
				int x;
				cin >> x;
				if(x > a[i].mx)
				{
					a[i].mxx = a[i].mx;
					a[i].idd = a[i].id;
					a[i].mx = x;
					a[i].id = j;
				}
				else if(x > a[i].mxx)
				{
					a[i].mxx = x;
					a[i].idd = j;
				}
			}
			a[i].cha = a[i].mx - a[i].mxx;
		}
		sort(a + 1,a + n + 1,cmp);
		ll ans = 0;
		for(int i = 1;i <= n;i++)
		{
			if(cnt[a[i].id] < n / 2)
			{
				ans += a[i].mx;
				cnt[a[i].id]++;
			}
			else
			{
				ans += a[i].mxx;
				cnt[a[i].idd]++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
