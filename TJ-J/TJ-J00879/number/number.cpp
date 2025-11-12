#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
	string s,ans="";
	cin>>s;
	int a[11]={0,0,0,0,0,0,0,0,0,0,0},num=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num++;
			a[s[i]-'0']++;
		}
	}
	if(a[0]==num) cout<0;
	else for(int i=9;i>=0;i--) for(int j=1;j<=a[i];j++) cout<<i;
}
