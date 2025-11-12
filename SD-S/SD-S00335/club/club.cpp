#include<iostream>
#include<cstdio>
#include<cstring> 
#include<string>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
//#include<priority_queue>
#include<vector>
using namespace std;
#define int long long
#define R(x) x=read()
#define W(X) write(x)
#define MAXN 1000010
inline int read()
{
	int x,y;
	x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') y=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<1)+(x<<3)+(c^'0');c=getchar();}
	return x*y;
}
inline void write(int x)
{
	if(x<0) {putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0'); 
}
priority_queue<pair<int,int> > q;
struct node
{
	int x,y,z;
	int id;
	int v;
}a[MAXN],c[MAXN],d[MAXN];
int b[MAXN];
bool vis[MAXN];
int cmp(node x,node y)
{
	if(x.x==y.x) return x.y>y.y;
	return x.x>y.x;
}
void dfs(int);
int n;
int t[MAXN];
int maxn=0;
int tag[MAXN];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	R(T);
	while(T--)
	{
		maxn=0;
		R(n);
		bool f1,f2;
		f1=f2=true;
		for(int i=1;i<=n;i++)
		{
			R(a[i].x);
			R(a[i].y);
			R(a[i].z);
			if(a[i].y>0) f1=false;
			if(a[i].z>0) f2=false;
		}
		int ans=0,tot=0;
		if(f1)
		{
			for(int i=1;i<=n;i++)
				b[i]=a[i].x;
			sort(b+1,b+1+n);
			for(int i=n;i>=1;i--)
			{
				ans+=a[i].x,tot++;
				if(tot==n/2) break;
			}
			cout<<ans<<endl;
			continue;
		}
		if(n<=10)
		{
			dfs(1);
			cout<<maxn<<endl;
			continue;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(q.size()<n/2)
			{
				q.push(make_pair(a[i].y,i));
				ans+=a[i].x;
			}
			else
			{
				if(ans-a[q.top().second].x+a[i].x+q.top().first>ans)
				{
					ans=ans-a[q.top().second].x+a[i].x+q.top().first;
					q.pop();
					q.push(make_pair(a[i].y,i));
				}
				else ans+=a[i].y;
			}
		}
		cout<<ans<<endl;
		while(!q.empty()) q.pop();
	}
	return 0;
}
void dfs(int st)
{
	if(st==n+1)
	{
		int now=0;
		int t1,t2,t3;
		t1=t2=t3=0;
		for(int i=1;i<=n;i++)
		{
			if(t[i]==1)
			{
				t1++;
				now+=a[i].x;
			}
			if(t[i]==2)
			{
				t2++;
				now+=a[i].y;
			}
			if(t[i]==3)
			{
				t3++;
				now+=a[i].z;
			}
		}
		if(t1>n/2||t2>n/2||t3>n/2) return;
		maxn=max(maxn,now);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		t[st]=i;
		dfs(st+1);
	}
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


1
2
10 9 8
4 0 0
*/
