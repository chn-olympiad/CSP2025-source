#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct stt
{
	int a,b,c;
}s[N];
int T,n,ans,cnta,cntb,cntc;
bool cmp1(stt xx,stt yy)
{
	return max(xx.b,xx.c) - xx.a > max(yy.b,yy.c) - yy.a;
}
bool cmp2(stt xx,stt yy)
{
	return max(xx.a,xx.c) - xx.b > max(yy.a,yy.c) - yy.b;
}
bool cmp3(stt xx,stt yy)
{
	return max(xx.b,xx.a) - xx.c > max(yy.b,yy.a) - yy.c;
}
void solve()
{
	scanf("%d",&n);
	ans = 0,cnta = cntb = cntc = 0;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d %d %d",&s[i].a,&s[i].b,&s[i].c);
	}
	for(int i = 1;i <= n;i++)
	{
		int mx = max(max(s[i].a,s[i].b),s[i].c);
		ans += mx;
		if(mx == s[i].a)
		{
			cnta++;
		}
		else if(mx == s[i].b)
		{
			cntb++;
		}
		else
		{
			cntc++;
		}
	}
	if(cnta > n / 2)
	{
		sort(s + 1,s + 1 + n,cmp1);
		for(int i = 1;i <= n;i++)
		{
			int mx = max(max(s[i].a,s[i].b),s[i].c);
			if(mx == s[i].a)
			{
				ans -= s[i].a;
				ans += max(s[i].b,s[i].c),cnta--;
			}
			if(cnta <= n / 2)
			{
				break;
			}
		}
	}
	else if(cntb > n / 2)
	{
		sort(s + 1,s + 1 + n,cmp2);
		for(int i = 1;i <= n;i++)
		{
			int mx = max(max(s[i].a,s[i].b),s[i].c);
			if(mx == s[i].b)
			{
				ans -= s[i].b,ans += max(s[i].a,s[i].c),cntb--;
			}
			if(cntb <= n / 2)
			{
				break;
			}
		}
	}
	else if(cntc > n / 2)
	{
		sort(s + 1,s + 1 + n,cmp3);
		for(int i = 1;i <= n;i++)
		{
			int mx = max(max(s[i].a,s[i].b),s[i].c);
			if(mx == s[i].c)
			{
				ans -= s[i].c,ans += max(s[i].b,s[i].a),cntc--;
			}
			if(cntc <= n / 2)
			{
				break;
			}
		}
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
