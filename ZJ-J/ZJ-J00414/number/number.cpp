#include<bits/stdc++.h> 
using namespace std;
int len,k,a[1000005];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)	if(s[i]>='0'&&s[i]<='9') a[++k]=s[i]-'0';
	sort(a+1,a+1+k);
	for(int i=k;i>=1;i--) cout<<a[i];
	return 0;
}