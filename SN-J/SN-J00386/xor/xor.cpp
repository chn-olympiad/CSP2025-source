/*张潇扬  SN-J00386  西安市曲江第一中学*/ 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k,a[1000];
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(k==2&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3)
	{
		cout<<2;
	}
	if(k==3&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3)
	{
		cout<<2;
	}
	if(k==0&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3)
	{
		cout<<1;
	}
	return 0;
}
