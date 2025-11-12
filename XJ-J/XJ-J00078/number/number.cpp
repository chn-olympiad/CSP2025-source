#include<bits/stdc++.h> 
using namespace std;
int b[1000005];
string s;
int cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int cnt=1;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			b[cnt++]=s[i]-'0';
		}
	}
	sort(b+1,b+cnt,cmp);
	for(int i=1;i<cnt;i++)
	{
		cout<<b[i];
	}
	return 0;
}
