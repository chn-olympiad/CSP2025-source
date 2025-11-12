#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll i,a[20]={0},f=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	for(i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	}
	for(i=9;i>=1;i--)
	{
		while(a[i]--)
		{
			cout<<i;
			f=1;
		}
	}
	if(f==0)cout<<0;
	else
	{
		while(a[0]--)
		{
			cout<<0;
		}
	}
	cout<<"\n";
	return 0;
}
/*

*/
