#include<bits/stdc++.h>
using namespace std;
int a[1005],k,n,m;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	k=a[1];
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==k)
			k=i;
	int k2=k%n,k1;
	if(k2==0)
		k1=k/n,k2=n;
	else
		k1=k/n+1;
	cout<<k1<<' ';
	if(k1%2==1)
		cout<<k2;
	else cout<<n-k2+1;
}