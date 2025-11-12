#include<iostream>
using namespace std;
int main()
	{
	    int n,i,m[3],num=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=3;j++)
				{
					m[j]++;
				}
			}
		for(i=1,i<=3;i++)
			{
				num+=m[i];
			}
		cout<<num;
		return 0;
	 } 