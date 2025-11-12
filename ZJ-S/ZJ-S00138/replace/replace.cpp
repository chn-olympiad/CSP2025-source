#include<bits/stdc++.h>
using namespace std;

string S_1[200005],S_2[200005];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> S_1[i] >> S_2[i];
	}
	for(int i = 1;i <= q;i++)
	{
		string T_1,T_2;
		cin >> T_1 >> T_2;
		long long cnt = 0;
		for(int i = 1;i <= n;i++)
		{
			int Slen = S_1[i].size() - 1,Tlen = T_1.size() - 1;// 0 ~ len - 1
			for(int j = 0;j <= Tlen - Slen;j++)
			{
				string TT = T_1;
				bool ok = 1;
				for(int k = 0;k <= Slen;k++)
				{
					if(TT[j + k] != S_1[i][k])
					{
						ok = 0;
						break;
					}
				}
				if(ok)
				{
					for(int k = 0;k <= Slen;k++)
					{
						TT[j + k] = S_2[i][k];
					}
					bool okk = 1;
					if(TT  == T_2)
					{
						cnt++;
					}
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
