#include<bits/stdc++.h>//polygon
using namespace std;
long long int n,a[5005],b[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long int i,j,z,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
	  cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	  b[i]=b[i-1]+a[i];
	
	for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
	    for(z=3;z<=n;z++)
	    {
	  	  if(j-i+1>=z&&b[j]-b[i-1]>a[j]*2)
	  	    ans++;
	    }
	cout<<ans;
	return 0;
	
}
