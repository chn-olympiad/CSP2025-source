#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
int seat[maxn];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&seat[i]);
	}
	int order=0;
	for(int i=1;i<=n*m;i++)
	{
		if(seat[1]>seat[i])
		{
			order++;
		}
	}
	order=n*m-order;
	//cout<<"*"<<order<<"*"<<endl;
	int ox,oy=(order-1)/n+1;
	if(oy%2==0)
	{
		ox=(n-order-1)%n+1;
	}
	else
	{
		ox=(order-1)%n+1;
	}
	printf("%d %d",oy,ox);
	return 0;
} 
