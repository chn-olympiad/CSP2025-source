//SN-J01113 陈梓言 曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int j=0;
string s;
int main()
{
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	cin>>s;
	s=s+" ";
	for (int i=0;;i++)
	{
		if (s[i]==' ')
		{
			break;
		}
		if (s[i]<='9' && s[i]>='0')
		{
			j++;
			a[j]=s[i]-'0';
		}
	}
	sort(a,a+j+1);
	for (int i=j;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
