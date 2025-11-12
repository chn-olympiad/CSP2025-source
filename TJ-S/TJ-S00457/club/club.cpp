#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <cstdio>
bool cmp(int a,int b)
{
	if(a >= b)
	{
		return a > b; 
	}
	else
	{
		return b > a;
	}
}
using namespace std;
const int p = 100005;
int n = 0;
int a,b,c = 0;
int z[3][p];
int y[3][p];
int x[3][p];
int tl = 0;
int f[p];
int npoe[p];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin >> t;
	for(int i = 1;i <= t;i++)
	{
		cin >> npoe[i];
		f[i] = npoe[i]/2;
		for(int k = 1;k <= 3;k++)
		{
			for(int j = 1;j <= n;j++)
			{
				cin >> z[k][j] >> y[k][j] >> x[k][j];
			}
		}
	}
	for(int i = 1;i <= t;i++)
	{
		for(int k = 1;k <= 3;k++)
		{
			for(int j = 1;j <= npoe[i];j++)
			{
				long long  maxn[npoe[i]*2] = {};
			}
		}
	}
	int Maxn = 0;
	for(int i = 1;i <= t;i++)
	{	
		for(int j = 1;j <= f[i]*2;j++)
		{
			int m[f[i]*2] = {};
			m[j] = max(max(Maxn,z[j]),max(y[j],x[j]));
		}
	}
	sort(m,m+(npoe[i]*2),cmp);
	for(int i = 1;i <= t;i++)
	{
		for(int j = 1;j <= f[i]*2;j++)
		{
			for(int k = 1;k <= 3;k++)
			{
				if(m[j] == z[k][j])
				{
					while(a <= f[i] && b <= f[i] && c <= f[i])
					{
						if(m[j]) == z[k][j];
						{
							if(k == 1)
							{	a++;
								tl = tl + m[j];
							}
							if(k == 2)
							{
								b++;
								tl = tl + m[j];
							}
							if(k == 3)
							{
								c++;
								tl = tl + m[j];
							}		
						}
						if(m[j] == y[k][j])
						{
							if(k == 1)
							{	a++;
								tl = tl + m[j];
							}
							if(k == 2)
							{
								b++;
								tl = tl + m[j];
							}
							if(k == 3)
							{
								c++;
								tl = tl + m[j];
							}		
						}
						if(maxn[j] == x[k][j])
						{
							if(k == 1)
							{	a++;
								tl = tl + m[j];
							}
							if(k == 2)
							{
								b++;
								tl = tl + m[j];
							}
							if(k == 3)
							{
								c++;
								tl = tl + m[j];
							}		
						}
						if(a == f[i] || b == f[i] || c == f[i])
						{
							break;
						}
						
					}
					if(a == f[i])
					{
						while(b <= f[i] && c <= f[i])
						{
							if(m[j] == z[k][j])	
							{
								if(k == 1)
								{
									max(z[k][j-1],z[k][j+1])
									if(k == 2)
									{
										b++;
										tl = tl + m[j];
									}
									if(k == 3)
									{
										c++;
										tl = tl + m[j];
									}
								}
								if(k == 2)
								{
									b++;
									tl = tl + m[j];
								}
								if(k == 3)
								{
									c++;
									tl = tl + m[j];
								}
							}
							if(b == f[i] || c == f[i])
							{
								if(b == f[i])
								{
									if(k == 3)
									{
										tl = tl + m[j];	
									}
								}
								if(c == f[i])
								{
									if(k == 2)
									{
										tl = tl + m[j];	
									}
								}
								break;
							}
						}
					}
					if(b == f[i])
					{
						while(a <= f[i] && c <= f[i])
						{
							if(m[j] == z[k][j])	
							{
								if(k == 1)
								{
									a++;
								}
								if(k == 2)
								{
									max(z[k][j-1],z[k][j+1])
								}
								if(k == 3)
								{
									c++;
									tl = tl + m[j];
									}
								}
								if(k == 2)
								{
									b++;
									tl = tl + m[j];
								}
								if(k == 3)
								{
									c++;
									tl = tl + m[j];
								}
						}
							if(a == f[i] || c == f[i])
							{
								if(a == f[i])
								{
									if(k == 1)
									{
										tl = tl + m[j];	
									}
								}
								if(c == f[i])
								{
									if(k == 3)
									{
										tl = tl + m[j];	
									}
								}
								break;
							}
					}
					if(c == f[i])
					{
						while(a <= f[i] && b <= f[i])
						{
							if(m[j] == z[k][j])	
							{
								if(k == 1)
								{
									a++;
									tl = tl + m[j];
								}
								if(k == 2)
								{
									b++;
									tl = tl + m[j];
								}
								if(k == 3)
								{
									max(z[k][j-1],z[k][j+1])
									if(k == 2)
									{
										b++;
										tl = tl + m[j];
									}
									if(k == 1)
									{
										a++;
										tl = tl + m[j];
									}
									
								}
							}
								if(k == 2)
								{
									b++;
									tl = tl + m[j];
								}
								if(k == 3)
								{
									c++;
									tl = tl + m[j];
								}
						}
							if(a == f[i] || b == f[i])
							{
								if(a == f[i])
								{
									if(k == 1)
									{
										a++;
										tl = tl + m[j];	
									}
								}
								if(b == f[i])
								{
									if(k == 2)
									{
										tl = tl + m[j];	
									}
								}
								break;
							}
					}
					}
				}
			}
			cout << tl << endl;
		}
	}
	
	return 0;
}
}
