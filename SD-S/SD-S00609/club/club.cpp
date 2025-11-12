#include<bits/stdc++.h> 

#define ll long long

using namespace std;

const ll N=1e5+10;

inline void read(ll &a)
{
	ll s=1,w=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			s=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		w=w*10+ch-'0';
		ch=getchar(); 
	}
	a=s*w;
}

struct Node
{
	ll x,y,z,xx,yy,zz,p;
}a[N];

ll Bijiao(ll x,ll y,ll z)
{
	if(x>y)
	{
		if(y>=z) return 1;
		if(x>=z&&y<z) return 1;
		if(z>x) return 3;
	}
	if(x<y)
	{
		if(x>=z) return 2;
		if(y>=z&&z>x) return 2;
		if(z>y) return 3;
	}
	if(x==y)
	{
		if(x==z) return 1;
		if(x>z) return 1;
		if(z>x) return 3;
	}
	return 1;
}

ll Cmp(Node a,Node b)
{
	return a.xx>b.xx;
}

ll CMP(Node a,Node b)
{
	return a.x>b.x;
}

ll PoP(Node a,Node b)
{
	return a.p>b.p;
}

ll n,s[6];

int main()//假设满意值不同 
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	read(t);
	//ll  t=1;
	while(t--)
	{
		ll f=1,ff=1;
		read(n);
		for(ll i=1;i<=n;i++)
		{
			ll minn=2e5+7;
			read(a[i].x);
			read(a[i].y);
			read(a[i].z);
			if(a[i].y!=0||a[i].z!=0)
			{
				f=0;
			}
			if(a[i].z!=0)
			{
				ff=0;
			}
			minn=min(a[i].x,min(a[i].y,a[i].z));
			a[i].xx=a[i].x-minn;
			a[i].yy=a[i].y-minn;
			a[i].zz=a[i].z-minn;
			a[i].p=Bijiao(a[i].x,a[i].y,a[i].z);
		} 
		ll ans=0;
		
		if(f==1)
		{
			ll js=1;
			sort(a+1,a+1+n,CMP);
			for(ll i=1;i<=n;i++)
			{
				if(js>n/2)
				{
					cout<<ans<<"\n";
					break;
				}
				ans+=a[i].x;
				js++;
			}
		}
		
		else if(ff==1)
		{
			ll js=1;
			for(ll i=1;i<=n;i++)
			{
				a[i].p=sqrt((a[i].x-a[i].y)*(a[i].x-a[i].y));
				//cout<<a[i].p<<" ";
			}
			sort(a+1,a+1+n,PoP);
			s[1]=1,s[2]=1;
			for(ll i=1;i<=n;i++)
			{
				if(s[2]>(n/2))
				{
					ans+=a[i].x;
					s[1]++;
					continue;
				}
				if(s[1]>(n/2))
				{
					ans+=a[i].y;
					s[2]++;
					continue;
				}
				if(a[i].x<a[i].y&&s[2]<=(n/2))
				{
					//cout<<a[i].y<<" ";
					ans+=a[i].y;
					s[2]++;
					continue;
				}
				if(a[i].x>=a[i].y&&s[1]<=(n/2))
				{
					//cout<<a[i].y<<" ";
					ans+=a[i].x;
					s[1]++;
					continue;
				}
			}
			cout<<ans<<"\n";
		}
		else
		{
			sort(a+1,a+1+n,Cmp);
			s[1]=1,s[2]=1,s[3]=1;
			for(ll i=1;i<=n;i++)
			{
				if(s[2]>(n/2))
				{
					if(s[3]>(n/2))
					{
						ans+=a[i].x;
						s[1]++;
						continue;
					}
					if(s[1]>(n/2))
					{
						ans+=a[i].z;
						s[3]++;
						continue;
					}
					if(a[i].x<a[i].z&&s[3]<=(n/2))
					{
						//cout<<a[i].y<<" ";
						ans+=a[i].z;
						s[3]++;
						continue;
					}
					if(a[i].x>=a[i].z&&s[1]<=(n/2))
					{
						//cout<<a[i].y<<" ";
						ans+=a[i].x;
						s[1]++;
						//cout<<"-1";
						continue;
					}
				}
				else if(s[1]>(n/2))
				{
					//cout<<"-1";
					if(s[2]>(n/2))
					{
						ans+=a[i].z;
						s[3]++;
						continue;
					}
					if(s[3]>(n/2))
					{
						ans+=a[i].y;
						s[2]++;
						continue;
					}
					if(a[i].y<a[i].z&&s[3]<=(n/2))
					{
						//cout<<a[i].y<<" ";
						ans+=a[i].z;
						s[3]++;
						continue;
					}
					if(a[i].y>=a[i].z&&s[2]<=(n/2))
					{
						//cout<<a[i].y<<" ";
						ans+=a[i].y;
						s[2]++;
						continue;
					}
				}
				else if(s[3]>(n/2))
				{
					if(s[2]>(n/2))
					{
						ans+=a[i].x;
						s[1]++;
						continue;
					}
					if(s[1]>(n/2))
					{
						ans+=a[i].y;
						s[2]++;
						continue;
					}
					if(a[i].x<a[i].y&&s[2]<=(n/2))
					{
						//cout<<a[i].y<<" ";
						ans+=a[i].y;
						s[2]++;
						continue;
					}
					if(a[i].x>=a[i].y&&s[1]<=(n/2))
					{
						//cout<<a[i].y<<" ";
						ans+=a[i].x;
						s[1]++;
						continue;
					}
				}
				int op=Bijiao(a[i].x,a[i].y,a[i].z);
				if(op==1)
				{
					ans+=a[i].x;
					s[1]++;
				//	cout<<n<<" "<<s[1]<<" ";
					continue;
				}
				if(op==2)
				{
					ans+=a[i].y;
					s[2]++;
					
					continue;
				}
				if(op==3)
				{
					ans+=a[i].z;
					s[3]++;
					continue;
				}
			}
			cout<<ans<<"\n";
		}
		
	}
	return 0;
}
//T1 14:30 开始想 
//14:40 第一步：找差值 
//14:50 尝试 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

