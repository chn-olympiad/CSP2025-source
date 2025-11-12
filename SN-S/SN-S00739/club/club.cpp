//SN-S00739 陈和骏 西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
multiset<int> st[5];
int rd()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c && c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
	}
	else if(x<10)
	{
		putchar(x+'0');
		return;
	}
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=rd();
	while(t--)
	{
		int n=rd(),ans=0;
		for(int i=1;i<=3;i++) st[i].clear();
		for(int i=1;i<=n;i++)
		{
			int maxx=-1,maxn=-1,idx;
			for(int j=1;j<=3;j++)
			{
				int w=rd();
				if(w>maxx) maxn=maxx,maxx=w,idx=j;
				else if(w>maxn) maxn=w;
			}
			ans+=maxx;
			st[idx].insert(maxx-maxn);
		}
		for(int i=1;i<=3;i++)
		{
			if((int)st[i].size()<=n/2) continue;
			int cnt=0,lim=st[i].size()-n/2;
			for(int j:st[i])
			{
				cnt++;
				ans-=j;
				if(cnt==lim) break;
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
/*
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
