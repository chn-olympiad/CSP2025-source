#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10;
int num[M];
int cntn=0;
int cmp(int a,int b)
{
	return a>b; 
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num[++cntn]=s[i]-48;
		}
	}
	sort(num+1,num+cntn+1,cmp);
	for(int i=1;i<=cntn;i++)
	{
		cout<<num[i];
	}
	cout<<"\n";
	return 0; 
}
