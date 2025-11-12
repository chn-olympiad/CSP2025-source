#include<bits/stdc++.h>//b-road
using namespace std;
int n,m,k;
int rd;//road 1e5+1e6
int u,v,w;
bool csh[16];
int c[16],a;
long long ans;
int f[2000006];//size=1e5+1e6 / n
int ln,cshcnt;//边数 已经城市化的个数 / rd/ k
int tx,ty;//1e5+1e6=n
struct node{
	int x,y;
	long long v;
	int xc;//隶属的乡村序号 
	inline friend bool operator<(node a,node b)
	{
		return b.v<a.v;
	}
};
priority_queue<node> q;//size=1e5+1e6

int find(int x)
{
	if(f[x]==x)
	{
		return x;
	}
	return f[x]=find(f[x]);
}

inline void read(register int &a)
{
	a=0;register char c;
	while((c=getchar())<48);
	do a=(a<<3)+(a<<1)+(c^48);
	while((c=getchar())>47);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		read(w);
		q.push((node){u,v,w,0});
	}
	for(int i=1;i<=k;i++)
	{
		read(c[i]);
		for(int j=1;j<=n;j++)
		{
			read(a);
			q.push((node){n+i,j,c[i]+a,i});
		}
	}
	rd=m+k*n;
	for(int i=1;i<=rd;i++) f[i]=i;
	for(int i=1;i<=rd&&ln<cshcnt+n-1;i++)
	{
		tx=find(q.top().x);
		ty=find(q.top().y);
	//	cout<<q.top().x<<"("<<tx<<")";//
	//	cout<<">"<<q.top().y<<"("<<ty<<")"<<":"<<q.top().v<<'\n';//
		if(tx!=ty)
		{
			++ln; 
			f[tx]=ty;
			ans+=q.top().v;
			if(q.top().xc!=0&&csh[q.top().xc]==1)
			{
				ans-=c[q.top().xc];
			//	cout<<ans<<'\n';//
			}
			else if(q.top().xc!=0&&csh[q.top().xc]==0)
			{
				csh[q.top().xc]=1;
				++cshcnt;
			}
		}
		q.pop();
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

双向道路

n座城市
m条连接两座城市的双向道路
k个准备进行城市化改造的乡镇(对其进行城市化改造的费用为c[j])

cout:最小费用
*/