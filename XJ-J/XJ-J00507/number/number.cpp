#include<bits/stdc++.h>
using namespace std;
char a[100005],c[100005];
long long int i,n=0;
int main()
{
	freopen("number.in","w",stdin);
    freopen("number.out","r",stdout);
	cin>>c;
	for(i=0;i<=strlen(c);i++)
	{
	  if(c[i]<='9'&&c[i]>='0')
	  {
	  a[n]=c[i];
	  n++;
}
	}
	sort(a,a+n);
	for(i=strlen(a);i>=0;i--)
	cout<<a[i];
	return 0;
} 
