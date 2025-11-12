#include <iostream>
#include <cstdio>
using namespace std;
int cnt[10];
string s; 
int main()//#Shang4Shan3Ruo6Shui4
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=s.size()-1;i>=0;i--)
	{
		if('0' <= s[i] && s[i] <= '9')
		{
			cnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<cnt[i];j++)
		{
			cout << i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
