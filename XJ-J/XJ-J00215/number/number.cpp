#include<bits/stdc++.h>
using namespace std;
long long int a[105],i;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<=s.size();i++)
	if(s[i]>='0'&&s[i]<='9')
	a[s[i]-'0']++;
	for(i=9;i>=0;i--)
	{
	while(a[i]>0)
{
	printf("%d",i);
	a[i]--;
}
}
	return 0;
}
 
