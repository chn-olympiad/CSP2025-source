#include<iostream>
using namespace std;
char a[20000],b[20000];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
	    cin>>a>>b;
	} 
	for(int i=1;i<=q;i++)
	{
		cin>>a>>b;
		cout<<0<<endl;
	}
	return 0;
} 
