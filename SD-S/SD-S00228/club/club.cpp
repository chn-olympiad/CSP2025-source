#include <bits/stdc++.h>
#define x first
#define y second
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
typedef pair<long,long> PLL;
const int N=1e5+10;
struct node
{
	int x,w;
	friend bool operator < (const node &x,const node &y)
	{
		return x.w>y.w;
	}
};
int a[N],b[N],c[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int c1=0,c2=0,c3=0,ans=0;
		priority_queue<node> q1,q2,q3;
		int f=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]!=0||b[i]!=0)
			{
				f=0;
			}
		}
		if(f)
		{
			priority_queue<int> q;
			for(int i=1;i<=n;i++)
			{
				q.push(c[i]);
			}
			for(int i=1;i<=n/2;i++)
			{
				ans+=q.top();
				q.pop();
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]>=c[i]&&a[i]>=b[i])
			{
				if(c1<n/2)
				{
					ans+=a[i];
					c1++;
					q1.push({i,a[i]});
				}
				else
				{
					int r=q1.top().w;
					int q=q1.top().x;
					int t=c[q]+a[i],o=a[q]+c[i],j=b[q]+a[i],e=b[i]+a[q];
					if(a[i]>q1.top().w)
					{
						ans-=q1.top().w;
						ans+=a[i];
						q1.pop(); 	
						q1.push({i,a[i]});
					}
					else if((t>o||j>e))
					{
						if(t>j)
						{
							ans-=r;
							ans+=t;
							q1.pop();
							c3++;
							q1.push({i,a[i]});
							q3.push({q,c[q]});
						}
						else
						{
							ans-=r;
							ans+=j;
							q1.pop();
							c2++;
							q1.push({i,a[i]});
							q2.push({q,b[q]});
						}
					}
					else
					{
						if(b[i]>c[i])
						{
							c2++;
							ans+=b[i];
							q2.push({i,b[i]});
						}
						else
						{
							c3++;
							ans+=c[i];
							q3.push({i,c[i]});
						}
					}
				}
			}
			else if(c[i]>=a[i]&&c[i]>=b[i])
			{
				if(c3<n/2)
				{
					ans+=c[i];
					c3++;
					q3.push({i,a[i]});
				}
				else
				{
					int r=q3.top().w;
					int q=q3.top().x; 
					int t=c[i]+a[q],o=a[q]+c[i],e=c[q]+b[i],j=c[i]+b[q];
					if(c[i]>q3.top().w)
					{
						ans-=q3.top().w;
						ans+=c[i];
						//int e=q3.top().x;
						q3.pop();
						q3.push({i,c[i]});
					}
					else if((t>o||j>e))
					{
						if(t>j||(t==j&&c1<c2))
						{
							ans-=r;
							ans+=t;
							q3.pop();
							c1++;
							q3.push({i,c[i]});
							q1.push({q,a[q]});
						}
						else
						{
							ans-=r;
							ans+=j;
							q3.pop();
							q3.push({i,c[i]});
							c2++;
							q2.push({q,b[q]});
						}
					}
					else
					{
						if(a[i]>b[i])
						{
							c1++;
							ans+=a[i];
							q1.push({i,a[i]});
						}
						else
						{
							c2++;
							ans+=b[i];
							q2.push({i,b[i]});
						}
					}
				}
			}
			else if(b[i]>=c[i]&&(a[i]<=b[i]))
			{
				if(c2<n/2)
				{
					ans+=b[i];
					c2++;
					q2.push({i,b[i]});
				}
				else
				{
					int r=q2.top().w;
					int q=q2.top().x; 
					if(b[i]>q2.top().w)
					{
						ans-=q2.top().w;
						ans+=b[i]; 
						//int e=q2.top().x;
						q2.pop();
						q2.push({i,b[i]});
					}
					else if((b[i]+c[q]>b[q]+c[i]||b[i]-a[i]>b[q]-a[q]))
					{
						if(b[i]+c[q]>b[i]+a[q]||(b[i]+c[q]==b[i]+a[q]&&c2<c1))
						{
							ans-=r;
							ans+=b[i]+c[q];
							ans+=c[q];
							q2.pop();
							q2.push({i,b[i]});
							c3++; 
							q3.push({q,c[q]});
						}
						else
						{
							ans-=r;
							ans+=a[i]+c[q];
							ans+=c[q];
							q2.pop();
							q2.push({i,b[i]});
							c1++;
							q1.push({q,a[q]});
						}
					}
					else
					{
						if(a[i]>c[i])
						{
							c1++;
							ans+=a[i];
							q1.push({i,a[i]});
						}
						else
						{
							c3++;
							ans+=c[i];
							q3.push({i,c[i]});
						}
					}
				}
			}
		//	cout<<ans<<" ";
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
