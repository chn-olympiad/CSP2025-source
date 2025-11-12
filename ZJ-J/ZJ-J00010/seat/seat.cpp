#include<bits/stdc++.h>
using namespace std;
int n,m,t,k=1,a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	t=n*m;
	for(int i=1;i<=t;i++)
	  cin>>a[i];
	for(int i=2;i<=t;i++)
	if(a[i]>a[1]) k++;
	cout<<(k-1)/n+1<<" ";
	if(((k-1)/n+1)%2==1) cout<<(k-1)%n+1;
	else cout<<n-(k-1)%n;
}