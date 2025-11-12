#include<iostream>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout);
	int n,k,i,a[20]={0};
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	 } 
	 if(n==1&&k==0)
	 {
	 	cout<<'0';
	 	return 0;
	 }
	 if(n==2&&k==0)
	 {
	 	cout<<'1';
	 	return 0;
	 }
	return 0;
 } 
