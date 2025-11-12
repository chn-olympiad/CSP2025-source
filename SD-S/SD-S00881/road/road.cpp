#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}a[10000010],b[10000010];
struct Node{
	int to,next,w;
}edge[2000010];
int f[2000010],head[2000010],c[20],w[20],in[10010],cnt,tot,mn,sum=2e9,ans,temp;
int find(int x)
{
	if(x==f[x])
		return f[x];
	f[x]=find(f[x]);
	return f[x];
}
void add(int u,int v,int w)
{
	edge[++tot].to=v;
	edge[tot].w=w;
	edge[tot].next=head[u];
	head[u]=tot;
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k; 
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int x=find(a[i].u),y=find(a[i].v);
		if(f[x]==f[y])
		{
			a[i].w=2e9;
			continue;
		}
		in[a[i].u]++;
		in[a[i].v]++;
		cnt++;
		f[x]=f[y];
		temp+=a[i].w;
		if(cnt==n-1)
		{
			sort(a+1,a+i+1,cmp);
			for(int i=1;i<=cnt;i++)
			{
				add(a[i].u,a[i].v,a[i].w);
				add(a[i].v,a[i].u,a[i].w);
			}
			break;
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			b[(i-1)*n+j].u=j;
			b[(i-1)*n+j].v=i+n;
			cin>>b[(i-1)*n+j].w;
		}
	}
	sort(b+1,b+n*k+1,cmp);
	for(int i=1;i<=n*k;i++)
		cout<<b[i].u<<" "<<b[i].v<<" "<<b[i].w<<endl;
	for(int i=0;i<=(1<<k)-1;i++)
	{
		mn=2e9;
		for(int j=1;j<=n*k;j++)
		{
			if((1<<(b[j].v-n-1))&i==0)
				continue;
			//cout<<i<<" "<<b[j].v-n-1<<" "<<(1<<(b[j].v-n-1))<<" "<<((1<<(b[j].v-n-1))&i)<<endl;
			cout<<b[j].u<<" "<<b[j].v<<" "<<b[j].w<<endl;
			cout<<b[j].u<<" "<<edge[head[b[j].u]].to<<" "<<edge[head[b[j].u]].w<<endl;
			cout<<in[edge[head[b[j].u]].to]<<endl<<endl;
			if(in[edge[head[b[j].u]].to]==1)
			{
				if(b[j].w<edge[head[b[j].u]].w)
				{
					ans+=b[j].w-edge[head[b[j].u]].w;
					cout<<"1:"<<b[j].w-edge[head[b[j].u]].w<<endl;
					in[edge[head[b[j].u]].to]--;
					mn=min(mn,edge[head[b[j].u]].w);
					cout<<"2:"<<mn<<endl;
				}
			}
		}
		cout<<mn<<endl;
		cout<<ans<<endl;
		ans-=(mn!=2e9)*mn;
		sum=min(temp+ans,sum);
	}
	cout<<sum<<endl;
	return 0;
}

