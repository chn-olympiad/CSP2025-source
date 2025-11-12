#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+5;
struct node{
	int x,id;
}b[N];
struct node1{
	int l,r;
}d[N];
int s[N],mi[N];
int n,k,a[N],x[N],id[N];
int m,z,ans;
bool cmp(node x,node y)
{
	if(x.x==y.x)
		return x.id<y.id;
	return x.x<y.x;
}
bool cmp2(node1 x,node1 y)
{
	return x.l>y.l;
}
signed main()
{
	freopen("xor.in","r",stdin);
 	freopen("xor.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		b[i].x=s[i];
		b[i].id=i;
	}
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		x[i]=b[i].x;
		id[i]=b[i].id;
	}
	for(int i=1;i<=n;i++)
	{
		int key=k^s[i];
		int t=lower_bound(x,x+1+n,key)-x;
		int t1=upper_bound(x,x+1+n,key)-x-1;
		if(id[t]>=i)
			continue;
		int t2=lower_bound(id+1+t,id+1+t1,i)-id-1;
		d[++m].l=id[t2]+1;
		d[m].r=i;
	}
	sort(d+1,d+1+m,cmp2);
	k=1;
	memset(mi,63,sizeof(mi));
	for(int i=n;i>=1;i--)
	{
		mi[i]=mi[i+1];
		while(k<=m&&i==d[k].l)
		{
			mi[i]=min(mi[i],d[k].r);
			k++;
		}
	}
	z=1;
	ans=0;
	while(mi[z]!=mi[n+1])
	{
		z=mi[z]+1;
		ans++;
	}
	cout<<ans;
 	return 0;
}
