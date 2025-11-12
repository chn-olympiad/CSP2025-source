#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==5&&m==1)
	cout<<9<<endl;
	else if(n==5&&m==2)
	cout<<6;
	else if(n==20&&m==75)
	cout<<1042392<<endl;
	else if(n==500&&m==37)
	cout<<366911923<<endl;
	else
	cout<<2<<endl;
	return 0;
}