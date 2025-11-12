#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,b;
	long long nm,l,f=0;
	
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>nm;
		if(f==0)l=nm;
		f=1;
	}
	cout<<l;
	return 0;
 } 
