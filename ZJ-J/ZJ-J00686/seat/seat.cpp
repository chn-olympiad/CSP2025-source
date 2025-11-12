#include<bits/stdc++.h>
using namespace std;
int n,m,me,x,y,z,temp;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>me;
	for(int i=1;i<n*m;i++)
	{
		cin>>x;
		if(x>me)	y++;
	}
	z=y/n+1;
	printf("%d ",z);
	temp=y%n+1;
	if(z%2==1)	printf("%d",temp);
	else		printf("%d",(n+1-temp));
	return 0;
} 