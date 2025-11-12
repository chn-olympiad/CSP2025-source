#include <iostream>
#include <algorithm>
using namespace std;
string s="a",s1;
int a[10000005]={};
bool cmp(int a,int b)
{
	return a>b;
 } 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	s+=s1;
	for(int i=1;i<=s.size();i++)
	{
		a[i]=s[i]-'0';
		if(a[i]>=10)
		{
			a[i]=-1;
		}
	}
	sort(a+1,a+s.size()+1,cmp);
	for(int i=1;i<=s.size();i++)
	{
		if(a[i]<0) return 0;
		cout<<a[i];
	}
	return 0;
 } 
