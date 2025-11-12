#include<bits/stdc++.h>

using namespace std;

const int N = 1e2 + 10, LEN = 2e2 + 10;
const int base = 131, mod1 = 998244353, mod2 = 1e9 + 7;

int n, q, ans = 0;
char s1[N][LEN], s2[N][LEN];
char t1[LEN], t2[LEN];

int H1[N][LEN], H2[N][LEN], P1[LEN], P2[LEN];
int H3[N][LEN], H4[N][LEN];
int H5[LEN], H6[LEN];
int H7[LEN], H8[LEN];

void initHash(int i)
{
	int len = strlen(s1[i] + 1);
	
	for(int j = 1; j <= len; j ++)
	{
		H1[i][j] = (H1[i][j - 1] * base + (int)s1[i][j]) % mod1;
		H2[i][j] = (H2[i][j - 1] * base + (int)s1[i][j]) % mod2;
		H3[i][j] = (H3[i][j - 1] * base + (int)s2[i][j]) % mod1;
		H4[i][j] = (H4[i][j - 1] * base + (int)s2[i][j]) % mod2;
	}
}

void inithash()
{
	int len = strlen(t1 + 1);
	
	for(int j = 1; j <= len; j ++)
	{
		H5[j] = (H5[j - 1] * base + (int)t1[j]) % mod1;
		H6[j] = (H6[j - 1] * base + (int)t1[j]) % mod2;
		H7[j] = (H7[j - 1] * base + (int)t2[j]) % mod1;
		H8[j] = (H8[j - 1] * base + (int)t2[j]) % mod2;
	}
}

int hash1(int i, int l, int r)
{
	return (H1[i][r] - H1[i][l - 1] * P1[r - l + 1] % mod1 + mod1) % mod1;
}
int hash2(int i, int l, int r)
{
	return (H2[i][r] - H2[i][l - 1] * P2[r - l + 1] % mod2 + mod2) % mod2;
}
int hash3(int i, int l, int r)
{
	return (H3[i][r] - H3[i][l - 1] * P1[r - l + 1] % mod1 + mod1) % mod1;
}
int hash4(int i, int l, int r)
{
	return (H4[i][r] - H4[i][l - 1] * P2[r - l + 1] % mod2 + mod2) % mod2;
}
int hash5(int l, int r)
{
	if(l > r)
	{
		return -1;
	}
	return (H5[r] - H5[l - 1] * P1[r - l + 1] % mod1 + mod1) % mod1;
}
int hash6(int l, int r)
{
	if(l > r)
	{
		return -1;
	}
	return (H6[r] - H6[l - 1] * P2[r - l + 1] % mod2 + mod2) % mod2;
}
int hash7(int l, int r)
{
	if(l > r)
	{
		return -1;
	}
	return (H7[r] - H7[l - 1] * P1[r - l + 1] % mod1 + mod1) % mod1;
}
int hash8(int l, int r)
{
	if(l > r)
	{
		return -1;
	}
	return (H8[r] - H8[l - 1] * P2[r - l + 1] % mod2 + mod2) % mod2;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	P1[0] = P2[0] = 1;
	
	for(int i = 1; i < LEN; i ++)
	{
		P1[i] = P1[i - 1] * base % mod1;
		P2[i] = P2[i - 1] * base % mod2;
	}
	
	cin >> n >> q;
	
	if(n > 100)
	{
		while(q --)
		{
			puts("0");
		}
		
		return 0;
	}
	
	for(int i = 1; i <= n; i ++)
	{
		cin >> s1[i] + 1;
		cin >> s2[i] + 1;
		
		initHash(i);
	}
	
	while(q --)
	{
		ans = 0;
		
		cin >> t1 + 1 >> t2 + 1;
		
		int len1 = strlen(t1 + 1), len2 = strlen(t2 + 1);
		
		if(len1 != len2)
		{
			puts("0");
			continue;
		}
		
		inithash();
		
		for(int i = 1; i <= n; i ++)
		{
			int len = strlen(s1[i] + 1);
			
			for(int j = 1; j <= len1 - len + 1; j ++)
			{
				if(hash1(i, 1, len) == hash5(j, j + len - 1) && hash2(i, 1, len) == hash6(j, j + len - 1)
				&& hash3(i, 1, len) == hash7(j, j + len - 1) && hash4(i, 1, len) == hash8(j, j + len - 1)
				&& (hash5(1, j - 1) != -1 && hash5(1, j - 1) == hash7(1, j - 1) || hash5(1, j - 1) == -1)
				&& (hash5(j + len, len1) != -1 && hash5(j + len, len1) == hash7(j + len, len1) || hash5(j + len, len1) == -1))
				{
					ans ++;
				}
			}
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}