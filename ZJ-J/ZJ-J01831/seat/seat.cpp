#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],dai,num,lie;
bool cmd(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	dai=a[1];
	sort(a+1,a+n*m+1,cmd);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==dai)
		{
			num=i;
			break;
		}
	}
	lie=num/n;
	if(lie*n==num) cout<<lie<<" "<<n;
	else if(lie%2==0) cout<<lie+1<<" "<<num-lie*n;
	else cout<<lie+1<<" "<<n-(num-lie*n)+1;
	return 0;
}