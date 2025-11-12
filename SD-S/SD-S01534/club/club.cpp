#include<bits/stdc++.h>
#define int long long
#define I using
#define AK namespace
#define CSPS2025 std
I AK CSPS2025;
const int maxn=1e6+10,maxm=1e3+10,mod=998244353,inf=1e18;
int t,n,m,u,v,w,a,b,x,y,z,cnt,ans,c[10];
struct node
{
	int x,y,z,id;
}arr[maxn],res[maxn];
int cmp(node x,node y)
{
	if(x.x-x.y==y.x-y.y)
	{
		return x.x>y.x;
	}
	return (x.x-x.y)>(y.x-y.y);
}
int A(node x,node y)
{
	return x.x>y.x;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		u=0,v=0,w=0,a=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i].x>>arr[i].y>>arr[i].z;
			if(arr[i].y or arr[i].z)
			{
				a=1;
			}
			if(arr[i].z)
			{
				b=1;
			}
			arr[i].id=i;
			res[i].x=max(arr[i].x,arr[i].z);
			res[i].y=arr[i].y;
//			tag[i].x=arr[i].x,tag[i].y=arr[i].y,tag[i].z=arr[i].z;
		}
		if(!a)
		{
			sort(arr+1,arr+n+1,A);
			for(int i=1;i<=(n>>1);i++)
			{
				u+=arr[i].x;
			}
			cout<<u;
			continue;
		}
		if(!b)
		{
			sort(arr+1,arr+n+1,cmp);
			for(int i=1;i<=(n>>1);i++)
			{
				u+=arr[i].x;
			}
			for(int i=(n>>1)+1;i<=n;i++)
			{
				u+=arr[i].y;
			}
			cout<<u;
			continue;
		}
		sort(res+1,res+n+1,cmp);
		for(int i=1;i<=(n>>1);i++)
		{
			u+=res[i].x;
		}
		for(int i=(n>>1)+1;i<=n;i++)
		{
			u+=res[i].y;
		}
		for(int i=1;i<=n;i++)
		{
			res[i].x=max(arr[i].x,arr[i].y);
			res[i].y=arr[i].z;
		} 
		sort(res+1,res+n+1,cmp);
		for(int i=1;i<=(n>>1);i++)
		{
			v+=res[i].x;
		}
		for(int i=(n>>1)+1;i<=n;i++)
		{
			v+=res[i].y;
		}
		for(int i=1;i<=n;i++)
		{
			res[i].x=max(arr[i].y,arr[i].z);
			res[i].y=arr[i].x;
		} 
		sort(res+1,res+n+1,cmp);
		for(int i=1;i<=(n>>1);i++)
		{
			w+=res[i].x;
		}
		for(int i=(n>>1)+1;i<=n;i++)
		{
			w+=res[i].y;
		}
		cout<<max({u,v,w})<<"\n";
	}
	return 0;
}
//Goodbye everyone
