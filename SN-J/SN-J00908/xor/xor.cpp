#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+1;
long long n,k,a[MAXN],f[1001][1001],ans=1;
struct node
{
	int l,r;
}bj[MAXN];
bool cmp(node x,node y)
{
	if(x.l==y.l)
	{
		return x.r<y.r;
	}
	return x.l<y.l;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(f,-1,sizeof(f));
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int num;
			for(int k=i;k<=j;k++)
			{
				if(k==i)
				{
					num=a[i];
				}
				if(i==j)
				{
					break;
				}
				num=num^a[i];
			}
			f[i][j]=num;
		}
	}
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(f[i][j]==k)
			{
				bj[cnt].l=i;
				bj[cnt].r=j;
				cnt++;
			}
		}
	}
	sort(bj+1,bj+cnt+1,cmp);
	int end=bj[1].r;
	for(int i=2;i<=cnt;i++)
	{
		if(bj[i].l>end)
		{
			ans++;
			end=bj[i].r;
		}
	}
	cout<<ans;
	return 0;
}
