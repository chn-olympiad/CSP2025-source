#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
int l;
int main()
{
	freopen("number.in","R",stdin);
	freopen("number.out","W",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{

	   if(s[i]>='0'&&s[i]<='9')
	   {
	   	l=s[i]-48;
        //cout<<l;
       a[l]++;

	   }
	}
	for(int i=9;i>=0;i--)
	{
     for(int j=0;j<a[i];j++)
     {
       cout<<i;
	 }
	}
	return 0;
}