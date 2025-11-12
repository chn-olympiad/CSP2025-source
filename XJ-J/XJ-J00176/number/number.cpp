#include<bits/stdc++.h>
using namespace std;
int i,k=0,m,n,a[10000004],b[10000005],j;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	j=s.size();
	for(i=0;i<j;i++)
		if(s[i]>='0'&&s[i]<='9')
		{
		a[k]=s[i]-'0';
		k++;
		}


   sort(a,a+k);

	for(i=k-1;i>=0;i--)
	printf("%d",a[i]);
	return 0;
 } 
