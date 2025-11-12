#include<bits/stdc++.h>
using namespace std;
struct node{
	int to1,to,val;
}a[5000006]; 
long long fa[100006];
long long c[1005];
long long hf[100006];
bool cmp(node aa,node bb)
{
	return aa.val<bb.val;
}
int get_fa(int fa1)
{
	if(fa[fa1]==fa1)
	{
		return fa1;
	}
	fa[fa1]=get_fa(fa[fa1]);
	return fa[fa1]; 
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(long long i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
	for(long long i=1;i<=m;i++)
	{
		cin>>a[i].to>>a[i].to1>>a[i].val;
	}
	int pp=m;
	for(long long i=1;i<=k;i++)
	{
		cin>>c[i];
		for(long long j=1;j<=n;j++)
		{
			pp++;
			a[pp].to=(n+j);
			a[pp].to1=(j); 
			cin>>a[pp].val;
		}
	}
	sort(a+1,a+1+pp,cmp);
	int oo=n,i=1;
	long long qqqq=0;
	while(oo>0)
	{
		int ff1=get_fa(a[i].to),ff2=get_fa(a[i].to1);
		if(ff1!=ff2)
		{
			oo--;
			qqqq+=a[i].val;
		}
	}
	cout<<qqqq;
	return 0;
} 
