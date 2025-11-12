#include<bits/stdc++.h>
using namespace std;
long long int a[15],i,j,ans,k;
string s;
int main()
{		freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
cin>>s;
for(i=0;i<s.size();i++)
if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
a[s[i]-'0']++;

for(i=9;i>=0;i--)
{
	if(a[i]!=0)
	for(j=1;j<=a[i];j++)
	cout<<i;
}
return 0;
}

