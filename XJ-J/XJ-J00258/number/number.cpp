#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N+10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int ji=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9'){
			a[ji]=s[i]-'0';
			ji++;
		}
	}
	sort(a,a+ji);
	for(int i=ji-1;i>=0;i--)
		cout<<a[i];
	return 0;
}
