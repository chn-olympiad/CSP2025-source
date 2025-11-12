#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();++i)
	  if(isdigit(s[i]))
	    ++a[s[i]-48];
	for(long long i=9;i>=0;--i)
	  for(long long k=1;k<=a[i];++k)
	    cout<<i;
	return 0;
}
