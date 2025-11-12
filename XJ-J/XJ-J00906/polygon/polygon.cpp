#include<bits/stdc++.h>
using namespace std;
long long a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==3)
	{
		int k=max(max(a[1],a[2]),a[3]); 
		int cnt=a[1]+a[2]+a[3];
		if(cnt>k*2)
			cout<<1;
			return 0;
		cout<<0;
	}
	if(n==4)
	{
		int ans=0; 
	    int k=max(max(a[1],a[2]),max(a[3],a[4]));
		int cnt1=a[1]+a[2]+a[3]+a[4];
		int cnt2=a[1]+a[2]+a[3];
		int cnt3=a[1]+a[2]+a[4];
		int cnt4=a[2]+a[3]+a[4];
		if(cnt1>k*2)
			ans++;
		if(cnt2>max(max(a[1],a[2]),a[3])*2)
			ans++;
		if(cnt3>max(max(a[1],a[2]),a[4])*2)
			ans++;
		if(cnt4>max(max(a[4],a[2]),a[3])*2)
			ans++;
		cout<<ans;
	}

}
