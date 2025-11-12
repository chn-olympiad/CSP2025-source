#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	int a[1000005],ans=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=s[i];
			if(s[i]=='0') ans++;
		}
	}
	sort(a,a+s.size());
	for(int i=s.size();;i--)
	{
		if(a[i]>=1&&a[i]<=9)
		{
			cout<<a[i];
		}
		if(a[i]==0) break;
	}
	for(int i=0;i<ans;i++)
	{
		cout<<"0";
	}
	return 0;
}
