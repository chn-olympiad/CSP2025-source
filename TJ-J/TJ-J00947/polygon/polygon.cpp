#include <iostream>
#include <string>
using namespace std;
int main()
{
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout); 
    int m;
	cin >> m;
	int arr[m];
	for(int i = 0;i<m;i++)
	{
		cin >> arr[i];
	}
	int gd = 0,better = -1,gd2=0;
	int zsgd = 0;
	int z = 0;
	int n = 0;
	int add[3];
	for(int i = 0;i<m;i++)
	{	
	    gd2 = arr[i];
        for(int j = 0;j<m;j++)
        {
        	if(j==i)
        	{
        		continue;
			}
        	if(gd2>arr[j])
        	{
        		better = gd2;
			}
			else
			{
				better = arr[j];
			}
        	if(gd2+arr[j]>2*better)
        	{
        		n++;
			}
			better = -1;
		}
		better = -1;
		for(int j = 1;j<m;j++)
		{
			gd = arr[j];
			zsgd=arr[j+1];
			add[0] = gd;
			add[1] = zsgd;
			for(int e = 0;e<m;e++)
			{
				if(e == j or e == j+1)
				{
					continue;
				}
				add[2] = arr[e];
				for(int i = 0;i<2;i++)
				{
					if(add[i]>better)
					{
						better = add[i];
					}
				}
				if(gd+arr[e]+zsgd > better)
				{
					n++;
				}
			}
		}
	}
	cout << n;
	
	
	
	
	
	
	return 0;
}
