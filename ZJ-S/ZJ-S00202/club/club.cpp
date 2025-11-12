#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,z;
};
struct node2
{
	int maxn,maxi,midn,midi;
};
node a[100005];
int cmp(node2 c,node2 d)
{
	if(c.maxn==d.maxn)
		return c.midn<d.midn;
	return c.maxn+d.midn>d.maxn+c.midn;
}
int t,n;
void solve()
{
	scanf("%d",&n);
	node2 k[100005];
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		k[i].maxn=max(a[i].x,max(a[i].y,a[i].z));
		if(a[i].x==k[i].maxn)
			k[i].maxi=1;
		else if(a[i].y==k[i].maxn)
				k[i].maxi=2;
		else k[i].maxi=3;
		k[i].midn=a[i].x+a[i].y+a[i].z-max(a[i].x,max(a[i].y,a[i].z))-min(a[i].x,min(a[i].y,a[i].z));
		if(a[i].x==k[i].midn)
			k[i].midi=1;
		else if(a[i].x==k[i].midn)
				k[i].midi=2;
		else k[i].midi=3;
	}
	sort(k+1,k+n+1,cmp); 
	int s[5]={},ans=0;
	for(int i=1;i<=n;i++)
		if(s[k[i].maxi]+1<=n/2)
		{
			s[k[i].maxi]++;
			ans+=k[i].maxn;
		}
		else
		{
			s[k[i].midi]++;
			ans+=k[i].midn;
		}
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
		solve();
	return 0;
}
