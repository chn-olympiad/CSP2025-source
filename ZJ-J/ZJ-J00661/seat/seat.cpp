#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t,ans1,ans2;
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==x)
		{
			t=i;
			break;
		}
	int z1=t/(2*n);
	int z2=t%(2*n);
	if(z2>n)
		ans1=2*z1+2,ans2=n*2-z2+1;
	if(z2<=n&&z2!=0)
		ans1=2*z1+1,ans2=z2;
	if(z2==0)
		ans1=2*z1,ans2=1;
	cout<<ans1<<" "<<ans2<<"\n";	
	return 0;
}