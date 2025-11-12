#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[100005],b[100005],c[100005];
int na,nb,nc;
long long ans;
long long sum;
int pd[100005];
int num[20005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{ 
		sum=0;
		ans=0;
		na=0;
		nb=0;
		nc=0;
		memset(pd,0,sizeof(pd));
		memset(num,0,sizeof(num));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			int p=max(a[i],(max(b[i],c[i])));
			if(p==a[i])
			{
				na++;
			}
			else if(p==b[i])
			{
				nb++;
			}
			else
			{
				nc++;
			}
		}
		if(max(na,max(nb,nc))<=n/2)
		{
			for(int i=1;i<=n;i++)
			{
				ans+=max(a[i],max(b[i],c[i]));
//				cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<" "<<ans<<endl;
			}
//			cout<<ans<<" aaaaaaa";
			continue;
		}
		else
		{
			if(na>n/2)
			{
				for(int i=1;i<=n;i++)
				{
					if(b[i]>=a[i]||c[i]>=a[i])
					{
						continue;
					}
					else
					{
						pd[i]=1;
						num[a[i]-max(b[i],c[i])]++;
						sum++;
					}
				}
				if(sum<=n/2)
				{
					for(int i=1;i<=n;i++)
					{
						ans+=max(a[i],max(b[i],c[i]));
					}
				}
				else
				{
					int p=sum-n/2;
					for(int i=1;i<=20000,p>0;i++)
					{
						if(num[i]>0)
						{
							p-=num[i];
							if(p<0)
							{
								num[i]=-p;
							}
							else
							{
								num[i]=0;
							}
						}
					}
					for(int i=1;i<=n;i++)
					{
						if(pd[i]==0)
						{
							ans+=max(b[i],c[i]);
							continue;
						}
						int m=a[i]-max(b[i],c[i]);
						if(num[m]>0)
						{
							num[m]--;
							ans+=a[i];
						}
						else
						{
							ans+=max(b[i],c[i]);
						}
					}			
				}
//				cout<<" bbbbbbbbbbb";
			}
			else if(nb>n/2)
			{
				for(int i=1;i<=n;i++)
				{
					if(c[i]>=b[i]||a[i]>=b[i])
					{
						continue;
					}
					else
					{
						pd[i]=1;
						num[b[i]-max(a[i],c[i])]++;
						sum++;
					}
				}
				if(sum<=n/2)
				{
					for(int i=1;i<=n;i++)
					{
						ans+=max(b[i],max(a[i],c[i]));
					}
				}
				else
				{
					int p=sum-n/2;
					for(int i=1;i<=20000,p>0;i++)
					{
						if(num[i]>0)
						{
							p-=num[i];
							if(p<0)
							{
								num[i]=-p;
							}
							else
							{
								num[i]=0;
							}
						}
					}
					for(int i=1;i<=n;i++)
					{
						if(pd[i]==0)
						{
							ans+=max(a[i],c[i]);
							continue;
						}
						int m=b[i]-max(a[i],c[i]);
						if(num[m]>0)
						{
							num[m]--;
							ans+=b[i];
						}
						else
						{
							ans+=max(a[i],c[i]);
						}
					}			
				}
//				cout<<" cccccccccccccc";
			}
			else
			{
				for(int i=1;i<=n;i++)
				{
					if(b[i]>=c[i]||a[i]>=c[i])
					{
						continue;
					}
					else
					{
						pd[i]=1;
						num[c[i]-max(b[i],a[i])]++;
						sum++;
					}
				}
				if(sum<=n/2)
				{
					for(int i=1;i<=n;i++)
					{
						ans+=max(c[i],max(b[i],a[i]));
					}
				}
				else
				{
					int p=sum-n/2;
					for(int i=1;i<=20000,p>0;i++)
					{
						if(num[i]>0)
						{
							p-=num[i];
							if(p<0)
							{
								num[i]=-p;
							}
							else
							{
								num[i]=0;
							}
						}
					}
					for(int i=1;i<=n;i++)
					{
						if(pd[i]==0)
						{
							ans+=max(b[i],a[i]);
							continue;
						}
						int m=c[i]-max(b[i],a[i]);
						if(num[m]>0)
						{
							num[m]--;
							ans+=c[i];
						}
						else
						{
							ans+=max(b[i],a[i]);
						}
					}			
				}
			}
//			cout<<" dddddddddddd";
		}
		cout<<ans<<endl;
	}
	return 0;
}