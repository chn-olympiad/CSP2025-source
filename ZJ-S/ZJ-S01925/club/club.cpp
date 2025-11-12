#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int MAXN = 1e5+10;


struct Node
{
	int a,b,c,mx,md,mi,idx;
} a[MAXN],mxa[MAXN];
ll n,sm[5],lin,ans = 0,t;

bool cmpmx(Node a,Node b)
{
	return a.mx > b.mx;
}


int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--)
	{
		ans = 0;
		cin >> n;
		if(n % 2 == 0) lin = n / 2;
		else lin = n / 2 + 1;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i].a >> a[i].b >> a[i].c;
			a[i].mx = max(a[i].a,max(a[i].b,a[i].c));
			mxa[i].mx = max(a[i].a,max(a[i].b,a[i].c));
			if(a[i].mx == a[i].a)
			{
				a[i].md = max(a[i].b,a[i].c);
				mxa[i].md = max(a[i].b,a[i].c);
			}
			else if(a[i].mx == a[i].b)
			{
				a[i].md = max(a[i].a,a[i].c);
				mxa[i].md = max(a[i].a,a[i].c);
			}
			else if(a[i].mx == a[i].c)
			{
				a[i].md = max(a[i].a,a[i].b);
				mxa[i].md = max(a[i].a,a[i].b);
			}
			a[i].mi = min(a[i].a,min(a[i].b,a[i].c));
			mxa[i].mi = min(a[i].a,min(a[i].b,a[i].c));
			a[i].idx = i;
			mxa[i].idx = i;
		}
		if(n == 2)
		{
			cout << max((a[1].mx + a[2].md) , (a[2].mx + a[1].md));
			memset(sm,0,sizeof(sm));
			continue;
		}
		sort(mxa+1,mxa+1+n,cmpmx);
		for(int i=1;i<=n;i++)
		{
			ll tidx = mxa[i].idx,tt;
			if(a[tidx].mx == a[tidx].a) tt = 1;
			else if(a[tidx].mx == a[tidx].b) tt = 2;
			else if(a[tidx].mx == a[tidx].c) tt = 3;
			if(sm[tt] < lin)
			{
				sm[tt]++;
				ans += a[tidx].mx;
			}
			else
			{
				if(a[tidx].md == a[tidx].a) tt = 1;
				else if(a[tidx].md == a[tidx].b) tt = 2;
				else if(a[tidx].md == a[tidx].c) tt = 3;
				sm[tt]++;
				ans += a[tidx].md;
			}
		}
		cout << ans << '\n';
		memset(sm,0,sizeof(sm));
	}
	return 0;
}
