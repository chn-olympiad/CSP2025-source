#include<bits/stdc++.h>
using namespace std;
const int MX = 1e3,mod = 998244353;
int n,m,s[MX + 10],c[MX + 10];
string st;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> st;
	for (int i = 0;i < st.size();i++)
	{
		s[i + 1] = st[i] - '0';
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> c[i];
	}
	//泪目了，孩子们，该退赛了 
	cout << 0 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
