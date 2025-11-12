#include<bits/stdc++.h>
using namespace std;
struct Node{
	int l,r;
};
Node b[500010];
int n,k,a[500010],ans,Max,sum[500010];
bool cmp(Node aa,Node bb)
{
	return aa.r<bb.r || aa.r==bb.r && aa.l>bb.l;
}
void cx1()
{
	for(int i=1;i<=n;i++)
	  sum[i]=sum[i-1]^a[i],b[i].r=INT_MAX,b[i].l=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int kkk=sum[j]^sum[i-1];
			if(kkk==k)
			{
				b[i].r=j;
				b[i].l=i;
				break;
			}
		}
	}
	sort(b+1,b+n+1,cmp);
	int nr=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i].l==INT_MAX) break;
		if(b[i].l>nr) ans++,nr=b[i].r;
	}
	cout<<ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	  cin>>a[i],Max=max(Max,a[i]);
	if(n<=3000) cx1();
	else
	{
		if(k==0 && Max<2)
		{
			for(int i=1;i<=n;i++)
			if(a[i]==0) ans++;
			for(int i=1;i<=n;i++)
			if(a[i]==1 && a[i+1]==1) ans++,a[i+1]=0;
			cout<<ans;
		}
		else if(k==1 && Max<2)
		{
			for(int i=1;i<=n;i++)
			  ans+=a[i];
			cout<<ans;
		}
		else cx1();
	}
}