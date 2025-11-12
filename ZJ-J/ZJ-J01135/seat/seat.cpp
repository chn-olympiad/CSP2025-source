#include<bits/stdc++.h>
using namespace std;

int n,m,a[109];

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int tot=n*m;
	for(int i=1;i<=tot;i++)
	{
		scanf("%d",&a[i]);
	}
	int ans=a[1];
	sort(a+1,a+tot+1,cmp);
	int i=1,j=1,idx=1;
	bool flag=1;
	while(idx<tot)
	{
		if(j>n) j=n,i++,flag=0;
		else if(j<1) j=1,i++,flag=1;
		if(a[idx]==ans)
		{
			printf("%d %d",i,j);
			break;
		}
		if(flag)
		{
			idx++;
			j++;
		}
		else
		{
			idx++;
			j--;
		}
	}
	return 0;
}
