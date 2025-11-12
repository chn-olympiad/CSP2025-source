#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], sum[500005], num;
struct Node{
	int l;
	int r;
}q[5000005];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	int w = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			if((sum[i] ^ sum[j]) == k)
			{
				w++;
				q[w].l = j + 1;
				q[w].r = i;
		    }
		}
	}
	bool v = false;
	int minn = 1e9;
	for(int i = 1; i <= n; )
	{
		v = false;
		minn = 1e9;
		for(int j = 1; j <= w; j++)
		{
			if(q[j].l == i)
			{
				minn = min(minn, q[j].r);
			}
		}
		for(int k = i + 1; k <= n; k++)
		{
		    int e = minn;
    		for(int j = 1; j <= w; j++)
	    	{
		    	if(q[j].l == k)
			    {
			     	minn = min(minn, q[j].r);
			    }
		    }  
    		if(minn < e)
	    	{
		   	    i++;
		   	    v = true;
			    break;
		    }
		}
		if(v)
		{
			continue;
		}
		if(minn == 1e9)
		{
			i++;
		}
		else
		{
			i = minn + 1;
			num++;
		}
	}
	cout << num;
	return 0;
}