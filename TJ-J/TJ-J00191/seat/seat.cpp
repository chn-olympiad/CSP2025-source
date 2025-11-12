#include<bits/stdc++.h>

int n , m , wzh;
int x , y;
struct aa
{
	int chj;
	bool r;
};

bool cmp(aa x , aa y)
{
	return x.chj > y.chj;
}
int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	
	
	std::cin>>n>>m;
	aa a[n * m + 10];
	
	for(int i = 0 ; i < n * m ; i++)
	{
		std::cin>>a[i].chj;
	}
	a[0].r = 1;
	
	std::sort(a , a + n * m , cmp);
	
	for(int i = 0 ; i < n * m ; i++)
	{
		if(a[i].r == 1)
		{
			//std::cout<<i;
			wzh = i + 1;
			break;
		}
	}
	
	//std::cout<<wzh;
	
	x = wzh / n;
	if(wzh % n != 0)
	{
		x++;
	}
	if(x % 2 == 0)
	{
		y = wzh % n + 1;
		//y = n - y + 1;
	}else
	{
		if(wzh % n == 0)
		{
			y = n;
		}else
		{
			y = wzh % n;
		}
	}
	
	std::cout<<x<<' '<<y;
	return 0; 
}
