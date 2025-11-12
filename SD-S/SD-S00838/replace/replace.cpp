#include <bits/stdc++.h>
using namespace std;
string a[3];
string t[3][200005];
int s[3][200005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	bool flagb = 1;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j <= 1;j++)
		{
			cin >> t[j][i];
			bool vis = 0;
			for(auto k : t[j][i])
			{
				if(!flagb)break;
				if(k != 'a' && k != 'b')
				{
					flagb = 0;break;
				}
				if(k == 'a' && !vis)s[j][i][0]++;
				else if(k == 'a' && vis)s[j][i][1]++;
				else if(k == 'b')vis = 1;
			}
		}
	}
//	for(int i = 0;i < n;i++)
//	{
//		for(int j = 0;j <= 1;j++)
//		{
//			for(int k = 0;k <= 1;k++)
//			{
//				cout << s[j][i][k] << ",";
//			}
//			cout << " ";
//		}
//		cout << endl;
//	}
	for(int i = 0;i < q;i++)
	{
		for(int j = 0;j <= 1;j++)
		{
			cin >> t[j][200001];
			bool vis = 1;
			for(auto k : t[j][200001])
			{
				if(k != 'a' && k != 'b')
				{
					flagb = 0;break;
				}
				if(!flagb)break;
					if(k == 'a' && vis)
					{
						s[j][200001][0]++;
					}
					if(k == 'b')vis = 0;
					if(k == 'a' && !vis)
					{
						s[j][200001][1]++;
					}
			}
		}
		if(flagb)
		{
			int sum = 0;
			//cout << s[0][200001][0] << "," << s[0][200001][1] << " " << s[1][200001][0] << "," <<s[1][200001][1] << ":\n";
			for(int j = 0;j < n;j++)
			{
			//	cout << s[0][j][0] << "," << s[0][j][1] << " " << s[1][j][0] << "," <<s[1][j][1] << "\n";
				if(s[1][200001][1]-s[0][200001][1] == s[1][j][1]-s[0][j][1])
				{
					if(s[0][200001][0] >= s[0][j][0])
					{
						if(s[1][200001][1] >= s[1][j][1])
						{
							sum++;
						}
					}
				}
			}
			//cout << "\n";
			cout << sum << endl;
		}
	}
}
