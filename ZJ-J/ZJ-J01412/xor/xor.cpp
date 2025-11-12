#include<bits/stdc++.h>
using namespace std;
int n,k,a[500100],cnt,sum;
struct node
{
	int l,r;
}ans[500100];
bool cmp(node x,node y)
{
	if(x.r==y.r) return x.l<y.l;
	return x.r<y.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int sum=a[i];
		if(sum==k) 
		{
			ans[++cnt].l=i;
			ans[cnt].r=i;
			continue;
		}
		for(int j=i+1;j<=n;j++)
		{
			sum^=a[j];
			if(sum==k) 
			{
				ans[++cnt].l=i;
				ans[cnt].r=j;
				break;
			}
		}
	}
	sort(ans+1,ans+cnt+1,cmp);
	int mx=0;
	for(int i=1;i<=cnt;i++)
	{
		if(ans[i].l>mx)
		{
			sum++;
			mx=ans[i].r;
		}
	}
	cout<<sum;
	return 0;
}