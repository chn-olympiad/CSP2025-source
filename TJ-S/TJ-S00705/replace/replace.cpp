#include <bits/stdc++.h>
using namespace std;
const int N = 200002;
int n, q;
string s1[N], s2[N], t1[N], t2[N];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >>	q;
	for(int i=1; i<=n; i++) cin >> s1[i] >> s2[i];
	for(int i=1; i<=q; i++) cin >> t1[i] >> t2[i];
	for(int i=1; i<=q; i++)
	{
		int cnt=0;
		for(int j=1; j<=n; j++)
		{
			for(int k=1; k<=(t1[i].size()-s1[j].size()+1); k++)
			{
				string tmp=t1[i];
				tmp.replace(k-1, s1[j].size(), s1[j]);
				if(tmp == t2[i]) cnt++;
			}
		}
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
