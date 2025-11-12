#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int u[1000005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	int sta=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			u[sta]=s[i]-'0';
			sta++;
		}
	}
	sort(u,u+sta,cmp);
	for(int i=0;i<sta;i++)
	{
		cout<<u[i];
	}
	return 0;
}
