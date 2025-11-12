#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int xiaor;
int xiaorxiabiao;
int a[105];
int c[105];
int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
    
    cin >> n >> m;
    for(int i=1 ; i<=n*m ; i++)
    {
    	cin >> a[i];
	}
	
	xiaor = a[1];
	
	for(int i=1 ; i<=n*m ; i++)
	{
		for(int j=i ; j<=n*m ; j++)
		{
			if(a[j] > a[i])
			{
				swap(a[i] , a[j]);
			}
			
		}
	}
	
	for(int i=1 ; i<=n*m ; i++)
    {
    	if(xiaor == a[i])
    	{
    		xiaorxiabiao = i;
		}
	}
	
	int shang = xiaorxiabiao/n;
	int yu = xiaorxiabiao%n;
	if(shang == 0)
	{
		cout << 1 << ' ' << yu;
	}
	else if(shang%2==1)
	{
		if(yu==0)
		{
			cout <<shang <<' ' << n;
		}
		else
		{
			cout << shang +1 << ' ' << n+1-yu;
		}
	}
	else if(shang%2==0)
	{
		if(yu==0)
		{
			cout << shang << ' ' << 1;
		}
		else
		{
			cout << shang+1 << ' ' << yu;
		}
	}
	
	return 0;
 } 
