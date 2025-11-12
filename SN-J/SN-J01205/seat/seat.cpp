#include <iostream>

using namespace std;
int as[101] = {0};
int main()
{
	
//	freopen("seat","r"stdin);
//	freopen("seat","w"stdans);
    int n,m,c,ming,yi;
    for(int i = 1;i <= n * m;i++)
    {
    	cin >> as[i - 1];
    }
    ming = as[0];
	for(int i = 1;i <= size(as);i++)
	{
		for(int j = 1;j <= size(as);j++)
		{
			if(as[j] > as[i])
			{
				c = as[j];
				as[j] = as[i];
				as[i] = c;
				c = 0;
			}
		}
	}
	for(int i = 1;i <= size(as);i++)
	{
		if(as[i - 1] = ming)
		{
			ming = i - 1;
		}
	}
	c = ming % m ;
	yi = ming / 2n;
	yi -= n;
	if(c % 2 = 1)
	{
		cout << c << " " << yi;
	}else{
		yi = n - yi;
		cout << c << " " << yi;	
	}
	
    return 0;
}
