#include<bits/stdc++.h>
using namespace std;
int n,m,a[225],r,cnt;
int ans[15][15],ansx,ansy;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
			for(int j=1;j<=n;j++)
			cnt++,ans[j][i]=a[cnt];
		else if(i%2==0)
			for(int j=n;j>=1;j--)
			cnt++,ans[j][i]=a[cnt];
	}
	for(int j=1;j<=n;j++)
		for(int i=1;i<=m;i++)
			if(ans[j][i]==r)
			ansx=i,ansy=j;	
	cout<<ansx<<" "<<ansy;
	return 0;
}
/*
3 4
99 92 91 86
98 93 90 87
97 94 89 88
*/
