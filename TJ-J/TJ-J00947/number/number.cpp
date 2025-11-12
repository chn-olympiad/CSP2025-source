#include <iostream>
#include <string>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	int add[100001];
	int z = 0;
	int zuizhong[100001];
	int d=-1,y=0;
	char arr[100001];
	cin >> arr;
	for(int i = 0;i<100001;i++)
	{
		if(arr[i]>='0' and arr[i]<='9')
	    {
			add[z] = int(arr[i]-'0');
			z++;
        }
	}
	for(int i = 0;i<z;i++)
	{
		for(int e = 0;e<z;e++)
		{
			if(add[e]>d)
			{
			    d = add[e];
			    y = e;
			}
		}
		add[y] = 0;
		cout << d;
		d = -1;
	}
	
	
	
	
	return 0;
}
