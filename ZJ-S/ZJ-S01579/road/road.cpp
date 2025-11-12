#include<bits/stdc++.h>
const int slen=1e6+10;
const int slen1=1e4+10;
using namespace std;
int n,m,k,num,fa[slen1],a[slen1],c[11];
bool f[11];
long long ans;
struct info
{
	int u,v,w,l;
}e[slen*4];
bool cmp(info a,info b)
{
	return a.w<b.w;
}
int getroot(int node)
{
	if(node!=fa[node]) return fa[node]=getroot(fa[node]);
	return node;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		int x,y,z;
		cin>>x>>y>>z;
		e[num].u=x,e[num].v=y,e[num].l=0,e[num++].w=z;
		e[num].u=y,e[num].v=z,e[num].l=0,e[num++].w=z;
	}
	for(int o=1;o<=k;++o)
	{
		cin>>c[o];
		for(int i=1;i<=n;++i) cin>>a[i];
		for(int i=1;i<n;++i)
			for(int j=i+1;j<=n;++j)
				{
					int z=a[i]+a[j]+c[o];
					e[num].u=i,e[num].v=j,e[num].l=o,e[num++].w=z;
					e[num].u=j,e[num].v=i,e[num].l=o,e[num++].w=z;
				}
	}
	sort(e,e+num,cmp);
	for(int i=1;i<=n;++i) fa[i]=i;
	//for(int i=1;i<=num;++i)
	//{
	//	cout<<e[i].w<<endl;
	//}
	int sum=0;
	for(int i=1;i<=2*m;++i)
	{
		if(sum>n-2) break;
		int x=e[i].u,y=e[i].v;
		int tx=getroot(x),ty=getroot(y);
		if(tx==ty) continue;
		fa[tx]=ty;
		if(e[i].l!=0&&f[e[i].l]==true) ans-=c[e[i].l];
		ans+=e[i].w;
		//cout<<e[i].u<<" "<<e[i].v<<endl;
		//cout<<ans<<"LLL"<<endl;
		sum++;
		if(e[i].l!=0) f[e[i].l]=true;
		//cout<<ans<<"LLL"<<endl;
	}
	cout<<ans<<endl;
	return 0;
}