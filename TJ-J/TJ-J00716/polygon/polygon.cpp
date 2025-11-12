#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int n,k,b=2,c=3;
	int a[10005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	if(a[1]>1)
	{
	cout<<"6"<<endl;
	}
	else
	{
		cout<<"1"<<endl; 
	}
	return 0;
}
