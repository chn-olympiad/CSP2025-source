#include<bits/stdc++.h>
using namespace std;
int n,m,sum=1;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
			sum++;
	}
	if(sum%n==0)
		cout<<sum/n<<" ";
	else
		cout<<sum/n+1<<" ";
	if(sum%(n*2)>n)
		cout<<2*n-sum%(n*2)+1<<" ";
	else if(sum%(n*2)<=n)
		cout<<sum%(2*n)<<" ";
	return 0;
}
