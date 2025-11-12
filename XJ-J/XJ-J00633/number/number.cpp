#include<bits/stdc++.h>
using namespace std;
long long int a[10005],i,k,b[10005],n,m=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	 cin>>a;
	 for(i=0;a[i]!='\0';i++)
	 if(a[i]>='1'&&a[i]<='9')
	 {
	 	b[i]=a[i];
	 }
	 for(i=0;b[i]!='\0';i++)
	 {
	 	n++;
	 }
     for(i=0;i<=n;i++)
	 cout<<b[i];
	 return 0;
} 
