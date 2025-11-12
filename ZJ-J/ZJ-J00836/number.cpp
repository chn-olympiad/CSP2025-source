#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b[10]={};
	string c="";
	int j=0;
	int l=a.size();
	for(int i=0;i<=l;i++)
	{
		if(48<=int(a[j])<=58)
			{
				b[int(a[j])-48]+=1;
			}
		j=j+1;
	}
	for(int i=9;i>=0;i--)
	{
		for(int q=0;q<b[i];q++)
		{
			c=c+char(i+48);
		}
	}
	cout<<c;
	return 0;
}