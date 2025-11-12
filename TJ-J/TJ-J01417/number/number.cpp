#include<bits/stdc++.h>
using namespace std ;
string s,a;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
    //freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]<='9'&&s[i]>='0')a+=int(s[i]);
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=0)cout<<a[i];
	}
	return 0;
}
