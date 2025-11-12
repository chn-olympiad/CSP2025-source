#include<bits/stdc++.h>
using namespace std;
int a[1000050],topp=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("uumber.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	cin>>str;
	for(long long i=0;i<(int)str.size();i++)
	{
		if((char)str[i]<='9'&&(char)str[i]>='0')
		{
			a[topp]=(int)((char)str[i]-'0');
			topp++;
		}
	}
	sort(a+1,a+1+topp);
	for(long long i=1;i<topp;i++)
	{
		cout<<a[topp-i+1];
	}
	cout<<endl;
	return 0;
}
