#include<bits/stdc++.h>
using namespace std;
#define ll long long
int _;
const int N=1e6+7;
int fa[N];
int n,m;
struct node
{
	int u,v,w;
	bool operator<(const node &oth)
	{
		return oth.w>w;
	}
}a[N];
void init(int x)
{
	for(int i=1;i<=x;i++)
	{
		fa[i]=i;
	}
}
int find(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
int k;
void solve() {
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+m+1);
	init(n);
	int cnt=n-1;
	ll sum=0;
	for(int i=1;i<=m;i++)
	{
		int fu=find(a[i].u),fv=find(a[i].v);
		if(fu==fv) continue;
		else
		{
			fa[fu]=fv;
			cnt--;
			sum+=a[i].w;
		}
	}
//	if(cnt!=0) cout<<"???";
	cout<<sum;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cin>>_;
//	for(int i=1; i<=_; i++) {
//		printf("---test---%d---\n",i);
		solve();
//	}
	return 0;
}
