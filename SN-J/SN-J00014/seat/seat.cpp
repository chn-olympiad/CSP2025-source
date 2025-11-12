#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int cnt=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1]) cnt++;
	}
	int ans1=0,ans2=0;
	ans1=((cnt-1)/n)+1;
	if(ans1%2==0) ans2=n-(cnt-1)%n;
	else ans2=(cnt-1)%n+1;
	cout<<ans1<<' '<<ans2;
	return 0;
}
