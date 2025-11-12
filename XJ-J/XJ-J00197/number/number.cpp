#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j,k,cnt=0,acnt=0;
	string s;
	cin>>s;
	cnt=s.size();
	for(i=0;i<=cnt-1;i++)
	{
		if(s[i]>='0' and s[i]<='9')
		{
			a[acnt]=s[i]-'0';
			acnt++;
		}
			
	}
	sort(a,a+acnt,cmp);
	for(i=0;i<=acnt-1;i++)
	{
		cout<<a[i];
	} 
	return 0;
} 
