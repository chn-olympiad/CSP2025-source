#include<bits/stdc++.h>
using namespace std;
int a[1000005],cnt=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			cnt++;
			a[cnt-1]=(s[i]-'0');		
		}
	}
	sort(a,a+cnt,cmp);
	if(a[0]==0)
	{
		cout<<0; 
		return 0;
	}
	for(int i=0;i<cnt;i++)
	{
		cout<<a[i];
	}
	return 0;
}
