#include<bits/stdc++.h>
using namespace std;
int n,m,a[107],x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int s=n*m;
	for(int i=1;i<=s;i++) scanf("%d",&a[i]);
	int k=a[1];
	sort(a+1,a+s+1);
	int l=1,r=s;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]==k)
		{
			y=mid;
			break;
		}
		else if(a[mid]<k) l=mid+1;
		else r=mid-1;
	}
	y=(s-y)+1;
	x=y%n;
	if(x==0) x=n;
	y=(y-x)/n+1;
	if(y%2==0) x=(n-x)+1;
	printf("%d %d\n",y,x);
	return 0;
}
