#include <bits/stdc++.h>
using namespace std;
string s;
int a[1100];
int cnt=0,minn=-1;
int main() 
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<=len-1;i++)
	{
		if(s[i]>='a'&&s[i]<='z'||s[i]==' ') continue;
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=s[i]-'0';
			cnt++;
		}
	}
	for(int i=0;i<=cnt;i++)
	{
		
		cout<<a[i];
	}
	
	return 0;
}
