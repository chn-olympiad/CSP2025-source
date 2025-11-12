#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
const int N = 100010, M = 110;
int t, n;
int a[N], b[N], c[N], lmt;
long long p[M][M][M];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t --)
	{
		cin >> n;
		lmt = n/2;
		memset(p, 0, sizeof(p));
		
		for(int i = 1; i <= n; i ++ )
			cin >> a[i] >> b[i] >> c[i];
		 
		for(int i = 1; i <= n; i ++ )
		for(int j = lmt; j >= 0; j -- )
		for(int l = lmt; l >= 0; l -- )
		for(int k = lmt; k >= 0; k -- )
			{
				if(j + l + k > n) continue;
				if(j-1 >= 0) p[j][l][k] = max(p[j][l][k], p[j-1][l][k] + a[i]);
				if(l-1 >= 0) p[j][l][k] = max(p[j][l][k], p[j][l-1][k] + b[i]);
				if(k-1 >= 0) p[j][l][k] = max(p[j][l][k], p[j][l][k-1] + c[i]);
			}	
		
		
		/*cout << "以下是图";
		for(int i = 1; i <= n; i ++ )
		{
		for(int j = lmt; j >= 0; j -- )
		for(int l = lmt; l >= 0; l -- )
		for(int k = lmt; k >= 0; k -- )
		{
			if(j + l + j > n) continue;
			cout << p[i][j][l][k] << ' ';
		}	
		cout << endl;
		}
		cout << endl <<"到此结束" << endl;*/
		
		long long ans = 0;
		for(int j = lmt; j >= 0; j -- )
		for(int l = lmt; l >= 0; l -- )
		for(int k = lmt; k >= 0; k -- )
		{
			if(j + l + k != n) continue;
			ans = max(ans, p[j][l][k]);
		}
		cout << ans << endl;
	}
 return 0;//Ren5Jie4Di4Ling5%
}

