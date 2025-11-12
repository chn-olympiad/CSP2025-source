#include <bits/stdc++.h>
using namespace std;
int a[1001],x,y,cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&x,&y);
	int ccc = x*y;
	for(int i=0;i<ccc;i++)
	{
		scanf("%d",&a[i]);
	}
	int kkey=a[0],kkkey;
	sort(a,a+ccc,greater<int>());
	for(int i=0;i<ccc;i++)
	{
		if(a[i]==kkey)kkkey = i;
	}
	int ans1=kkkey/y+1,ans2;
	printf("%d ",ans1);
	if((ans1%2)==1)
	{
		ans2=kkkey-x*(ans1-1)+1;
	}
	else
	{
		ans2=x-(kkkey-x*(ans1-1));
	}
	printf("%d",ans2);
	return 0;
}
