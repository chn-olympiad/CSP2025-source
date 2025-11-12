#include<bits/stdc++.h>
using namespace std;
string s;
int k,a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	if(s[i]>='0' && s[i]<='9') a[++k]=s[i]-'0';
	sort(a+1,a+k+1);
	for(int i=k;i>0;i--)
	  cout<<a[i];
}