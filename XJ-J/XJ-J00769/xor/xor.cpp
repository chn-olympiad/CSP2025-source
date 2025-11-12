#include<bits/stdc++.h>
using namespace std;
long long int t,n,k,i,l1,l2,r1,r2,a[100005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(l1=1,l2=n-r1;l1<=r1,l2<=n;l1++,l2++)
	for(r1=1,r2=l2;r1<=n,r2<=n;r1++,r2++)
	{
		if(a[l1]+a[l1+1]+a[l1+2]+a[r1]==a[l2]+a[l2+1]+a[r2])
		t++;
		if(a[l1]+a[l1]+a[r1]==a[l2]+a[r2])
		t++;
		if(a[l1]+a[r1]==a[l2+r2])
		t++;
	}
	cout<<t+1;
}
