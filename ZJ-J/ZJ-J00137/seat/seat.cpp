#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m,ans=1,a,b,x,y;
string s;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=2;i<=n*m;i++)
	{
		cin>>b;
		if(a<b)
			ans++;
	}
	if(ans%n)
		x=ans/n+1;
	else
		x=ans/n;
	if(x%2)
	{
		if(ans%n==0)
			y=n;
		else
			y=ans%n;
	}
	else
	{
		if(ans%n==0)
			y=1;
		else
			y=n-(ans%n)+1;
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
