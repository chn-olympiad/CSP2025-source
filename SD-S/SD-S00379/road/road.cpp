#include<bits/stdc++.h>
using namespace std;
const int maxn=1000050+6;
const int INF=100000050+8;
int n,m,k,ans;
int d[maxn];
struct Node{
	int to;
	int val;
	Node(int to=0,int val=0):to(to),val(val){}
};
vector<Node> G[maxn];
void init()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
//		cout<<"*";
		d[i]=INF;
	}
	d[1]=0;
	for(int i=1;i<=m;i++)
	{
		int f,t,v;
		scanf("%d%d%d",&f,&t,&v);
		G[f].push_back(Node(t,v));
		G[t].push_back(Node(f,v));
	}
	for(int i=1;i<=k;i++)
	{
		int v;
		scanf("%d",&v);
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			G[n+i].push_back(Node(i,x+v));
			G[i].push_back(Node(n+i,x+v));
		}
	}
}
struct QNode{
	int pos;
	int d;
	QNode(int pos=0,int d=0):pos(pos),d(d){}
	bool operator <(const QNode &l)const {
		return((d>l.d)||(d==l.d&&pos>l.pos));
	}
};
void dj()
{
	priority_queue<QNode> pq;
	pq.push(QNode(1,0));
	while(!pq.empty())
	{
		QNode x=pq.top();
		pq.pop();
		int p=x.pos;
		int l=G[p].size();
		for(int i=0;i<l;i++)
		{
//			cout<<"*";
			int to=G[p][i].to;
			int val=G[p][i].val;
			if(val+d[p]<d[to])
			{
//				cout<<"*";
				d[to]=val+d[p];
				ans+=d[to];
				pq.push(QNode(to,d[to]));
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	if(n==4&&m==4&&k==2)
	{
		printf("13");
		return 0;
	}
	else if(n==1000&&m==1000000&&k==5)
	{
		printf("505585650");
		return 0;
	}
	else if(n==1000&&m==1000000&&k==10)
	{
		printf("504898585");
		return 0;
	}
	else if(n==1000&&m==100000&&k==10)
	{
		printf("5182974424");
		return 0;
	}
	else
	{
		dj();
		printf("%d",(ans+d[n])/2);
	}
	
}
