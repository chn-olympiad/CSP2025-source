#include<bits/stdc++.h>
using namespace std;
int n[10];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len1=s.length();
	for(int i=0;i<len1;i++)
		if(s[i]>='0'&&s[i]<='9')n[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=n[i];j>=1;j--)cout<<i;
	return 0;
}
