#include<bits/stdc++.h>
using namespace std;
string s;
long long int len,a[1000005],i,j,k;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(i=0;i<len;i++)
	if(s[i]>='0'&&s[i]<='9')
	a[++k]=s[i]-'0';
	
	sort(a+1,a+1+k,greater<long long int>());
	for(i=1;i<=k;i++)
	printf("%lld",a[i]);
	return 0;
}
