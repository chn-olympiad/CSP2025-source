#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	int len=s.size();
	sort(s.begin(),s.end());
	for(int i=len-1;i>=0;i--)
	{
		if(s[i]>='0'&&s[i]<='9')cout<<s[i];
	}
	cout<<"\n";
	return 0;
}
