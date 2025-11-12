#include <bits/stdc++.h>

using namespace std;

int n,m;

string s1[1000000],s2[1000000];


int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> m;
	
	for(int i = 1;i <= n;i++)
	{
		cin >> s1[i] >> s2[i];
	}
	string s3,s4;
	cin >> s3 >> s4;
	if(m == 1)
	{
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			int flag = 0;
			for(int j = 0;j < s3.size() - s1[i].size();j++)
			{
				
				for(int o = j;o <= j + s1[i].size();o++)
				{
					if(s3[o] != s1[i][o - j] or s4[o] != s2[i][o - j])
					{
						flag = 1;
						break;
					}
				}
			}
			
			if(flag == 0)ans++;
		}
		
		cout << ans;
	}
	else
	{
		
		for(int i = 1;i <= m;i++)cout << 0 << endl;
	}
	


	
	
	
	
	return 0;
} 
