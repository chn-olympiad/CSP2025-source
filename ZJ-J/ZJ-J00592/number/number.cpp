#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int a[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int i,sum=0;
	cin>>s;
	for(i=0;i<s.size();i++)
		if('0'<=s[i]&&s[i]<='9')
			a[++sum]=s[i]-'0';
	sort(a+1,a+1+sum,cmp);
	for(i=1;i<=sum;i++)
		cout<<a[i];
	return 0;
}
