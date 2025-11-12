#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],b[1000000],c[1000000];
int sum,x,y,z;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		x+=a[i];
		y+=b[i];
		z+=c[i];
	}
	cout<<(x+y+z)/3<<endl;
	return 0;
}
