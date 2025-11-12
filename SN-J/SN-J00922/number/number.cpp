//SN-J00922
#include<bits/stdc++.h>
using namespace std;
string s;
int a[100001];
//vector<int> a;
int it=0;
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
		if(s[i]-'0'>=0 && s[i]-'0'<=9)
		{
			
			a[++it]=s[i]-'0';
		}
	}
	sort(a,a+1+it);
	if(a[it]==0) cout<<0;
	else
	{
		for(int i=it;i>=1;i--)
		{
			cout<<a[i];
		}
	}
	return 0;
}
