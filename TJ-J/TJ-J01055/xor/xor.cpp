#include<bits/stdc++.h>
using namespace std;
struct qj
{
	int l,r;
}q[1000009];
int a[500009];
int b[10009][10009];
int qzh[500009];
bool cmp(qj c,qj d)
{
	if(c.r!=d.r)
		return c.r<d.r;
	return c.l>d.l;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	//if(n<=10000)
	//{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			b[i][i]=a[i];
			if(b[i][i]==k)
				q[++cnt].l=i,q[cnt].r=i;
			for(int j=i+1;j<=n;j++)
			{
				b[i][j]=(b[i][j-1]^a[j]);
				if(b[i][j]==k)
					q[++cnt].l=i,q[cnt].r=j;
			}
		}
		int ans=0;
		sort(q+1,q+cnt+1,cmp);
		int R=0;
		for(int i=1;i<=cnt;i++)
		{
			if(q[i].l>R)
			{
				ans++;
				R=q[i].r;
			}	
		}
		cout<<ans;
		return 0;
	//}
	return 0;
}
