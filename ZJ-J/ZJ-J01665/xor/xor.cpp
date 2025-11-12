#include<iostream>
#include<algorithm>
using namespace std;
int n,k,a[500001],d[500001],p=1,pos,ans;
struct qj
{
	int l,r;
}q[500001];
bool cmp(qj x,qj y)
{
	if(x.r!=y.r)return x.r<y.r;
	return x.l>y.l;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		d[i]=d[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(int(d[i-1]^d[j])==k)
			{
				q[p].l=i;
				q[p].r=j;
				p++;
				break;
			}
		}
	}
	sort(q+1,q+p,cmp);
	for(int i=1;i<p;i++)
	{
		if(q[i].l>pos)
		{
			ans++;
			pos=q[i].r;
		}
	}
	cout<<ans;
	return 0;
}
