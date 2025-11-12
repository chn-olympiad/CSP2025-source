/*
Solution:
给了一堆点
先开C 
17：02回来了 
只会60pts
前20pts就是最小生成树 
特殊性质A就是给了一条免费边
然后能算出每条边代价的最小生成树 
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
怎么又读错题了
k个乡村是新加入的 
所以存在一个与该乡村匹配的等效城市
该城市与其他城市连边即可 

再想想
对于每个乡村k 
计算每一条最小生成树上的边{i,j,w}
如果s[k][i]+s[k][j]<w
那么res+=w-s[k][i]-s[k][j]
如果sigma(res)>=c[k]
就把k城市化  
不行
骗几分吧
假设所有乡村都选 
wc
乡村只有10个
枚举选不选只有1e3个排列 
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+7,M=2e6+7;
int n,m,k,ans,cnt,xx;//cnt:集合数 
struct node{
	int u,v,w;
}a[M];
int fa[N],s[11][N],b[N],c[N];
bool cmp(node xx,node yy)
{
	return xx.w<yy.w;
}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(rand()%2)
	{
		fa[x]=y;
	}
	else
	{
		fa[y]=x;
	}
}
void search()//最小生成树 
{
	cnt=n;
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].u)!=find(a[i].v))
		{
			merge(a[i].u,a[i].v);
			ans+=a[i].w;
			cnt--;
		}
		if(cnt==1)
		{
			return ;
		}
    }
}
void search2(int &res)//最小生成树 
{
	cnt=n;
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].u)!=find(a[i].v))
		{
			merge(a[i].u,a[i].v);
			res+=a[i].w;
			cnt--;
		}
		if(cnt==1)
		{
			return ;
		}
    }
}
int work(int num)
{int now=0;
 	for(int p=1;p<=k;p++)
 	{
 		if(!(1<<(p-1)&num)) continue;
 		now+=c[p];
		for(int i=1;i<=n;i++)
		 	for(int j=1;j<=n;j++)
				a[++m]={i,j,s[p][i]+s[p][j]};
			}
			sort(a+1,a+m+1,cmp);
			for(int i=1;i<=n;i++) fa[i]=i;
			
			search2(now);
	return now;		
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	srand(time(0));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,x;i<=k;i++)
	{
		cin>>c[i];if(c[i]==0) xx++;
		for(int j=1;j<=n;j++)
		{
			cin>>s[i][j];
		}
	}
	if(xx==k||!k){
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i][j]==0)
			{
				b[i]=j;//i和j是等效点 
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[i]!=j) a[++m]={b[i],j,s[i][j]};//直接将第i个乡村的等效城市b[i]与每个j连接，代价与i相同 
		}
	}
	sort(a+1,a+m+1,cmp);
	search();
	cout<<ans<<'\n';
	return 0;
	}
	ans=2147483647;
	int last=m;
	for(int i=0;i<pow(2,k);i++)
	{
		m=last;
		ans=min(ans,work(i));
	 }
	cout<<ans<<'\n';
	return 0;
}
