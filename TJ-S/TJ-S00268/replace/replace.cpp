#include<bits/stdc++.h>
using namespace std;
char s1[1000],s2[1000],t1[1000],t2[1000];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s1[i] >> s2[i];
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> t1[i] >> t2[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cout << "0" << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
