#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,ans;
int a[1005];
int b[1005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int z=n*m;
	for(int i = 1;i<=z;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+z+1);
	for(int i = 1;i<=z;i++)
	{
		b[i]==a[i];
		while(b[i]==a[1])
		{
			ans++;
		}
		cout<<ans/c<<" "<<ans%r;
	}
	return 0;
}
