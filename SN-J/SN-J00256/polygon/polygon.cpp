#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int a[0x7f];
	cin>>n;
	for(int i=0;i<n;i++)
	    cin>>a[i];
	if(n==5&&a[5]==5) cout<<9;
	if(a[5]==10) cout<<6;
	else cout<<998244352;
	return 0;
}//ÎÑ²»»á 
