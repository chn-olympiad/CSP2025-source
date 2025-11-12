#include<bits/stdc++.h>
using namespace std;
string s;
int n[1000000],j=0;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			n[j]=s[i]-'0';
			j++;
		}
	}
	sort(n,n+j,cmp);
	for(int i=0;i<j;i++)
		cout<<n[i];
	return 0;
}
