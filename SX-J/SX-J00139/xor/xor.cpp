#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt,a[500005],b[500005];
struct line{
	long long l,r;
}x[500005];
struct tree{
	long long l,r,sum,laz;
}t[4000005];
bool cmp(line a,line b)
{
	if(a.r-a.l+1==b.r-b.l+1)
	{
		return a.l<b.l;
	}
	return (a.r-a.l+1)<(b.r-b.l+1);
}
void pushd(long long ls)
{
	if(t[ls].laz==0)
	{
		return;
	}
	t[ls*2].sum=t[ls*2+1].sum=0;
	t[ls*2].laz=t[ls*2+1].laz=0;
	t[ls].laz=0;
}
void build(long long ls,long long l,long long r)
{
	t[ls].l=l;
	t[ls].r=r;
	t[ls].sum=r-l+1;
	if(l==r)
	{
		return;
	}
	long long mid=(l+r)/2;
	build(ls*2,l,mid);
	build(ls*2+1,mid+1,r);
}
void rem(long long ls,long long l,long long r)
{
	if(t[ls].l>=l&&t[ls].r<=r)
	{
		t[ls].sum=0;
		t[ls].laz=1;
		return;
	}
	if(t[ls].l==t[ls].r)
	{
		return;
	}
	pushd(ls);
	long long mid=(t[ls].l+t[ls].r)/2;
	if(l<=mid)
	{
		rem(ls*2,l,r);
	}
	if(r>mid)
	{
		rem(ls*2+1,l,r);
	}
	t[ls].sum=t[ls*2].sum+t[ls*2+1].sum;
}
long long query(long long ls,long long l,long long r)
{
	if(t[ls].l>=l&&t[ls].r<=r)
	{
		return t[ls].sum;
	}
	if(t[ls].l==t[ls].r)
	{
		return 0;
	}
	pushd(ls);
	long long ans=0;
	long long mid=(t[ls].l+t[ls].r)/2;
	if(l<=mid)
	{
		ans+=query(ls*2,l,r);
	}
	if(r>mid)
	{
		ans+=query(ls*2+1,l,r);
	}
	t[ls].sum=t[ls*2].sum+t[ls*2+1].sum;
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
//		cout<<b[i]<<' ';
	}
//	cout<<endl;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i;j<=n;j++)
		{
			if((b[j]^b[i-1])==k)
			{
//				cout<<b[j]<<' '<<b[i-1]<<' '<<(b[j]^b[i-1])<<endl;
				cnt++;
				x[cnt]={i,j};
				break;
			}
		}
	}
	sort(x+1,x+1+cnt,cmp);
	build(1,1,n);
	long long ans=0;
	for(long long i=1;i<=cnt;i++)
	{
		if(query(1,x[i].l,x[i].r)!=x[i].r-x[i].l+1)
		{
			continue;
		}
//		cout<<query(1,1,n)<<endl;
		ans++;
		rem(1,x[i].l,x[i].r);
//		cout<<x[i].l<<' '<<x[i].r<<endl;
	}
	cout<<ans;
	return 0;
}