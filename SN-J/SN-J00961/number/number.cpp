#include<bits/stdc++.h>
using namespace std;
string s,n;
int a=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]>='0' and s[i]<='9')
		{
			n+=s[i];
		}
	}
	while(a==1)
	{
		a=0;
		for(int i=1;i<=n.size();i++)
		{
			if(n[i]-48>n[i-1]-48)
			{
				swap(n[i],n[i-1]);
				a=1;
			}
		}
		
	}
	cout<<n;
	return 0;
 } 
