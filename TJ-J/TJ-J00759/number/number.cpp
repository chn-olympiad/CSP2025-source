#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000100],x=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') 
		{
			x++;
			a[x]+=int(s[i]-'0'); 
		} 
	}
	sort(a+1,a+x+1);
	for(int i=x;i>=1;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
}
