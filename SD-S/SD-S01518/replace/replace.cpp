#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,q;
pair<string,string> a[maxn];
int pos = 0;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	while(q--)
	{
		string t1,t2;
		cin >> t1 >> t2;
		int len1 = t1.size(),len2 = t2.size();
		for(int i = 1; i <= n; i++)
		{
			string s1 = a[i].first;
			string s2 = a[i].second;
			int l1 = s1.size(),l2 = s2.size();
			for(int x = 0; x < len1 - l1; x++)
			{ 
				if(t1[x] == s1[pos])
					pos++;
			}
		}
	}
	cout << pos << endl;
	fclose(0);
	return 0;
}
