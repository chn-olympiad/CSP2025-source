#include<bits/stdc++.h>
using namespace std;
long long int n,a[5005],s,sum;
int main()
{
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	for(int l=1;l<=n;l++)
	    for(int r=l+1;r<=n;r++)
	    {
		    for(int i=l;i<=r;i++)
		    s+=a[i];
		    if(s>2*a[r])
		    sum++;
	    }
	cout<<sum;
	return 0;
}
