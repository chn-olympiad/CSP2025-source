#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
string s1[200005],s2[200005],sub1,sub2;
unordered_map<string,vector<string> >p;
int main()
{
	freopen("replace.in","r",stdin); 
	freopen("replace.out","w",stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL); 
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> s1[i] >> s2[i],p[s1[i]].push_back(s2[i]);
	while(q--)
	{
		string a,b;
		cin >> a >> b;
		if(a.size() != b.size())
		{
			cout << "0\n"; 
			continue;
		}
		int w = a.size(),ans = 0;
		for(int j = 0;j < w;j++)
		{
			if(j > 0 && a[j - 1] != b[j - 1]) break;
			for(int k = w - 1;k >= j;k--)
			{
				if(k < w - 1 && a[k + 1] != b[k + 1]) break;
				sub1 = a.substr(j,k - j + 1);
				sub2 = b.substr(j,k - j + 1);
				for(string x : p[sub1]) if(x == sub2) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
