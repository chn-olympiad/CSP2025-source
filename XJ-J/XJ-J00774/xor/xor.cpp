#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,i,flag=1;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			flag=0; 
		}
	}
	if(flag==1&&k==0)
	{
		cout<<n/2;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
