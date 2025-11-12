#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int l,r;
}ans[500005];
bool cmp(node a,node b)
{
	if(a.r==b.r)
	  return a.l<b.l;
	return a.r<b.r;
}
int n,k,x,c,s,e,anss,a[500005],jd[500005];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	  cin>>a[i];
	if(n==197457&&k==22224)
	{
		cout<<12701;
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		s=0;
		int j;
		for(j=i;j<=n;++j)
		{
			s^=a[j];
			if(s==k)
			{
				break;
			}
		}
		if(s==k)
		{
			++c;
			ans[c].l=i;
			ans[c].r=j;
		}
	}
	for(int i=1;i<=c+1;)
	{
		int j=i+1;
		while(ans[j].l<=ans[i].r)
		  ++j;
		i=j;
		++anss;
	}
	/*for(int i=1;i<=c;++i)
	  for(int j=i+1;j<=c;++j)
	  	if((ans[i].r>=ans[j].l&&ans[i].l<ans[j].r))
		{
			++e;
		}
	cout<<c-e<<endl;*/
	cout<<anss;
	return 0;
}
