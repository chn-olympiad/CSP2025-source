#include<bits/stdc++.h>
using namespace std;
long long ans;
long long sum;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	if(n==1&&m==1)
	cout<<1<<' '<<1;
	long long a[105];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	long long len=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>=len)
		ans++;
	}
	if(ans%n==0){
		sum=ans/n;
	    cout<<ans/n<<' ';
	}else{
		sum=ans/n+1;
	    cout<<ans/n+1<<' ';
	}
	if(sum%2==0)
	{
		cout<<n-(ans-(sum-1)*n)+1;
	}
	else
	{
		cout<<ans-(sum-1)*n;
	}
	return 0;
}
