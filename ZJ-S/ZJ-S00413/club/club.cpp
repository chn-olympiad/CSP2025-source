#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t;
int n;
int maxx;
int A[N];
int B[N];
int C[N];
int h[N];
int a[10][N];
int dc[N];
int topa, topb, topc,top;
long long sum;
void pusha ( int markk )
{
	top = 0;
	if (topa < n / 2 )
	{
		while ( dc[A[topa]] < dc[markk] && topa )
		{
			h[++top] = A[topa];
			topa--;
		}
		A[++topa] = markk;
		for ( int i = top; i >= 1; i-- )
		{
			A[++topa] = h[i];
		}
	}
	else
	{
		if ( dc[A[topa]] > dc[markk] )
		{
			if ( a[2][markk] > a[3][markk] )
			{
						while ( dc[B[topb]] < dc[markk] &&topb)
						{
							h[++top] = B[topb];
							topb--;
						}
						B[++topb] = markk;
						for ( int i = top; i >= 1; i-- )
						{
							B[++topb] = h[i];
						}
			}
			else
			{
					while ( dc[C[topc]] < dc[markk] &&topc)
					{
						h[++top] = C[topc];
						topc--;
					}
					C[++topc] = markk;
					for ( int i = top; i >= 1; i-- )
					{
						C[++topc] = h[i];
					}
			}
		}
		else
		{
			int q = A[topa];
			topa--;
			if ( a[2][q] > a[3][q] )
			{
				while ( dc[B[topb]] < dc[q]&&topb )
						{
							h[++top] = B[topb];
							topb--;
						}
						B[++topb] = q;
						for ( int i = top; i >= 1; i-- )
						{
							B[++topb] = h[i];
						}
			}
			else
			{
				while ( dc[C[topc]] < dc[q] &&topc)
					{
						h[++top] = C[topc];
						topc--;
					}
					C[++topc] = q;
					for ( int i = top; i >= 1; i-- )
					{
						C[++topc] = h[i];
					}
			}
			while ( dc[A[topa]] < dc[markk] &&topa)
			{
				h[++top] = A[topa];
				topa--;
			}
			A[++topa] = markk;
			for ( int i = top; i >= 1; i-- )
			{
				A[++topa] = h[i];
			}
		}
	}
}
void pushb ( int markk )
{
	top = 0;
	if (topb < n / 2 )
	{
		while ( dc[B[topb]] < dc[markk]&&topb )
		{
			h[++top] = B[topb];
			topb--;
		}
		B[++topb] = markk;
		for ( int i = top; i >= 1; i-- )
		{
			B[++topb] = h[i];
		}
	}
	else
	{
		if ( dc[B[topb]] > dc[markk] )
		{
			if ( a[1][markk] > a[3][markk] )
			{
				while ( dc[A[topa]] < dc[markk]&&topa )
				{
					h[++top] = A[topa];
					topa--;
				}
				A[++topa] = markk;
				for ( int i = top; i >= 1; i-- )
				{
					A[++topa] = h[i];
				}
			}
			else
			{
				while ( dc[C[topc]] < dc[markk]&&topc )
					{
						h[++top] = C[topc];
						topc--;
					}
					C[++topc] = markk;
					for ( int i = top; i >= 1; i-- )
					{
						C[++topc] = h[i];
					}
			}
		}
		else
		{
			int q = B[topb];
			topb--;
			if ( a[1][q] > a[3][q] )
			{
				while ( dc[A[topa]] < dc[q] &&topa)
				{
					h[++top] = A[topa];
					topa--;
				}
				A[++topa] = q;
				for ( int i = top; i >= 1; i-- )
				{
					A[++topa] = h[i];
				}
			}
			else
			{
				while ( dc[C[topc]] < dc[q]&&topc )
					{
						h[++top] = C[topc];
						topc--;
					}
					C[++topc] = q;
					for ( int i = top; i >= 1; i-- )
					{
						C[++topc] = h[i];
					}
			}
			while ( dc[B[topb]] < dc[markk] &&topb)
			{
				h[++top] = B[topb];
				topb--;
			}
			B[++topb] = markk;
			for ( int i = top; i >= 1; i-- )
			{
				B[++topb] = h[i];
			}
		}
	}
}
void pushc ( int markk )
{
	top = 0;
	if (topc < n / 2 )
	{
		while ( dc[C[topc]] < dc[markk]&&topc )
		{
			h[++top] = C[topc];
			topc--;
		}
		C[++topc] = markk;
		for ( int i = top; i >= 1; i-- )
		{
			C[++topc] = h[i];
		}
	}
	else
	{
		if ( dc[C[topc]] > dc[markk] )
		{
			if ( a[2][markk] > a[1][markk] )
			{
					while ( dc[B[topb]] < dc[markk]&&topb )
					{
						h[++top] = B[topb];
						topb--;
					}
					B[++topb] = markk;
					for ( int i = top; i >= 1; i-- )
					{
						B[++topb] = h[i];
					}
			}
			else
			{
					while ( dc[A[topa]] < dc[markk]&&topa )
					{
						h[++top] = A[topa];
						topa--;
					}
					A[++topa] = markk;
					for ( int i = top; i >= 1; i-- )
					{
						A[++topa] = h[i];
					}
			}
		}
		else
		{
			int q = C[topc];
			topc--;
			if ( a[2][q] > a[1][q] )
			{
					while ( dc[B[topb]] < dc[q]&&topb )
					{
						h[++top] = B[topb];
						topb--;
					}
					B[++topb] = q;
					for ( int i = top; i >= 1; i-- )
					{
						B[++topb] = h[i];
					}
			}
			else
			{
					while ( dc[A[topa]] < dc[q]&&topa )
				{
					h[++top] = A[topa];
					topa--;
				}
				A[++topa] = q;
				for ( int i = top; i >= 1; i-- )
				{
					A[++topa] = h[i];
				}
			}
			while ( dc[C[topc]] < dc[markk]&&topc )
			{
				h[++top] = C[topc];
				topc--;
			}
			C[++topc] = markk;
			for ( int i = top; i >= 1; i-- )
			{
				C[++topc] = h[i];
			}
		}
	}
}
void solve ( int markk )
{
	if ( a[1][markk] >= a[2][markk] && a[1][markk] >= a[3][markk] )
	{
		pusha ( markk );
	}
	else if ( a[2][markk] >= a[3][markk] )
	{
		pushb ( markk );
	}
	else
	{
		pushc ( markk );
	}
}
int main()
{
	freopen ( "club2.in", "r", stdin );
	freopen ( "club.out", "w", stdout );
	cin >> t;
	while ( t-- )
	{
		sum = 0;
		topa = 0;
		topb = 0;
		topc = 0;
		cin >> n;
		for ( int i = 1; i <= n; i ++ )
		{
			cin >> a[1][i] >> a[2][i] >> a[3][i];
			dc[i] =max(a[1][i],max(a[2][i],a[3][i])) -( a[1][i] + a[2][i] + a[3][i] - max(a[1][i],max(a[2][i],a[3][i])) - min(a[1][i],min(a[2][i],a[3][i])));
		}
		for ( int i = 1; i <= n; i ++ )
			solve ( i );
		for ( int i = 1; i <= topa; i++ )
		sum += a[1][A[i]];
		for ( int i = 1; i <= topb; i++ )
			sum += a[2][B[i]];
		for ( int i = 1; i <= topc; i++ )
			sum += a[3][C[i]];
		cout << sum << endl;
	}
	return 0;
}
