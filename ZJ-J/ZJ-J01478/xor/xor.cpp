#include<bits/stdc++.h>
using namespace std;
int m[1000005],o[1000005],p[1000005][1000005];
struct qj{
	int l;
	int r;
}q[1000000000005];
bool st(qj a,qj b)
{
	if(a.l==b.l)
	return a.r<b.r;
	return a.l<b.l;
}
int yh(int l,int r)
{
	if(l==r)
	return m[l];
	else
	{
		if(p[l][r]>0)
		return p[l][r];
		else
		if(p[l][r]==-1)
		return 0;
		else
		{
			int a=(yh(l,r-1)|m[r])-(yh(l,r-1)&m[r]);
		    if(a)
		    p[l][r]=a;
		    else
		    p[l][r]=-1;
		    return a;
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,w=0,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	scanf("%d",&m[i]);
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
	if(yh(i,j)==k)
	{
		q[w].l=i;
		q[w++].r=j;
	}
	sort(q,q+w,st);
	if(w<=n)
	printf("%d",w);
	else
	printf("%d",n);
	return 0;
}