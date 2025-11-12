#include<iostream>
#include<algorithm>
using namespace std;
int b[100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> s;
	int n = s.size();
	for(int i = 0;i < n;i++)
	{
		if('0' <= s[i] && s[i] <= '9') b[s[i] - '0']++;
	}
	for(int i = 9;i >= 0;i--)
	{
		for(int j = 1;j <= b[i];j++) cout << i;
	}
	cout << "\n"; 
	return 0;  
}  
