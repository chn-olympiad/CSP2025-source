#include<bits/stdc++.h>
using namespace std;
long long int i,t,n,j,s,k,dp[100006][4];
struct ccc
{int a,b,c,v,vv,w;}q[100005];
bool cmp(ccc x,ccc y)
{return x.a>y.a;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		s=0;
		cin>>n;
		for(i=1;i<=n;i++)
		cin>>q[i].a>>q[i].b>>q[i].c;
		sort(q+1,q+1+n,cmp);
		for(i=1;i<=n/2;i++)
		s+=q[i].a;
		cout<<s<<endl;
	}
	return 0;
}
//ÌØÊâ-A  5·Ö
