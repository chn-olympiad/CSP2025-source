#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
using namespace std;
pair<int,int> a[100005],b[100005],c[100005];
bool vis[100005];
int f(int sum,int flag,int n)
{
	int cnta=0,cntb=0,cntc=0;
	if(flag==1)cnta=n;
	if(flag==2)cntb=n;
	if(flag==3)cntc=n;
	int i;
	for(i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			if(flag==1)
			{
				if(b[i].first>c[i].first)
				{
					sum+=b[i].first;
					cntb++;
				}
				else
				{
					sum+=c[i].first;
					cntc++;
				}
			}
			else if(flag==2)
			{
				if(a[i].first>c[i].first)
				{
					sum+=a[i].first;
					cnta++;
				}
				else
				{
					sum+=c[i].first;
					cntc++;
				}
			}
			else
			{
				if(a[i].first>b[i].first)
				{
					sum+=a[i].first;
					cnta++;
				}
				else
				{
					sum+=b[i].first;
					cntb++;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(vis[i]==1)
		{
			if(flag==1)
			{
				if(b[i]>c[i])
				{
					if(b[i].first>a[i].first&&cntb<n/2)
					{
						sum+=b[i].first-a[i].first;
						cntb++;
					}
				}
				else if(b[i]<c[i])
				{
					if(c[i].first>a[i].first&&cntc<n/2)
					{
						sum+=c[i].first-a[i].first;
						cntc++;
					}
				}
			}
			else if(flag==2)
			{
				if(a[i]>c[i])
				{
					if(a[i].first>b[i].first&&cnta<n/2)
					{
						sum+=a[i].first-b[i].first;
						cnta++;
					}
				}
				else if(a[i]<c[i])
				{
					if(c[i].first>b[i].first&&cntc<n/2)
					{
						sum+=c[i].first-b[i].first;
						cntc++;
					}
				}
			}
			else
			{
				if(a[i]>b[i])
				{
					if(a[i].first>c[i].first&&cnta<n/2)
					{
						sum+=a[i].first-c[i].first;
						cnta++;
					}
				}
				else if(a[i]<b[i])
				{
					if(b[i].first>c[i].first&&cntb<n/2)
					{
						sum+=b[i].first-c[i].first;
						cntb++;
					}
				}
			}
		}
	}
	return sum;
}
void solve()
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > sum1,sum2,sum3;
	int n;
	cin>>n;
	int i,j;
	int suma=0,sumb=0,sumc=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i].first,&b[i].first,&c[i].first);
		a[i].second=b[i].second=c[i].second=i;
	}
	for(i=1;i<=n;i++)
	{
		suma+=a[i].first;
		sumb+=b[i].first;
		sumc+=c[i].first;
		sum1.push(a[i]);
		sum2.push(b[i]);
		sum3.push(c[i]);
		if(sum1.size()>n/2)
		{
			suma-=sum1.top().first;
			sum1.pop();
		}
		if(sum2.size()>n/2)
		{
			sumb-=sum2.top().first;
			sum2.pop();
		}
		if(sum3.size()>n/2)
		{
			sumc-=sum3.top().first;
			sum3.pop();
		}
	}
	int sum=0;
	int flag;
	int maxn=-INF;
	sum+=suma;
	memset(vis,0,sizeof(vis));
	while(!sum1.empty())
	{
		vis[sum1.top().second]=1;
		sum1.pop();
	}
	flag=1;
	sum=f(sum,flag,n);
	maxn=max(maxn,sum);
	
	
	sum=0;
	sum+=sumb;
	memset(vis,0,sizeof(vis));
	while(!sum2.empty())
	{
		vis[sum2.top().second]=1;
		sum2.pop();
	}
	flag=2;
	sum=f(sum,flag,n);
	maxn=max(maxn,sum);
	
	
	sum=0;
	sum+=sumc;
	memset(vis,0,sizeof(vis));
	while(!sum3.empty())
	{
		vis[sum3.top().second]=1;
		sum3.pop();
	}
	flag=3;
	sum=f(sum,flag,n);
	maxn=max(maxn,sum);
	
	
	cout<<maxn;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
