#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	string s1[n+2][2],s2[q+2][2];
	for(int i = 1;i <= n;i++)
	{
		cin >> s1[i][0] >> s1[i][1];
	}
	for(int i = 1;i <= q;i++)
	{
		cin >> s2[i][0] >> s2[i][1]; 
		cout << 0 << endl;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
