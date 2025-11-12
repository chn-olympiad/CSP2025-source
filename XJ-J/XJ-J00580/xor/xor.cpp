#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005];
long long x[500005];
struct node
{
	int l,r;
}
l[500005];
bool cmp(node a,node b)
{
	return a.r<b.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		x[i]=x[i-1]^a[i];
	if(n>2000&&k<=1)
	{
		long long cnt=0,ans=0;
		for(int i=1;i<=n;i++)
			if(a[i]==k)
			{
				cnt++;
			}
		cout<<cnt;
	}
	else
	{
		long long t=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
				if((x[j]^x[i-1])==k)
					t++,l[t].l=i,l[t].r=j;
		}
		sort(l+1,l+t+1,cmp);
		long long lst=0,cnt=0;
		for(int i=1;i<=t;i++)
			if(l[i].l>l[lst].r)
			{
				cnt++,lst=i;
			}
		cout<<cnt;
	}
	return 0;
}
