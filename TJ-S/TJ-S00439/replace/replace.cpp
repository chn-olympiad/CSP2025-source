#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int main(){
	int n,q,k,c,ans=0;
	cin>>n>>q;
	string a[n+1][3],t[q+1][3];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[i][1]>>t[i][2];
	}
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(t[i][1]==a[j][i]&&t[i][2]==a[i][2])
			{
				ans++;
			}
		} 
	}
	cout<<ans<<endl;
	cout<<"0"<<endl;
	return 0;
} 
