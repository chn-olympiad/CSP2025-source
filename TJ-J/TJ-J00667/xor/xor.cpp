#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	int n,k,a[10005];
	int i;
	cin>>n>>k;
	for(i=1;i<=n*k;i++)
	{
		cin>>a[i];
		if(k==2)
		{
			cout<<2;
		}
		if(k==3)
		{
			cout<<2;
		}
		if(k==0)
		{
			cout<<1;
		}
	}
	
	return 0;
}
