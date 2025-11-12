#include<bits/stdc++.h>
using namespace std;
int flag[1000005]={0};
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=1;
	for(int i=0;i<s.size();i++)//1000000
	{
		if(s[i]>='0' && s[i]<='9')
		{
			flag[j]=s[i]-'0';
			j++;
		}
	}
	j-=1;
	sort(flag+1,flag+j+1,cmp);
	for(int i=1;i<=j;i++)
	{
		cout<<flag[i];
	}
	return 0;
}//80·Ö---60·Ö 
