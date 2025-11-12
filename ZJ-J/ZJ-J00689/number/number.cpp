#include<bits/stdc++.h>
using namespace std;
int m,a[1001000];
string s;
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			int x=s[i]-'0';
			a[++m]=x;
		}
	}
	sort(a+1,a+m+1,cmp);
	if(a[1]==0) cout<<"0";
	else 
		for(int i=1;i<=m;i++) cout<<a[i];
	return 0;
}
