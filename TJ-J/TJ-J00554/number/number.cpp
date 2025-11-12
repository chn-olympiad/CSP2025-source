#include<bits/stdc++.h> 

using namespace std;
string s,a;
int b[100001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0' or s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9')
		{
			a+=s[i];
		}
	}
	for(int i=0;i<a.size();i++)
	{
		b[i]=a[i]-'0';
	}
	int n=a.size();
	sort(b+1,b+n+1);
	for(int i=a.size();i>0;i--)
	{
		cout<<b[i];
	}
	return 0;
}
