#include<bits/stdc++.h>
using namespace std;
void fre()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
}
string s;
int cnt[10];
int main()
{
	fre();
	cin>>s;
	int len = s.size();
	for(int i = 0; i<len; i++)
	{
		if('0'<=s[i] && s[i]<='9')
		{
			cnt[s[i]-'0']++;
		}
	}
	bool flg = false;
	for(int i = 9; i>=0; i--)
	{
		if(cnt[i])
		{
			if(i>0)
			{
				flg = true;
				for(int j = 1; j<=cnt[i]; j++)
				{
					cout<<i;
				}
			}
			else
			{
				if(flg)
				{
					for(int j = 1; j<=cnt[i]; j++)
					{
						cout<<i;
					}
				}
				else
				{
					cout<<i;
				}
			}
		}
	}
	return 0;
}
