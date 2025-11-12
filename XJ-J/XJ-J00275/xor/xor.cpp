#include<bits/stdc++.h>
using namespace std;
long long int a[100000005],l,r,n,i,j,flag,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)
	 {
	 	cin>>a[i];
	 	if(a[i]!=1)
	 	flag=1;
	 }
	 if(flag==0&&k==0)
	 cout<<n/2;
	 return 0;
} 
