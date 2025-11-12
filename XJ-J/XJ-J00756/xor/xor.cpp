#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,i,j,k,x=0,y=0,ans=0,flag;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			ans++; 
		}
		else
		{
			ans=0;
		}
	 } 
	 if(ans==n)
	 {
	 	cout<<1;
	 }
	 else
	 {
	 	cout<<2;
	 }
	return 0;
}
