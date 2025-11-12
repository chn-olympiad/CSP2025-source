#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;//n行m列 
	cin>>n>>m;
	
    int s=1;
    int temp=0;
    int a1=0;
	for(int i=0;i<m*n;i++)
	{
		if(i==0)cin>>a1;
		else
		{
			cin>>temp;
			if(temp>a1)s++;
		}
	}
	int c=0;
	for(int i=1;i<=m;i++)//列 
	{
		//列 
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				c++;
				if(c==s)
				{
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}//奇数列顺排 
		else
		{
			for(int j=n;j>=1;j--)
			{
				c++;
				if(c==s)
				{
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}//偶数列逆排 
	}
	return 0;
}
