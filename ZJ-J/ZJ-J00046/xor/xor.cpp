#include <iostream>
#include <cstdio>

#define sigma_subA sum1 == n
#define sigma_subB sum1 + sum0 == n

using namespace std;

const int N = 5e5 + 5;

int a[N], pre[N], sq[N];
int n, k, cnt, tot = 1, sum1, sum0;

inline void subB();
inline void subA();

int main() 
{
	freopen("xor6.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		pre[i] = pre[i - 1] ^ a[i];
		if(a[i] == k)
			sq[++tot] = i, cnt++;
		sum0 += (a[i] == 0), sum1 += (a[i] == 1);
	}
	
	sq[tot + 1] = n + 1;
	
	if(sigma_subA)
	{
		subA();
	}
	
	else if (sigma_subB)
	{
		subB();
	}
		
	else
	{
		for (int i = 1; i <= tot; i++)
		{
			int s = sq[i];
			for (int j = sq[i] + 1; j < sq[i + 1]; j++)
			{
				for (int l = s; l < j; l++)
				{
					if((pre[j] ^ pre[l]) == k)
					{
						s = j;
						cnt++;
						break;
					}
				}
					
			}
		}
	}
	
	printf("%d\n", cnt);

	return 0;
}

inline void subB()
{	
	if (k == 1)
	{
		cnt = sum1;
		return;
	}
		
	for (int i = 1; i <= tot; i++)
	{
		cnt += (sq[i + 1] - sq[i] - 1) / 2;
	}
	
	return;
}

inline void subA()
{
	cnt = n / 2;
	return;
}


