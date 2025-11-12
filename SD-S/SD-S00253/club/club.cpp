#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, tot;
struct st
{
	pair<int,int> v[4];
}a[N], b[N];
int read()
{
	int n=0, f=1; char c=getchar();
	while(c<'0'||c>'9') f-=2*(c=='-'), c=getchar();
	while(c>='0'&&c<='9') n=n*10+c-'0', c=getchar();
	return n*f;
}
void wrt(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) wrt(x/10);
	putchar('0'+x%10);
}
bool cmp(st a, st b)
{
	int a1 = a.v[1].first-a.v[2].first;
	int a2 = a.v[2].first-a.v[3].first;
	int b1 = b.v[1].first-b.v[2].first;
	int b2 = b.v[2].first-b.v[3].first;
	if(a1!=b1) return a1>b1;
	return a2>b2;
}
void p(int u)
{
	tot++;
	b[tot] = a[u];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		tot = 0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++) a[i].v[j].first=read(), a[i].v[j].second=j;
			sort(a[i].v+1,a[i].v+4);
			reverse(a[i].v+1,a[i].v+4);
		}
		sort(a+1,a+n+1,cmp);
		int c[4]={0,0,0,0};
		int ans = 0;
		for(int i=1;i<=n;i++)
		{
			if(c[a[i].v[1].second]==n/2) p(i);
			else ans += a[i].v[1].first, c[a[i].v[1].second]++;
		}
		sort(b+1,b+1+tot,cmp);
		for(int i=1;i<=tot;i++)
		{
			if(c[b[i].v[2].second]==n/2) c[b[i].v[3].second]++,ans+=b[i].v[3].first;
			else ans += b[i].v[2].first, c[b[i].v[2].second]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
