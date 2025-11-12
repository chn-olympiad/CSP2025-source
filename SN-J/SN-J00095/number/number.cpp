#include<bits/stdc++.h>
using namespace std;

char a[1000050];
int b[1000050];
long long i=1;
long long ch,js=1;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
	while(cin>>a[i])
	{
		if(a[i]<=57&&a[i]>=48)
		{
			b[js]=a[i]-48;
			js++;
			
		}
		i++;
	}
	
	for(int j=1;j<=js-1;j++)//
	{
		for(int c=1;c<=js-1;c++)//
		{
			if(b[c]>b[c-1])
			{
				ch=b[c];
				b[c]=b[c-1];
				b[c-1]=ch;
			}
		}
	}

	for(int j=0;j<js-1;j++)
	{
		cout<<b[j];
	}	
	return 0;
 } 
//GXEZ RP++!
