#include <bits/stdc++.h>
using namespace std;
char s[1000001];
int a[1000001];
int main(void)
{
	freopen("number.in","r",stdin);
	int n,k,y;
	int i,j;
	
	for(i=1;i<=n;i++)
	{ 
		cin>>s[i];
	} 
	for(i=1;i<=n;i++)
	{
		if(s[i]==2)
			      
	}
	for(i=1;i<=n;i++)
	{
		k=i;
		for(j=1;j<=n;j++)	
		{
			if(a[k]>a[j])
				swap(a[k],a[j]);
		} 
	} 	
	for(i=1;i<=n;i++)
	{
		cout<<a[i];
	}
	freopen("number.out","w",stdout);
	return 0;
}
