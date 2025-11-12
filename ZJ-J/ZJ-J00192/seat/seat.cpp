#include<bits/stdc++.h>
using namespace std;
int n,m,s,sum=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=2;i<=n*m;i++)
	{
		int x;
		cin>>x;
		if(x>s) sum++;
	}
	int c=ceil(sum*1.0/n),r=(sum-1)%n+1;
	if(c%2==0) r=n-r+1;
	cout<<c<<" "<<r;
	return 0;
}

