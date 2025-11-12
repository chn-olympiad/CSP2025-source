#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	preopen("number.in","r",stdin);
	preopen("number.out","w",stdout);
	string s;
	cin>>s;
	char a[1001000];
	int n=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[n]=s[i];
			n++;
		}
	 }
	 sort(a,a+n,cmp);
	 cout<<a;
	 return 0;
}
