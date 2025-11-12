#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a[110],l;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1; i<=n*m; i++)cin>>a[i];
	l=a[1];
	sort(a+1,a+1+n*m);
	for(i=1; i<=n*m; i++)if(a[i]==l)j=n*m-i+1;
	i=j/n+1;
	j=j%n;
	if(j==0)j=n,i--;
	cout<<i<<' ';
	if(i%2==1)cout<<j;
	else cout<<n-j+1;
}
