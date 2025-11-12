#include <bits/stdc++.h>
using namespace std;
int n,m,q=1,w,f;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	f=n*m;
	int a[f]; 
	int b[f];
	for(int i=0;i<f;i++)
	{
		cin >> a[i];
		b[i]=a[i];
	}
	for(int i=0;i<f;i++)
	{		
		if(a[i]>a[i-1])
		{ 
			b[i]=a[i-1];
		}	   
	}
	for(int i=0;i<f;i++)
	{
		if(q>n)
		{
			q--;
			w++;
			if(w%2==0)
			{
				if(a[0]!=b[i])
				{
					q--;
				}
				else
				{
					break;
				}
			}
			else
			{
				if(a[0]!=b[i])
				{
					q++;
				}
				else
				{
					break;
				}
			}
		}
		else if(q<=1)
		{
			w++;
			q++;
			if(w%2==0)
			{
				if(a[0]!=b[i])
				{
					q--;
				}
				else
				{
					break;
				} 
			}
			else
			{
				if(a[0]!=b[i])
				{
					q++;
				}
				else
				{
					break;
				}
			}
		}
	}
	cout << q << " " << w;
	return 0;
} 
