#include<bits/stdc++.h>
using namespace std;

long long int n,k,a[500005],i,l,r,sum;

long long int change(long long int x)
{
	long long int b[30] = {0},j = 29;
	if(x == 0) return 0;
	long long int ans = 0;
	while(x != 0)
	{
		b[j--] = x%2;
		x /= 2;
	}
	for(j;j < 30;j++) ans = ans*10+b[j];
	return ans;
}

long long int yh(long long int y,long long int s,long long int e)
{
	if(s == e+1) return change(a[s]);
	else
	{
		long long int at = change(y),bt = change(a[s]),c[30] = {0},ans = 0,m = 29;
		while(at != 0 || bt != 0)
		{
			if(at != 0 && bt != 0)
			{
				if(at%10 == bt%10) c[m--] = 0;
				else c[m--] = 1;
				at /= 10;
				bt /= 10;
			}
			else
			{
				if(at != 0 && bt == 0)
				{
					if(at%10 == 0) c[m--] = 0;
					else c[m--] = 1;
					at /= 10;
				}
				else
				{
					if(at == 0 && bt != 0)
					{
						if(0 == bt%10) c[m--] = 0;
						else c[m--] = 1;
						bt /= 10;
					}
				}
			}
		}
		for(m;m < 30;m++) ans = ans*10+c[m];
		return yh(ans,s+1,e);
	}
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(i = 0;i < n;i++) cin >> a[i];
	yh(a[1],2,3);
	for(l = 0;l < n;l++)
	{
		for(r = l;r < n;r++)
		{
			if(yh(a[l],l,r) == change(k))
			{
				cout << l << " " << r << endl;
				sum++;
				l = r+1;
			}
		}
	}
	cout << sum;
	return 0;
}
