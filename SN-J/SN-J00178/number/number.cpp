#include<bits/stdc++.h> 
using namespace std;
string s;
int a[100005]={},o=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			
			a[o]=s[i]-'0';
			o++;
		}
	}
	sort(a+1,a+o,cmp);
	for(int i=1;i<o;i++)
	{
		cout<<a[i];
	}
	return 0;
}
