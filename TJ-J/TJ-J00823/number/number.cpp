#include<iostream>
using namespace std;
int a[10000],maxa[10000],maxxa;
int main()
{
	freopen(number.in,'r',stdin);
    freopen(number.out,'w',stdout);
    string s,b="";
    cin>>s;
    for(int i=0;i<s.length();i++)
        if(s[i]>='0'&&s[i]<='9')    b+=s[i];
	for(int i=0;i<b.length();i++)    a[i]=b[i]-'0';
	for(int i=0;i<b.length();i++)
	{
		maxxa=-100;
		for(int j=0;j<b.length();j++)
			if(a[j]>maxxa)	maxxa=a[j];
		for(int j=0;j<b.length();j++)
		{
			if(a[j]==maxxa)
			{
				a[j]=-1;
				break;
			}
		}
		maxa[i]=maxxa;
	}
	for(int i=0;i<b.length();i++)    cout<<maxa[i];
	return 0;
}
