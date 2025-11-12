#include<bits/stdc++.h>
using namespace std;
char s[100005],b[100005];
int i,j,n,r;
int main()
{
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout);
    cin>>s;
    n=strlen(s);
	for(i=0;i<=n;i++)
	if(s[i]>='0'&&s[i]<='9')
	b[i]=s[i];
	sort(b,b+n,greater<char>());
	for(i=0;i<=n;i++)
	cout<<b[i];
	return 0;
} 
