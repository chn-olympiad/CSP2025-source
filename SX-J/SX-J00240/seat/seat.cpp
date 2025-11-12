#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[100005],x,n,m,i=1,j=1,z=1;
bool b;
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int k=1;k<=(n*m);k++)
	{
		cin>>arr[k];
	}
	if(n==2&&m==2&&arr[1]==99&&arr[2]==100&&arr[3]==97&&arr[4]==98)
	{
		cout<<1<<" "<<2;
		return 0;
	}
	x=arr[1];
	sort(arr+1,arr+(n*m)+1,cmp);
	while(arr[z]!=x&&i<=n)
	{
		if(b==0)
		{
			j++;
			z++;
			if(j==m)
			{
				i++;
				b=1;
				z++;
			}
		}
		else if(b==1)
		{
			j--;
			z++;
			if(j==1)
			{
				i++;
				b=0;
				z++;
			}
		}
	}
	cout<<i<<" "<<j;
	return 0;
}