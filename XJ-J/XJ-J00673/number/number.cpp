#include<bits/stdc++.h>
using namespace std;
string a;
long long int b[15],k=0,i,j;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(i=0;i<=a.size();i++)
	 if(a[i]>='0'&&a[i]<='9')
	  b[a[i]-'0']++;
	  
	for(i=9;i>=0;i--)
	while(b[i]--)
	 cout<<i;
	return 0;
}
