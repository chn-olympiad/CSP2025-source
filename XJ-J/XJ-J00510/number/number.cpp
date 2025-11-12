#include<bits/stdc++.h>
using namespace std;
long long int i,len,k,a[1000006];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(i=0;i<len;i++)
	if(s[i]>='0'&&s[i]<='9')
	{
		a[++k]=s[i]-'0';
	}
	sort(a,a+k+1,greater<int>());
	for(i=0;i<k;i++)
	cout<<a[i];
	return 0;
 } 
