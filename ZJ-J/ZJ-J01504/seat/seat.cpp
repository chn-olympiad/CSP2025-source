#include<bits/stdc++.h>
using namespace std;

int n,m;
struct node
{
	int num;
	int sc;
}a[100005];
int k,s;
bool cmp(node x,node y)
{
	return x.sc>y.sc;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);	
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i].sc);
		a[i].num=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].num==1)
		{
			k=i;
			break;
		}
	}
	//cout<<k<<endl;
	if(k%n==0)
		s=k/n;
	else
		s=k/n+1;
	if(s%2==1)
	{
		printf("%d %d",s,k-(s-1)*n);
	}
	else
		printf("%d %d",s,n-(k-(s-1)*n)+1);
	return 0;
}

