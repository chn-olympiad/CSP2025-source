#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,he=0,i=0,aa=0;
	cin>>a;
	int b[a];
	for(i=0;i<a;i++)
	{
		cin>>b[i];
		he+=b[i];
	}
	for(i=0;i<a;i++)
	{
		if(he>=2*b[i])
		{
			aa=1;
		}
	}
	if(aa==1)
	{
		
	}
	cout<<a;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
} 
