#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+3;
const int M = 5e6+3; 

int n,q;
int locz[M],locf[M];
string s1,s2;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1; i<= n; i++)
	{
		cin >> s1 >> s2;
		int l1 = s1.size(),l2 = s2.size();
		int a = 0, b = 0;
		for (int i = 0; i< l1; i++) if (s1[i] == 'b') a = i;
		for (int i = 0; i< l2; i++) if (s2[i] == 'b') b = i;
		if ((a-b) < 0) locf[abs(a-b)]++;
		else locz[abs(a-b)]++;
	}
	while(q--)
	{
		cin >> s1 >> s2;
		int l1 = s1.size(),l2 = s2.size();
		if (l1 != l2) cout << 0 << endl;
		else 
		{
			int a = 0, b = 0;
			for (int i = 0; i< l1; i++) if (s1[i] == 'b') a = i;
			for (int i = 0; i< l2; i++) if (s2[i] == 'b') b = i;
			if ((a-b) < 0) 	cout << locf[abs(a-b)] << endl;
			else cout << locz[abs(a-b)] << endl;	
		}
	}
	
	
	return 0;
}
