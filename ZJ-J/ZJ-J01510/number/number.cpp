#include<bits/stdc++.h>
using namespace std;
int a[10],siz;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s; siz=s.size();
	for(int i=0;i<siz;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(a[i]--) putchar(i+'0');
	return 0;
}
