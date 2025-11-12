#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t , n;
	
	int aqu[10000] , bqu[10000] , cqu[10000];
	int cla , clb , clc;
	cin >> t;
	for(int i = 1 ; i <= t ; i++)
	{
		cin >> n;
		int anum = 0 , bnum = 0 , cnum = 0 ;
		int an , bn, cn;
		int ans = 0;
		int a[100000] , b[100000] , c[100000];
		int ab[1000] , bb[1000] , cb[1000];
		int hn = n / 2;
		for(int j = 1 ; j <= n ; j++)
		{
			cin >> a[j] >> b[j] >> c[j];
			if(a[j] > b[j] && a[j] >c[j])
			{
				anum ++;
				an += a[j];
				ab[j] = 1;
			}
			else if(b[j] > a[j] && b[j] > c[j])
			{
				bnum ++;
				bn += b[j];
				bb[j] = 1;
			}
			else
			{
				cnum ++;
				cn += c[j];
				cb[j] = 1;
			}
		}
		ans = an + bn + cn;
		cout << ans;
		if(anum > hn || bnum > hn || cnum > hn)
		{
			while(anum <= hn && bnum <= hn && cnum <= hn)
			{
				if(anum > hn)
				{
					int min = 10086;//最小数 
					int gps ;//最小数位置 
					for(int j = 1 ; j <= hn ; j++)
					{
						if(ab[j] == 1)
						{
							if(a[j] < min)
							{
								min = a[j];
								gps = j;
							}
							if(a[j] == min)//选第二兴趣最高者参与别的活动 
							{
								int maxn = 0;
								int go; 
								if(b[j] > maxn)
								{
									maxn = b[j];
									go = 1;
								}
								if(c[j] > maxn)
								{
									maxn = c[j];
									go = 2;
								}
								if(b[gps] > maxn)
								{
									maxn = b[gps];
									go = 3;
								}
								if(c[gps] > maxn)
								{
									maxn = c[gps];
									go = 4;
								}
								if(go = 1)
								{
									an -= a[j];
									bn += b[j];
									bnum ++;
								}
								if(go = 2)
								{
									an -= a[j];
									cn += c[j];
									cnum ++;
								}
								if(go = 3)
								{
									an -= a[j];
									bn += b[gps];
									bnum ++;
								}
								if(go = 1)
								{
									an -= a[j];
									cn += c[gps];
									cnum ++;
								}
							}
						}
					}
				}
				if(bnum > hn)
				{
					int min = 10086;//最小数 
					int gps ;//最小数位置 
					for(int j = 1 ; j <= hn ; j++)
					{
						if(bb[j] == 1)
						{
							if(b[j] < min)
							{
								min = b[j];
								gps = j;
							}
							if(b[j] == min)//选第二兴趣最高者参与别的活动 
							{
								int maxn = 0;
								int go; 
								if(a[j] > maxn)
								{
									maxn = a[j];
									go = 1;
								}
								if(c[j] > maxn)
								{
									maxn = c[j];
									go = 2;
								}
								if(a[gps] > maxn)
								{
									maxn = a[gps];
									go = 3;
								}
								if(c[gps] > maxn)
								{
									maxn = c[gps];
									go = 4;
								}
								if(go = 1)
								{
									bn -= b[j];
									an += a[j];
									anum ++;
								}
								if(go = 2)
								{
									bn -= b[j];
									cn += c[j];
									cnum ++;
								}
								if(go = 3)
								{
									bn -= b[j];
									an += a[gps];
									anum ++;
								}
								if(go = 1)
								{
									bn -= b[j];
									cn += c[gps];
									cnum ++;
								}
							}
						}
					}
				}
				if(cnum > hn)
				{
					int min = 10086;//最小数 
					int gps ;//最小数位置 
					for(int j = 1 ; j <= hn ; j++)
					{
						if(cb[j] == 1)
						{
							if(c[j] < min)
							{
								min = c[j];
								gps = j;
							}
							if(c[j] == min)//选第二兴趣最高者参与别的活动 
							{
								int maxn = 0;
								int go; 
								if(b[j] > maxn)
								{
									maxn = b[j];
									go = 1;
								}
								if(a[j] > maxn)
								{
									maxn = a[j];
									go = 2;
								}
								if(b[gps] > maxn)
								{
									maxn = b[gps];
									go = 3;
								}
								if(a[gps] > maxn)
								{
									maxn = a[gps];
									go = 4;
								}
								if(go = 1)
								{
									cn -= c[j];
									bn += b[j];
									bnum ++;
								}
								if(go = 2)
								{
									cn -= c[j];
									an += a[j];
									cnum ++;
								}
								if(go = 3)
								{
									cn -= c[j];
									bn += b[gps];
									bnum ++;
								}
								if(go = 1)
								{
									cn -= c[j];
									an += a[gps];
									anum ++;
								}
							}
						}
					}
				}
			}
		}
		else
		{
			cout << ans ;
		}
		
	}
	
	return 0;
}
