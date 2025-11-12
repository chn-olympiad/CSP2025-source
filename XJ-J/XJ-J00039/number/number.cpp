#include<bits/stdc++.h>
using namespace std;
int main()
{
	propen("number.in","r",stdin);
	propen("number.out","w",stdout);
	int i,j,k,a,sum=0,zd=0,s=0,szd=0;
	cin>>a;
	while(a!=0)
	{
		a=a%10;
		a=a/10%10;	
		sum++;
		if(a>szd)
		{
		szd=a;
		s=szd*s;
		szd=0;
		}
	} 
	cout<<s;
	
	return 0;
} 
