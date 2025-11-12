#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int idx=0,len=s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			idx++;
			a[idx]=int(s[i]-'0');
		}
	}
	sort(a+1,a+1+idx,cmp);
	if(a[1]==0)
	{
		cout<<0<<endl;
	}
	else
	{
		for(int i=1;i<=idx;i++)
		{
			cout<<a[i];
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
