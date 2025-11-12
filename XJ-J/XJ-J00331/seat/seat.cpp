#include<bits/stdc++.h>
using namespace std;
long long int i,n,m,a[105],k;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
	 scanf("%lld",&a[i]);
	 if(i!=1&&a[i]>a[1])
	 k++;
	}
	k++;
	if(k%n==0)
	{
		cout<<k/n<<" ";
		if(k/n%2==1) cout<<n;
		else cout<<1;
	}
	else if(k/n%2==1)
		cout<<k/n+1<<" "<<n-k%n+1;
	else
		cout<<k/n+1<<" "<<k%n;
	return 0;
}
