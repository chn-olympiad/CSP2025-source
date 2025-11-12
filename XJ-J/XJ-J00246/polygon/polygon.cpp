#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a,b,c;
	cin>>n;
	cin>>a>>b>>c;
	if(a+b>c&&a-b<c)
	cout<<1;
	else
	cout<<0; 
	return 0;
 } 
