#include<bits/stdc++.h>
using namespace std;
string s,s1;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++)
	{
		if('0' <= s[i] && s[i] <= '9') a[s[i]-'0']++;
	}
	for(int i = 9;i >= 1;i--)
	{
		for(int j = 0;j < a[i];j++) s1.push_back(i+'0');
	}
	if(s1.empty())
	{
		cout << 0;
		return 0;
	}
	for(int i = 0;i < a[0];i++) s1.push_back('0');
	cout << s1;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
