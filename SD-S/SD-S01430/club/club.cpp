//longlong? MLE? clear?
#include<bits/stdc++.h>
#define LL long long
#define LOCAL
using namespace std;
const int N=1e5+10;
const LL INF=1e18;
LL rd()
{
	LL s=0,g=1;char c=getchar();
	while(!isdigit(c)){if(c=='-');c=getchar();}
	while(isdigit(c)){s=(s<<3)+(s<<1)+(c-'0');c=getchar();}
	return s*g;
}
void wt(LL x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>9){wt(x/10);}
	putchar(x%10+'0');
	return ;
}
int t,n,m;
int a[N][5];
LL ans;
struct Node
{
	LL x;
	int id,f;
	bool operator < (const Node &A) const
	{
		return x<A.x;
	}
};
priority_queue<Node> q[4];
void Push(int bl,int id)
{
	LL c;
	int f;
	if(bl==1)
	{
		if(a[id][2]>a[id][3])
		{
			c=a[id][2];
			f=2;
		}
		else
		{
			c=a[id][3];
			f=3;
		}
	}
	else if(bl==2)
	{
		if(a[id][1]>a[id][3])
		{
			c=a[id][1];
			f=1;
		}
		else
		{
			c=a[id][3];
			f=3;
		}
	}
	else
	{
		if(a[id][1]>a[id][2])
		{
			c=a[id][1];
			f=1;
		}
		else
		{
			c=a[id][2];
			f=2;
		}
	}
	//cout<<bl<<" "<<-a[id][bl]+c<<" "<<id<<" "<<f<<endl;
	q[bl].push({-a[id][bl]+c,id,f});
}
int main()
{
	#ifdef LOCAL
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
	#endif
	t=rd();
	while(t--)
	{
		ans=0;
		for(int i=1;i<=3;i++)
		{
			while(q[i].size())q[i].pop();
		}
		n=rd();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				a[i][j]=rd();
			}
		}
		for(int i=1;i<=n;i++)
		{
			LL mx=-INF,idx=0; //记录当前点的最大贡献
			int id=0,f=0; 
			for(int j=1;j<=3;j++)
			{
				if(q[j].size()<n/2)
				{
					if(a[i][j]>mx)
					{
						mx=a[i][j];
						idx=j;
					}
				}
				else
				{
					LL gx=a[i][j]+q[j].top().x;
					id=q[j].top().id,f=q[j].top().f;
					if(gx>mx)
					{
						mx=gx;
						idx=j;
					}
				}
			}
			//cout<<"i:"<<i<<" mx:"<<mx<<endl;
			ans+=mx;
			if(q[idx].size()<n/2)
			{
				Push(idx,i);
			//	q[idx].push({-a[i][idx]+max(a[id]),i});
			//	ans+=a[i][idx];
			}
			else
			{
				q[idx].pop();
				Push(idx,i);
			//	q[idx].push({a[i][idx],i});
				Push(f,id);
			//	q[f].push({a[id][f],id});
			//	ans+=a[i][idx]-b+c;
			}
//			cout<<idx<<endl;
		}
		wt(ans),puts("");
	}
	#ifdef LOCAL
		fclose(stdin);
		fclose(stdout);
	#endif
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
/*
18
4
13
*/
