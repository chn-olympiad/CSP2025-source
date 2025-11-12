/*
	SN-J00158 
	华紫陌
	西安辅轮中学 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int n;
int a[1000001];
int m=1;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(isdigit(s[i]))
		{
			a[m]=s[i]-'0';
			m++;
		}
	}
	sort(a+1,a+m,cmp);
	if(a[1]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<m;i++) cout<<a[i];
	return 0;
}
