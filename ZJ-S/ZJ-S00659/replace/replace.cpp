#include <bits/stdc++.h>
using namespace std;
struct sdiv
{
	string x, y, z;
}L[2][200001];
int n, q;
string div(string str, int l, int r)
{
	string re;
	for(int i = l; i <= r; i++)
	{
		re = re+str[i];
	}
	return re;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	string str1, str2;
	for(int i = 1; i <= n; i++)
	{
		cin >> str1 >> str2;
		if(str1 == str2)
		{
			L[0][i].x = str1;
			L[0][i].y = "";
			L[0][i].z = "";
			L[1][i].x = str2;
			L[1][i].y = "";
			L[1][i].z = "";
			continue;
		}
		int pos1 = 0;
		while(str1[pos1] == str2[pos1])
		{
			L[0][i].x = L[0][i].x+str1[pos1];
			pos1++;
		}
		L[1][i].x = L[0][i].x;
		int pos2 = str1.length()-1;
		while(str1[pos2] == str2[pos2])
		{
			L[0][i].z = str1[pos2]+L[0][i].z;
			pos2--;
		}
		L[1][i].z = L[0][i].z;
		for(int j = pos1; j <= pos2; j++)
		{
			L[0][i].y = L[0][i].y + str1[j];
			L[1][i].y = L[1][i].y + str2[j];
		}
	}
	while(q--)
	{
		string s1x, s1y, s1z, s2x, s2y, s2z;
		cin >> str1 >> str2;
		if(str1.length() != str2.length())
		{
			cout << 0 << endl;
			continue;
		}
		int pos1 = 0;
		while(str1[pos1] == str2[pos1])
		{
			s1x = s1x+str1[pos1];
			pos1++;
		}
		s2x = s1x;
		int pos2 = str1.length()-1;
		while(str1[pos2] == str2[pos2])
		{
			s1z = str1[pos2]+s1z;
			pos2--;
		}
		s2z = s1z;
		for(int j = pos1; j <= pos2; j++)
		{
			s1y = s1y + str1[j];
			s2y = s2y + str2[j];
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if((s1y == L[0][i].y) && (s2y == L[1][i].y) && (s1x.length() >= L[0][i].x.length()) && (s1z.length() >= L[0][i].z.length()))
			{
				int ll = L[0][i].x.length(), lr = L[0][i].z.length(), s1 = s1x.length(), s2 = s1y.length();
				if((div(s1x, s1-ll, s1-1) == L[0][i].x) && (div(s1z, 0, lr-1) == L[0][i].z))
				{
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}
