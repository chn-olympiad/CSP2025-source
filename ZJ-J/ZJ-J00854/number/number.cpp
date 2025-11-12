#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
string s;
int a[N],x;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);   cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[x]=s[i]-'0';
			x++;
		}
		
	}
	sort(a,a+x,cmp);
	for(int i=0;i<x;i++)
	{
		cout<<a[i];
	}
	return 0;
} 
