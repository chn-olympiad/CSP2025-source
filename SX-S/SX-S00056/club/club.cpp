#include<bits/stdc++.h>
using namespace std;
long long T,n,a[100005][4],is[100005],ans;
struct node{
	long long dat,i;
}x[100005],y[100005],z[100005];
bool cmp(node a,node b)
{
	return a.dat>b.dat;
}
priority_queue<pair<long long,long long> > mq;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			x[i]={a[i][1],i};
			y[i]={a[i][2],i};
			z[i]={a[i][3],i};
		}
		sort(x+1,x+1+n,cmp);
		sort(y+1,y+1+n,cmp);
		sort(z+1,z+1+n,cmp);
		long long rans=0,ans=0;
		for(long long i=1;i<=n;i++)
		{
			ans+=x[i].dat;
			is[x[i].i]=1;
		}
		for(long long i=1;i<=n;i++)
		{
			long long cz=y[i].dat-a[y[i].i][1];
			if(mq.size()<n/2)
			{
				mq.push(make_pair(-cz,i));
			}
			else
			{
				pair<long long,long long> f=mq.top();
				mq.pop();
				if(-f.first>cz)
				{
					mq.push(f);
					continue;
				}
				else
				{
					mq.push(make_pair(-cz,i));
				}
			}
		}
		while(mq.size())
		{
			pair<long long,long long> f=mq.top();
			mq.pop();
			ans-=f.first;
			is[y[f.second].i]=2;
		}
		for(long long i=1;i<=n;i++)
		{
			long long cz=z[i].dat-a[z[i].i][is[z[i].i]];
			if(mq.size()==n/2)
			{
				pair<long long,long long> f=mq.top();
				mq.pop();
				if(-f.first>cz)
				{
					mq.push(f);
				}
				else
				{
					mq.push(make_pair(-cz,i));
				}
			}
			else if(cz>0)
			{
				mq.push(make_pair(-cz,i));
			}
		}
		while(mq.size())
		{
			ans-=mq.top().first;
			mq.pop();
		}
		cout<<ans<<endl;
	}
	return 0;
}
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