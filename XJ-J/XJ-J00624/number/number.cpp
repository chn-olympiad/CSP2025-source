#include<bits/stdc++.h>
using namespace std;
long long int i,j,a[1000005],k=0,len;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	memset(a,0,sizeof(a));
	for(i=0;i<len;i++)
	if(s[i]>='0'&&s[i]<='9')
	{
		a[++k]=s[i]-'0';
		
	}
	sort(a+1,a+1+k);
	for(i=k;i>=1;i--)
	cout<<a[i];
	
	return 0;
 } 
