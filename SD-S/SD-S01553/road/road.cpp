#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1e4+8;
const int MAXM = 2e6+8;
inline LL read()
{
	int num = 0,sign = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9')sign = ch == '-'?-1:1,ch = getchar();
	while(ch >= '0'&&ch <= '9')num = (num<<3)+(num<<1)+ch-'0',ch = getchar();
	return sign>0?num:-num;
}
int n,m,k,dsu[MAXN],a[16][MAXN];
long long ans;
struct ED
{
	int u,v,w;
	bool operator <(const ED&rhs)const {return w < rhs.w;};
}edge[MAXM];
int find(int u){return u == dsu[u]?u:dsu[u] = find(dsu[u]);};
void unite(int u,int v){dsu[find(u)] = find(v);};
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(),m = read(),k = read();
	for(int i = 1;i <= n;i++)dsu[i] = i;
	for(int i = 1;i <= m;i++)edge[i].u = read(),edge[i].v = read(),edge[i].w = read();
	for(int i = 1;i <= k;i++)
	{
		int c = read(),flag = 0;
		for(int j = 1;j <= n;j++)
		{
			a[i][j] = read();
			if(!a[i][j])flag = j;
		}
		if(flag)
		{
			for(int j = m+1;j <= m+n;j++)edge[j].u = flag,edge[j].v = j-m,edge[j].w = a[i][j-m];
			m += n;
		}
	}
	sort(edge+1,edge+m+1);
	int cnt = 0;
	for(int i = 1;i <= m;i++)
		if(find(edge[i].u)!= find(edge[i].v)&&cnt < n-1)unite(edge[i].u,edge[i].v),ans += edge[i].w,cnt++;
	cout<<ans;
	return 0;
}
