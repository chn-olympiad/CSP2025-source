#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[1000005];
int pd(char s)
{
	if(s<='z'&&s>='a')
	{
		return 0;
	}
	return 1;
}
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000005];
	int cnt;
	cnt=1;
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(pd(s[i])==1)
		{
			a[cnt]=s[i]-'0';
			cnt++;
//			cout<<a[cnt-1]<<endl;
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt-1;i++)
	{
		cout<<a[i];
	}
	return 0;
} 
