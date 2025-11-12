#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct st{
	ll x,y,z;
} a[100010];
bool cmp(st a,st b)
{
	return a.x+a.y+a.z>b.x+b.y+b.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t,n;
	cin>>t;
	while(t--)
	{
		ll s=0;
		ll x=0,y=0,z=0;
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].z;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			ll v=max(max(a[i].x,a[i].y),a[i].z);
			if(v==a[i].x)
			{
				if(x<n/2)
				{
					s+=a[i].x;
					x++;
				}
				else
				{
					if(a[i].y>a[i].z)
					{
						if(y<n/2)
						{
							s+=a[i].y;
							y++;
						}
						else
						{
							if(z<n/2)
							{
								s+=a[i].z;
								z++;
							}
						}
					}
					else
					{
						if(z<n/2)
						{
							s+=a[i].z;
							z++;
						}
						else
						{
							if(y<n/2)
							{
								s+=a[i].y;
								y++;
							}
						}
					}
				}
			}
			else if(v==a[i].y)
			{
				if(y<n/2)
				{
					s+=a[i].y;
					y++;
				}
				else
				{
					if(a[i].x>a[i].z)
					{
						if(x<n/2)
						{
							s+=a[i].x;
							x++;
						}
						else
						{
							if(z<n/2)
							{
								s+=a[i].z;
								z++;
							}
						}
					}
					else
					{
						if(z<n/2)
						{
							s+=a[i].z;
							z++;
						}
						else
						{
							if(x<n/2)
							{
								s+=a[i].x;
								x++;
							}
						}
					}
				}
			}
			else if(v==a[i].z)
			{
				if(z<n/2)
				{
					s+=a[i].z;
					z++;
				}
				else
				{
					if(a[i].x>a[i].y)
					{
						if(x<n/2)
						{
							s+=a[i].x;
							x++;
						}
						else
						{
							if(y<n/2)
							{
								s+=a[i].y;
								y++;
							}
						}
					}
					else
					{
						if(y<n/2)
						{
							s+=a[i].y;
							y++;
						}
						else
						{
							if(x<n/2)
							{
								s+=a[i].x;
								x++;
							}
						}
					}
				}
			}
		}
		cout<<s<<"\n";
	}
	return 0;
}
