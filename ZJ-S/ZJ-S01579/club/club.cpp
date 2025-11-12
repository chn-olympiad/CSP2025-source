#include<bits/stdc++.h>
const int slen=1e5+10;
using namespace std;
int t,n,tt[4];
long long ans=0;
struct info
{
	int node,num,c1,c2;
}a[slen][3];
struct info1
{
	int num1,num2,num3,c1,c2,node1,node2,node3;
}b[slen];
bool cmp(info x,info y)
{
	return x.num>y.num;
}
bool cmp2(info1 x,info1 y)
{
	if(x.c1==y.c1&&x.c2==y.c2&&x.num1==y.num1) return x.num2>y.num2;
	if(x.c1==y.c1&&x.c2==y.c2) return x.num1>y.num1;
	if(x.c1==y.c1) return x.c2>y.c2;
	return x.c1>y.c1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		tt[1]=tt[2]=tt[3]=0;ans=0;
		cin>>n;
		int m=n/2;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i][0].num>>a[i][1].num>>a[i][2].num;
			a[i][0].node=1;a[i][1].node=2;a[i][2].node=3;
			sort(a[i],a[i]+3,cmp);
		}
		for(int i=1;i<=n;++i) 
		{
			b[i].num1=a[i][0].num;b[i].num2=a[i][1].num;b[i].num3=a[i][2].num;
			b[i].node1=a[i][0].node;b[i].node2=a[i][1].node;b[i].node3=a[i][2].node;
			b[i].c1=b[i].num1-b[i].num2;b[i].c2=b[i].num2-b[i].num3;
		}
		sort(b+1,b+n+1,cmp2);
		for(int i=1;i<=n;++i)
		{
			if(tt[b[i].node1]<m) {ans+=b[i].num1;tt[b[i].node1]++;}
			else if(tt[b[i].node2]<m) {ans+=b[i].num2;tt[b[i].node2]++;}
			else if(tt[b[i].node3]<m) {ans+=b[i].num3;tt[b[i].node3]++;}
		}
		cout<<ans<<endl;
	}
	return 0;
}