#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;//输入字符串 
	int l=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[l]=s[i]-'0';
			l++;
		}
	}//提取数字 
	sort(a,a+l);
	if(a[l-1]==0)
	{
		cout<<0<<endl;
	}//特判 
	else
	{
		for(int i=l-1;i>=0;i--)
	    {
	    	cout<<a[i];
	    }
	    cout<<endl;
	}
	
	return 0;
}
