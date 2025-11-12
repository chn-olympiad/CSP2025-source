#include<bits/stdc++.h>
using namespace std;
int a[104],n,m,b,c;
int i,j,x=1,y=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	b=a[1];
	for(i=2;i<=n*m;i++)
		cin>>a[i];
	for(i=1;i<=n*m;i++)
		for(j=2;j<=n*m;j++)
			if(a[j-1]<a[j])
				swap(a[j-1],a[j]);
	for(i=1;i<=n*m;i++)
		if(a[i]==b)
			c=i;
	for(i=2;i<=c;i++)
	{
		if(y==n&&x%2==1)
			x++;
		else if(y==1&&x%2==0)
			x++;
		else if(x%2==1)
			y++;
		else
			y--;
	}
	cout<<x<<' '<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
