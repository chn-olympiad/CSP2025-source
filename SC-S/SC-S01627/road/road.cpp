#include<bits/stdc++.h>
//#define int long long
using namespace std;
inline long long read()
{
	long long x=0;
	int f=0;
	char c=getchar();
	while(!isdigit(c))
	{
		f|=c=='-';
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f?(-x):x;
}
struct nnode
{
	int nxt,to,f;
	long long w;
}eedge[2000010];
int hhead[100000],ttot;
void Add(int x,int y,long long w)
{
	eedge[++ttot].nxt=hhead[x];
	eedge[ttot].to=y;
	eedge[ttot].w=w;
	eedge[ttot].f=x;
	hhead[x]=ttot;
}
struct nnnode
{
	int nxt,to;
	long long w;
	int flag;
}edge[300010];
int head[100000],tot;
void add(int x,int y,long long w,int f)
{
//	cout<<"checkadd"<<x<<' '<<y<<' '<<w<<' '<<f<<endl;
	edge[++tot].nxt=head[x];
	edge[tot].to=y;
	edge[tot].w=w;
	edge[tot].flag=f;
	head[x]=tot;
}
int n,m,k;
long long c[14];
long long a[14][10010];
struct node
{
	long long w;
	int to,f;
	bool operator <(node const &y) const
	{
		return w>y.w;
	}
};
priority_queue<node>q;
int book[20010];
long long Min;
int ff[20010];
void K(int xgd)
{
	while(!q.empty())q.pop();
	memset(book,0,sizeof(book));
	long long ans=0;
	int id=1;
	int num=1;
//	int nj=0;
	ff[0]=1;
	while(xgd)
	{
		if(xgd&1)
		{
			ff[num]=1;
//			nj++;
			ans+=c[num];
		}
		else ff[num]=0;
		num++;
		xgd>>=1;
	}
	int cnt=1;
	int hys=1;
	while(cnt<=n)
	{
//		cout<<"qwq";
		if(hys!=1)
		{
			node tmp=q.top();
			while(book[tmp.to])
			{
				q.pop();
				tmp=q.top();
			}
			id=tmp.to;
			ans+=tmp.w;
			if(ans>Min)return;
//			cout<<"ans="<<ans<<"   "<<id<<endl;
			q.pop();
		}
		hys=2;
		book[id]=1;
		if(id<=n)cnt++;
		for(int i=head[id];i;i=edge[i].nxt)
		{
			int to=edge[i].to;
			long long w=edge[i].w;
			if(book[to]==0&&ff[edge[i].flag])
			{
				node tmp;
				tmp.to=to;
				tmp.w=w;
//				cout<<"checkedge"<<to<<' '<<w<<endl;
				q.push(tmp);
			}
		}
	}
	Min=min(Min,ans);
//	cout<<Min;
}
void kk()
{
	long long checkans=0;
	int id=1;
	for(int I=1;I<=n;I++)
	{
//		cout<<"qwq";
		if(I!=1)
		{
			node tmp=q.top();
			while(book[tmp.to])
			{
				q.pop();
				tmp=q.top();
			}
			id=tmp.to;
			checkans+=tmp.w;
			add(tmp.f,tmp.to,tmp.w,0);
			add(tmp.to,tmp.f,tmp.w,0);
//			cout<<checkans<<endl;
			q.pop();
		}
		book[id]=1;
		for(int i=hhead[id];i;i=eedge[i].nxt)
		{
			int to=eedge[i].to;
			long long w=eedge[i].w;
			int f=eedge[i].f;
			if(book[to]==0)
			{
				node tmp;
				tmp.to=to;
				tmp.w=w;
				tmp.f=f;
				q.push(tmp);
			}
		}
	}
	Min=checkans;
//	cout<<Min;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++)
	{
		int u,v;
		long long w;
		u=read();
		v=read();
		w=read();
		Add(u,v,w);
		Add(v,u,w);
	}
	kk();
//	if((double)clock()/(double)CLOCKS_PER_SEC>0.85)
//	{
//		printf("%lld",Min);
//		return 0;
//	}
	int checka=0;
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		if(c[i]!=0)checka=1;
		for(int j=1;j<=n;j++)
		{
			a[i][j]=read();
			add(n+i,j,a[i][j],i);
			add(j,n+i,a[i][j],i);
		}
	}	
	int xgdd=0;
	if(checka==0)
	{
		K((1<<k)-1);
	}
	else
	for(int i=1;i<(1<<k);i++)
	{
//		cout<<"\n\nI="<<i<<endl;
		K(i);
		xgdd++;
		if(xgdd%10==0)
		if((double)clock()/(double)CLOCKS_PER_SEC>0.9)
		{
			printf("%lld",Min);
			return 0;
		}

	}
	printf("%lld",Min);
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


*/