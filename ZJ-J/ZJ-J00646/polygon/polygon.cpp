#include<bits/stdc++.h>
using namespace std;

int n, stick[5005];

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> stick[i];
	}
	sort(stick + 1, stick + n + 1);
	if(n == 3)
	{
		if(stick[1] + stick[2] > stick[3]) cout << "1";
		else cout << "0";
	}
	else if(n == 4)
	{
		int ans = 0;
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					if(stick[a] + stick[b] > stick[c]) ans++;
				}
			}
		}
		if(stick[1] + stick[2] + stick[3] > stick[4]) ans++;
		cout << ans;
	}
	else if(n == 5)
	{
		int ans = 0;
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					if(stick[a] + stick[b] > stick[c]) ans++;
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						if(stick[a] + stick[b] + stick[c] > stick[d]) ans++;
					}
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						for(int e = d + 1; e <= n; e++)
						{
							if(stick[a] + stick[b] + stick[c] + stick[d] > stick[e]) ans++;
						}
					}
				}
			}
		}
		cout << ans;
	}
	else if(n == 6)
	{
		int ans = 0;
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					if(stick[a] + stick[b] > stick[c]) ans++;
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						if(stick[a] + stick[b] + stick[c] > stick[d]) ans++;
					}
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						for(int e = d + 1; e <= n; e++)
						{
							if(stick[a] + stick[b] + stick[c] + stick[d] > stick[e]) ans++;
						}
					}
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						for(int e = d + 1; e <= n; e++)
						{
							for(int f = e + 1; f <= n; f++)
							{
								if(stick[a] + stick[b] + stick[c] + stick[d] + stick[e] > stick[f]) ans++;
							}
						}
					}
				}
			}
		}
		cout << ans;
	}
	else if(n == 7)
	{
		int ans = 0;
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					if(stick[a] + stick[b] > stick[c]) ans++;
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						if(stick[a] + stick[b] + stick[c] > stick[d]) ans++;
					}
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						for(int e = d + 1; e <= n; e++)
						{
							if(stick[a] + stick[b] + stick[c] + stick[d] > stick[e]) ans++;
						}
					}
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						for(int e = d + 1; e <= n; e++)
						{
							for(int f = e + 1; f <= n; f++)
							{
								if(stick[a] + stick[b] + stick[c] + stick[d] + stick[e] > stick[f]) ans++;
							}
						}
					}
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						for(int e = d + 1; e <= n; e++)
						{
							for(int f = e + 1; f <= n; f++)
							{	
								for(int g = f + 1; g <= n; g++)
								{
									if(stick[a] + stick[b] + stick[c] + stick[d] + stick[e] + stick[f] > stick[g]) ans++;
								}
							}
						}
					}
				}
			}
		}
		cout << ans;
	}
	else if(n == 8)
	{
		int ans = 0;
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					if(stick[a] + stick[b] > stick[c]) ans++;
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						if(stick[a] + stick[b] + stick[c] > stick[d]) ans++;
					}
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						for(int e = d + 1; e <= n; e++)
						{
							if(stick[a] + stick[b] + stick[c] + stick[d] > stick[e]) ans++;
						}
					}
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						for(int e = d + 1; e <= n; e++)
						{
							for(int f = e + 1; f <= n; f++)
							{
								if(stick[a] + stick[b] + stick[c] + stick[d] + stick[e] > stick[f]) ans++;
							}
						}
					}
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						for(int e = d + 1; e <= n; e++)
						{
							for(int f = e + 1; f <= n; f++)
							{	
								for(int g = f + 1; g <= n; g++)
								{
									if(stick[a] + stick[b] + stick[c] + stick[d] + stick[e] + stick[f] > stick[g]) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						for(int e = d + 1; e <= n; e++)
						{
							for(int f = e + 1; f <= n; f++)
							{	
								for(int g = f + 1; g <= n; g++)
								{
									for(int h = g + 1; h <= n; h++)
									{
										if(stick[a] + stick[b] + stick[c] + stick[d] + stick[e] + stick[f] + stick[g] > stick[h]) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		cout << ans;
	}
	else if(n == 9)
	{
		int ans = 0;
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					if(stick[a] + stick[b] > stick[c]) ans++;
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						if(stick[a] + stick[b] + stick[c] > stick[d]) ans++;
					}
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						for(int e = d + 1; e <= n; e++)
						{
							if(stick[a] + stick[b] + stick[c] + stick[d] > stick[e]) ans++;
						}
					}
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						for(int e = d + 1; e <= n; e++)
						{
							for(int f = e + 1; f <= n; f++)
							{
								if(stick[a] + stick[b] + stick[c] + stick[d] + stick[e] > stick[f]) ans++;
							}
						}
					}
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						for(int e = d + 1; e <= n; e++)
						{
							for(int f = e + 1; f <= n; f++)
							{	
								for(int g = f + 1; g <= n; g++)
								{
									if(stick[a] + stick[b] + stick[c] + stick[d] + stick[e] + stick[f] > stick[g]) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						for(int e = d + 1; e <= n; e++)
						{
							for(int f = e + 1; f <= n; f++)
							{	
								for(int g = f + 1; g <= n; g++)
								{
									for(int h = g + 1; h <= n; h++)
									{
										if(stick[a] + stick[b] + stick[c] + stick[d] + stick[e] + stick[f] + stick[g] > stick[h]) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						for(int e = d + 1; e <= n; e++)
						{
							for(int f = e + 1; f <= n; f++)
							{	
								for(int g = f + 1; g <= n; g++)
								{
									for(int h = g + 1; h <= n; h++)
									{
										for(int i = h + 1; i <= n; i++)
										{
											if(stick[a] + stick[b] + stick[c] + stick[d] + stick[e] + stick[f] + stick[g] + stick[h] > stick[i]) ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout << ans;
	}
	else if(n == 9)
	{
		int ans = 0;
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					if(stick[a] + stick[b] > stick[c]) ans++;
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						if(stick[a] + stick[b] + stick[c] > stick[d]) ans++;
					}
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						for(int e = d + 1; e <= n; e++)
						{
							if(stick[a] + stick[b] + stick[c] + stick[d] > stick[e]) ans++;
						}
					}
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						for(int e = d + 1; e <= n; e++)
						{
							for(int f = e + 1; f <= n; f++)
							{
								if(stick[a] + stick[b] + stick[c] + stick[d] + stick[e] > stick[f]) ans++;
							}
						}
					}
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						for(int e = d + 1; e <= n; e++)
						{
							for(int f = e + 1; f <= n; f++)
							{	
								for(int g = f + 1; g <= n; g++)
								{
									if(stick[a] + stick[b] + stick[c] + stick[d] + stick[e] + stick[f] > stick[g]) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						for(int e = d + 1; e <= n; e++)
						{
							for(int f = e + 1; f <= n; f++)
							{	
								for(int g = f + 1; g <= n; g++)
								{
									for(int h = g + 1; h <= n; h++)
									{
										if(stick[a] + stick[b] + stick[c] + stick[d] + stick[e] + stick[f] + stick[g] > stick[h]) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int a = 1; a <= n; a++)
		{
			for(int b = a + 1; b <= n; b++)
			{
				for(int c = b + 1; c <= n; c++)
				{
					for(int d = c + 1; d <= n; d++)
					{
						for(int e = d + 1; e <= n; e++)
						{
							for(int f = e + 1; f <= n; f++)
							{	
								for(int g = f + 1; g <= n; g++)
								{
									for(int h = g + 1; h <= n; h++)
									{
										for(int i = h + 1; i <= n; i++)
										{
											for(int j = i + 1; j <= n; j++)
											{
												if(stick[a] + stick[b] + stick[c] + stick[d] + stick[e] + stick[f] + stick[g] + stick[h] + stick[i] > stick[j]) ans++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout << ans;
	}
	else
	{
		cout << "RP++";
	};
	return 0;
} 