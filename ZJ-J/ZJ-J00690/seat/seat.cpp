#include<bits/stdc++.h>
using namespace std;
int n,m,a[150],cnt,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>=a[1]) cnt++;
	}
	c=(cnt+n-1)/n;
	int s=cnt%n;
	if(s==0) s=m;
	if(c%2) r=s;
	else r=m-s+1;
	cout<<c<<' '<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
