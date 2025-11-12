#include<bits/stdc++.h>
#define endl '\n'
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define freio(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
using namespace std;
int n;
long long a[500005];
bool f[500005];
long long k;
struct node
{
	long long l;
	long long r;
}b[500005],c[500005],d[500005];
long long cnt;
long long cnt2;
long long cnt3;
long long maxs=LLONG_MIN;

void dfs(int x,long long s,long long l)
{
	maxs=max(maxs,s);
	for(int i=x+1;i<=cnt2;i++)
	{
		if(c[i].l>=l)
		{
			f[i]=true;
			dfs(i,s+1,c[i].r+1);
		}
	}
	return ;
}

bool cmp(node a,node b)
{
	if(a.r==b.r)
	{
		if(a.l>b.l)
		{
			return true;
		}
	}
	if(a.r<b.r)
	{
		return true;
	}
	return false;
}
//RP++
//10:30 10 dfs
//10:50 25
int main()
{
//	fastio
	freio("xor")
	cin>>n>>k;
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1)
		{
			flag=false;
		}
	}
	for(int i=1;i<=n;i++)
	{
		long long ans=a[i];
		if(ans==k)
		{
			cnt++;
			b[cnt].l=i;
			b[cnt].r=i;
			continue;
		}
		for(int j=i+1;j<=n;j++)
		{
			ans^=a[j];
			if(ans==k)
			{
				cnt++;
				b[cnt].l=i;
				b[cnt].r=j;
				break;
			}
		}
	}
//	cout<<cnt<<endl;
	c[1].l=b[1].l;
	c[1].r=b[1].r;
	cnt2=1;
	for(int i=2;i<=cnt;i++)
	{
		if(b[i].r==b[i-1].r&&b[i].l>b[i-1].l)
		{
			c[cnt].l=b[i].l;
			continue;
		}
		cnt2++;
		c[cnt2].l=b[i].l;
		c[cnt2].r=b[i].r;
	}
	sort(c+1,c+cnt2+1,cmp);
//	cout<<cnt2<<endl;
//	for(int i=1;i<=cnt2;i++)
//	{
//		cout<<c[i].l<<" "<<c[i].r<<endl;
//	}
//	cout<<cnt2<<endl;
//	d[1].l=c[1].l;
//	d[1].r=c[1].r;
//	cnt3=1;
//	for(int i=2;i<=cnt2;i++)
//	{
//		if(c[i].r==c[i-1].r&&c[i].l>c[i-1].l)
//		{
//			d[cnt3].l=c[i].l;
//			continue;
//		}
//		cnt3++;
//		d[cnt3].l=c[i].l;
//		d[cnt3].r=c[i].r;
//	}
//	for(int i=1;i<=cnt3;i++)
//	{
//		cout<<d[i].l<<" "<<d[i].r<<endl;
//	}
//	cout<<cnt3;
	if(flag==true)
	{
		cout<<cnt2;
	}
	else
	{
		for(int i=1;i<=c[cnt2].r;i++)
		{
			if(f[i]==true)
			{
				continue;
			}
			f[i]=true;
			dfs(i,1,c[i].r+1);
		}
		cout<<maxs;
	}
	return 0;
}
