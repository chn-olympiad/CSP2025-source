#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int r,c;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i) cin>>a[i]; 
	int R=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;++i)
	if(a[i]==R){R=i;break;}
	r=ceil(1.0*R/n);
	c=R%n;
	if((r&1)&&c==0) c=n;
	else if(!(r&1))c=n-R%n+1;
	cout<<r<<" "<<c<<"\n";
	return 0;
}//100pts
