#include<bits/stdc++.h>
using namespace std;
#define ll long long
int tong[11];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			tong[s[i]-'0']++;
		}
	}
	if(tong[1]==0&&tong[2]==0&&tong[3]==0&&tong[4]==0&&tong[5]==0&&tong[6]==0&&tong[7]==0&&tong[8]==0&&tong[9]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=tong[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
