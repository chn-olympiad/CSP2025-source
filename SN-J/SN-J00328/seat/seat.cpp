//100
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int sum,idc;
}a[10001];
bool cmp(node a,node b)
{
	return a.sum>b.sum;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int n,m,t=0,x=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			t++;
			cin>>a[t].sum;
			a[t].idc=t;
		}
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++)
	{
		if(a[i].idc==1) 
		{
			x=i;
			break;
		}
	}
	int num=(x-1)/n+1,aa=x%n;
	if(num%2==1)
	{
		if(aa==0) cout<<num<<" "<<n;
		else cout<<num<<" "<<aa;
	}
	else 
	{
		if(aa==0) cout<<num<<" "<<1;
		else cout<<num<<" "<<n-aa+1;
	}
	return 0;
} 
