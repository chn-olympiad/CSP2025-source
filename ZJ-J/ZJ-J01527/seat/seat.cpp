#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[1000005];
bool cmp(int x,int y) {return x>y;}


signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int a1=a[1],id=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++) 
	{
		if(a[i]==a1)
		{
			id=i;
			break;
		}
	} 	
	int c=ceil(id*1.0/n*1.0),r=0;
	if(c%2==1)
	{
		r=id%n;
		if(r==0) r=n;
	}
	else
	{
		if(id%n==0) r=1;
		else r=n-id%n+1;
	}
    
	cout<<c<<" "<<r;
	return 0;

}

