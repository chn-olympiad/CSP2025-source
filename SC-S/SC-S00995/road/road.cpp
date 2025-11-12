#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5,M=1e6+5,K=12,P=1030;
int n,m,k,c[K],x,y,z,f[N+K],d[P],num,ans;
int read()
{
	int t=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')t=t*10+c-'0',c=getchar();
	return t*f;
}
struct edge
{
	int l,r,w;
}a[M],b[K][N];
vector<edge>vec[P];
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int find(int num)
{
	if(f[num]==num)return num;
	return f[num]=find(f[num]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=m;i++)x=read(),y=read(),z=read(),a[i]={x,y,z};
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int v=1;v<=n;v++)x=read(),b[i][v]={0,v,x};
		sort(b[i]+1,b[i]+1+n,cmp);
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int s1=find(a[i].l),s2=find(a[i].r);
		if(s1==s2)continue;
		vec[0].push_back({a[i].l,a[i].r,a[i].w});
		d[0]+=a[i].w;
//		cout<<a[i].l<<" "<<a[i].r<<" "<<a[i].w<<"\n";
		f[s1]=s2;
	}
	ans=d[0];
//	cout<<ans<<"\n";
	for(int i=1;i<(1<<k);i++)
	{
		int C=0,v,cnt=0;
		for(int z=1;z<=k;z++)
		{
			if(!((1<<(z-1))&i))continue;
			C+=c[z];
			v=z;
			cnt++;
		}
//		cout<<C<<"\n";
		for(int z=1;z<=n+k;z++)f[z]=z;
		int y=(i-(1<<(v-1))),sum=0;
		num=1;
		for(int z=0;z<vec[y].size();z++)
		{
			edge it=vec[y][z];
			if(num>n||it.w<=b[v][num].w)
			{
//					cout<<it.l<<" "<<it.r<<" "<<it.w<<"\n";
				int s1=find(it.l),s2=find(it.r);
//					cout<<s1<<" "<<s2<<"\n";
				if(s1==s2)continue;
				vec[i].push_back(it);
				sum+=it.w;
				f[s1]=s2;
			}
			else
			{
//					cout<<"*"<<v+n<<" "<<b[v][num].r<<" "<<b[v][num].w<<"\n";
				z--;
				int s1=find(v+n),s2=find(b[v][num].r);
//					cout<<s1<<" "<<s2<<"\n";
				if(s1==s2)
				{
					num++;continue;
				}
				vec[i].push_back({v+n,b[v][num].r,b[v][num].w});
				sum+=b[v][num].w;
				f[s1]=s2;
				num++;
			}
		}
//		cout<<i<<" "<<v<<"\n";
//		for(int z=0;z<vec[i].size();z++)cout<<vec[i][z].l<<" "<<vec[i][z].r<<" "<<vec[i][z].w<<"\n";
//		cout<<"\n";
		ans=min(ans,sum+C);
	}
	cout<<ans;
	return 0;
}
/*
状压 dp
记录每个状态使用的边。 
做最小生成树。

时间复杂度：O(2^k*n*2*log2n) 
*/