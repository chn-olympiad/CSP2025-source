#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000];
string mx;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		char c=i+'0';
		while(a[i]>0)
		{
			a[i]--;
			mx+=c;
		}
	}
	cout<<mx;
}
