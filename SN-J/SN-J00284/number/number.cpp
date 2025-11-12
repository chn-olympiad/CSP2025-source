#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int num[20];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int x=s[i]-'0';
			num[x]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(num[i]--) cout<<i;
	}


	return 0;
}

