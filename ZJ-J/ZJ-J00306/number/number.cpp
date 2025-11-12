#include<bits/stdc++.h>
using namespace std;
long long a[1000005],k;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]<='9'&&s[i]>='0')
			a[++k]=s[i]-'0';
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++)
		cout<<a[i];
}