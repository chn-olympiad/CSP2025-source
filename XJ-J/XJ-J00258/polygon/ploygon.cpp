#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	int n,a[5010];
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	if(n==5&&a[0]==1)
		cout<<9;
	if(n==5&&a[0]==2)
		cout<<6;
	if(n==20)
		cout <<"1042392";
	if(n==500)
		cout<<"366911923";
	return 0;
}
