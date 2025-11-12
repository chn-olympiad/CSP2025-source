#include<bits/stdc++.h>
using namespace std;
int t,n,t1[5],f,tot;
long long ans;
struct node
{
	int f1,f2,f3,mx,mid,mn,nid;
} a[100005];
struct fo
{
	int s,lk;
} v[100005];
bool cmp(fo x,fo y)
{
	if((x.s-x.lk)!=(y.s-y.lk)) return (x.s-x.lk)>(y.s-y.lk);
	return x.s>y.s;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		memset(t1,0,sizeof(t1));
		f=0;
		tot=0;
		for(int i=1; i<=n; i++) cin>>a[i].f1>>a[i].f2>>a[i].f3;
		for(int i=1; i<=n; i++)
		{
			if(a[i].f1>=a[i].f2&&a[i].f1>=a[i].f3)
			{
				a[i].mx=1;
				a[i].mid=a[i].f1;
				if(a[i].f2>=a[i].f3)
				{
					a[i].mn=2;
					a[i].nid=a[i].f2;
				}
				else
				{
					a[i].mn=3;
					a[i].nid=a[i].f3;
				}
			}
			else if(a[i].f2>=a[i].f1&&a[i].f2>=a[i].f3)
			{
				a[i].mx=2;
				a[i].mid=a[i].f2;
				if(a[i].f1>=a[i].f3)
				{
					a[i].mn=1;
					a[i].nid=a[i].f1;
				}
				else
				{
					a[i].mn=3;
					a[i].nid=a[i].f3;
				}
			}
			else if(a[i].f3>=a[i].f1&&a[i].f3>=a[i].f1)
			{
				a[i].mx=3;
				a[i].mid=a[i].f3;
				if(a[i].f1>=a[i].f2)
				{
					a[i].mn=1;
					a[i].nid=a[i].f1;
				}
				else
				{
					a[i].mn=2;
					a[i].nid=a[i].f2;
				}
			}
		}
		for(int i=1; i<=n; i++) t1[a[i].mx]++;
		for(int i=1; i<=3; i++)
		{
			if(t1[i]>n/2)
			{
				f=i;
				continue;
			}
		}
		for(int i=1; i<=n; i++)
		{
			if(a[i].mx==f)
			{
				v[++tot].s=a[i].mid;
				v[tot].lk=a[i].nid;
			}
		}
		sort(v+1,v+tot+1,cmp);
		for(int i=1; i<=n; i++) ans+=a[i].mid;
		for(int i=n/2+1; i<=tot; i++)
		{
			ans-=v[i].s;
			ans+=v[i].lk;
		}
		cout<<ans<<endl;
	}
	return 0;
}
