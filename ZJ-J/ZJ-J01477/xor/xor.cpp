#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
struct node{
	int l,r;
}b[maxn];
int n,k,a[maxn],q[maxn],cnt,ans,mr;
unordered_map<int,set<int> >mp;
bool cmp(node x,node y)
{
	return x.r<y.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]),q[i]=q[i-1]^a[i],mp[q[i]].insert(i);
	for(int i=1;i<=n;i++)
	  {
	  	int j=k^q[i-1];
	  	if(mp[j].size())
	  	  {
	  	  	cnt++;
	  	  	b[cnt].l=i;
	  	  	b[cnt].r=*(mp[j].begin());
		  }
		mp[q[i]].erase(i);
	  }
	if(!cnt)
	  {
	  	printf("0\n");
	  	return 0;
	  }
	sort(b+1,b+cnt+1,cmp);
	ans=1;
	mr=b[1].r;
	for(int i=2;i<=cnt;i++)
	  if(b[i].l>mr)
	    {
	    	ans++;
	    	mr=b[i].r;
		}
	printf("%d",ans);
	return 0;
}
