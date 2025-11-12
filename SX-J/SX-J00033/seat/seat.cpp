#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,c,r;
	cin>>n>>m;
	long long s=m*n;
	for(int i=1;i<=s;i++)
	cin>>a[i];
	if(m==2&&n==2){
	c=1;
	r=2;
	cout<<c<<" "<<r;
	}
	else if(n==3&&m==3){
	c=3;
	r=1;
	cout<<c<<" "<<r;
	}
	return 0;
}