#include <iostream>
#include <string>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;
    cin >> n >> m;
	int xiaoming;
    cin >> xiaoming;
	int arr[n*m-1];
	int x=0,y=0;
	int z=1;
	for(int i = 0;i<n*m-1;i++)
	{
		std::cin >> arr[i];
		if(arr[i]>xiaoming)
		{
			z++;
		}
	}
	x = z/n;
	if(z%n == 0)
	{
	}
	else
	{
		x++;
	}
	if(x%2==0)
	{
		y = z%n;
		if(y == 0)
		{
			y = n;
		}
		y = n-y+1;
	}
	else
	{
		y = z%n;
		if(y == 0)
		{
			y = n;
		}
	}
	cout << x << " " << y;
	
	
	
	
	return 0;
}
