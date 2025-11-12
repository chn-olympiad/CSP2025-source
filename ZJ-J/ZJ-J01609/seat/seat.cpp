#include<bits/stdc++.h>
using namespace std;
int n,m,ans,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ans=1;
	cin>>n>>m;
	cin>>x;
	for(int i=2;i<=n*m;i++)
	{
		cin>>y;
		if(y>x) ans++;
	}
	if(ans%n==0)
	{
		if(ans/n%2==1) cout<<ans/n<<" "<<n<<endl;
		  else cout<<ans/n<<" "<<1<<endl;
	}
	if(ans%n>0)
	{
		if(ans/n%2==1) cout<<ans/n+1<<" "<<n-ans%n+1<<endl;
		  else cout<<ans/n+1<<" "<<ans%n<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}