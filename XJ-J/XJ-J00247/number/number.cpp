#include<bits/stdc++.h>
using namespace std;
long long i,a[1000005],s,k,l;
char b[1000005];
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","out",stdout);
	scanf("%s",b);
	for(i=9;i>=0;i--)
	for(l=0;b[l]!='\0';l++)
	{
		if(b[l]-'0'==i)
		a[++k]=i;
	}
	for(i=1;i<=k;i++)
	cout<<a[i];
	return 0;
} 
