#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	int a[11][11];
	int b[11];
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=b[i];
		}
	}
	
	return 0;
}
