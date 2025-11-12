#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=2e6+5;
int n,m,k,ans,last,a[N],s[N],id[N];
struct node
{
	int l,r; 
}q[N];
vector<int>p[M];
bool cmp(node x,node y)
{
	return x.r<y.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i],s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;++i) p[s[i]].push_back(i);
	for(int i=1;i<=n;++i)
	{
		if(p[s[i-1]^k].size()!=id[s[i-1]^k]) q[++m]=node{i,p[s[i-1]^k][id[s[i-1]^k]]};
		id[s[i]]++;
	}
	sort(q+1,q+1+m,cmp);
	for(int i=1;i<=m;++i)
	if(last<q[i].l)
	{
		last=q[i].r;
		ans++;
	}
	cout<<ans;
	return 0;
}
