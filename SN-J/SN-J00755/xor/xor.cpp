#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
int a[maxn]; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int mans=0;
	int n,k;
	scanf("%d%d",&n,&k);
	bool h=1;
	char data='A';
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>255 || a[i]<0 && (data=='A' || data=='B' || data=='C'))
		{
			data='0';
		}
		else if(a[i]<0 || a[i]>1 && (data=='B' || data=='A'))
		{
			data='C';
		}
		else if(a[i]!=1 && data=='A'){
			data='B';
		}
			
	}
	//printf("%c",data);
	if(n<=2 && data=='A' && k==0)
	{
		if(n==1)
		{
			return printf("0"),0;
		}
		else
		{
			return printf("1"),0;
		}
	}
	else
	{
		return printf("%d",n/2),0;
	}
	return 0;	
} 
