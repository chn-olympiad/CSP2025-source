#include<bits/stdc++.h>
using namespace std;
int n,m,i,a[101],s;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	   cin>>a[i];
	s=a[1];
	sort(a+1,a+n*m+1);
	for(i=1;i<=n*m;i++)
	   if(a[i]==s)
	     break;
	i=n*m-i+1;
	if((i+n-1)/n%2)
	  cout<<(i+n-1)/n<<" "<<(i-1)%n+1;
	else
	  cout<<(i+n-1)/n<<" "<<n-(i-1)%n;
	return 0;
}
