#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],n=0;
string s;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		a[++n]=s[i]-'0';
	}
	sort(a+1,a+n+1,cmp);
	bool p=false;
	for(int i=1;i<=n;i++)
	{
		if(!p&&a[i]==0)
		continue;
		else
		{
			p=true;
			cout<<a[i];
		}
	}
	if(!p) cout<<0;
	cout<<endl;
	return 0;
}
