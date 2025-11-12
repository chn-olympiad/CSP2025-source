#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int n,ans;
struct node
{
	int a,b,c;
	int m1,m2,m3;
}a[N];
vector<int> A,B,C;
bool cmp(int x,int y){return a[x].m2-a[x].m1>a[y].m2-a[y].m1;}
void solve()
{
	ans=0;
	A.clear();
	B.clear();
	C.clear();
	for(int i=1;i<=n;i++) a[i].a=a[i].b=a[i].c=a[i].m1=a[i].m2=a[i].m3=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		if(a[i].a>=a[i].b&&a[i].a>=a[i].c)
		{
			a[i].m1=a[i].a;
			if(a[i].b>=a[i].c) a[i].m2=a[i].b,a[i].m3=a[i].c;
			else a[i].m2=a[i].c,a[i].m3=a[i].b;
		}
		else if(a[i].b>=a[i].a&&a[i].b>=a[i].c)
		{
			a[i].m1=a[i].b;
			if(a[i].a>=a[i].c) a[i].m2=a[i].a,a[i].m3=a[i].c;
			else a[i].m2=a[i].c,a[i].m3=a[i].a;
		}
		else
		{
			a[i].m1=a[i].c;
			if(a[i].a>=a[i].b) a[i].m2=a[i].a,a[i].m3=a[i].b;
			else a[i].m2=a[i].b,a[i].m3=a[i].a;
		}
		if(a[i].a>=a[i].b&&a[i].a>=a[i].c) A.push_back(i),ans+=a[i].a;
		else if(a[i].b>=a[i].a&&a[i].b>=a[i].c) B.push_back(i),ans+=a[i].b;
		else C.push_back(i),ans+=a[i].c;
	}
	if((int)A.size()>n/2)
	{
		sort(A.begin(),A.end(),cmp);
		int num=A.size()-n/2;
		for(int i=0;i<num;i++) ans+=a[A[i]].m2-a[A[i]].m1;
	}
	else if((int)B.size()>n/2)
	{
		sort(B.begin(),B.end(),cmp);
		int num=B.size()-n/2;
		for(int i=0;i<num;i++) ans+=a[B[i]].m2-a[B[i]].m1;
	}
	else if((int)C.size()>n/2)
	{
		sort(C.begin(),C.end(),cmp);
		int num=C.size()-n/2;
		for(int i=0;i<num;i++) ans+=a[C[i]].m2-a[C[i]].m1;
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--) solve();
	return 0;
}
