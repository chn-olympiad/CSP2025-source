#include<iostream>
#include<cstring>
using namespace std;
string a[1005],b[1005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int q,x,i,j,l;
	cin>>q>>x;
	for(i=1;i<=q;i++)
	{
		cin>>a[i];
		l=a[i].size();
	}
	for(i=1;i<=x;i++)
	{
		cin>>b[i];
	}
	for(i=1;i<=x;i++)
	{
		cout<<l<<endl<<"0";
	}
	return 0;	
} 
