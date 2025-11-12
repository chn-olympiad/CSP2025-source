//西安高新二中  杨嘉乐  SN-J00609
#include<bits/stdc++.h>
using namespace std;
int n,ans,num,maxx,maxx2;
int a[50005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		num=num+a[i];
		maxx=max(a[i],maxx);
	}
	maxx2=maxx*2;
	if(maxx2<num&&n==3)
	{
		cout<<1;
	}
	return 0;
}
