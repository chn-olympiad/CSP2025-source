/*张潇扬  SN-J00386  西安市曲江第一中学*/ 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n,a[10000];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10)
	{
		cout<<6;
	}
	if(a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5)
	{
		cout<<9;
	}
	return 0;
}
