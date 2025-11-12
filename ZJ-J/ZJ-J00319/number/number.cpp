#include<bits/stdc++.h>
using namespace std;
int a[10]={0,0,0,0,0,0,0,0,0,0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-48]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=a[i];j>0;j--)
			cout<<i;
	}/*
		That girl,but I let her get away.
		It's all my fault,cause ...
		Error!Error!I found you didn't pay!
		The time of listening music for free is ending.If you want to lisren more,please give me 20 point
	*/
	return 0;
}

