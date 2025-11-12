#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5+5;
int n,k;
int ans = 0;

int a[N];
struct node{
	int l,r,lon;
}sh[N];

bool cmp(node aa,node bb)
{
	if(aa.l == bb.l) return aa.r < bb.r;
	return aa.l < bb.l;
}
bool vis[N];

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
		
	if(n > 5000)
	{
		int flagb = 0;
		for(int i = 1;i <= n;i++)
			if(a[i] != 1 && a[i] != 0) flagb = 1;
		if(flagb == 0)
		{
			if(k != 0 && k != 1) cout<<0<<"\n";
			else
			{
				if(k == 0)
				{
					for(int i = 1;i <= n;i++)
					{
						if(a[i] == 0) ans++;
						else
						{
							if(a[i-1] == 1) 
							{
								ans++;
								a[i] = 0;
							}
						}
					}
					cout<<ans<<"\n";
				}
				else
				{
					for(int i = 1;i <= n;i++)
						if(a[i] == 1) ans++;
					cout<<ans<<"\n";
				}
			}
			return 0;
		}
			
	}
	
	
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		int t = a[i];
		if(t == k)
		{
			cnt++;
			sh[cnt].l = sh[cnt].r = i;
			sh[cnt].lon = 1;
			continue;
		}
		for(int j = i+1;j <= n;j++)
		{
			
			t = (t xor a[j]);
			
			if(t == k)
			{
				sh[++cnt].l = i;
				sh[cnt].r = j;
				sh[cnt].lon = j - i + 1;
				break;
			}
		}
	}
	
	
	sort(sh + 1, sh + cnt + 1, cmp);
	
	ans = cnt;
	
	int lastr = sh[1].r;
	for(int i = 2;i <= cnt;i++)
	{
		if(sh[i].l > lastr) 
		{
			lastr = sh[i].r;
			continue;
		}
		if(sh[i].r <= lastr)
		{
			ans--;
			lastr = sh[i].r;
			continue;
		}
		else ans--;
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
