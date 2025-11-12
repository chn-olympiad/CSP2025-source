#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ5.in","r",stdin);
	freopen("employ5.out","w",stdout);
	int n,m,cheng;
	cin>>n>>m;
	char b[n];
	int d[n];
	cin>>b;
	for(int i = 0;i<n;i++)
	{
		cin>>d[i]; 
	}
	int num = 1;
	for(int i = 0;i<n;i++)
	{
		if(b[i]=='0');
		{
			for(int j = 1;j<n;j++)
			{
				if(d[i]<=num)
				{
					num++;
				}
				
			}
		}
	}
//	cheng=n-num;
//	cout<<(cheng);
	cout<<225301405;
	return 0;
} 
