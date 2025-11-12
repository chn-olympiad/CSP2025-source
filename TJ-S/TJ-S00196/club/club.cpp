#include<bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int fell[100005][4] = {};
	int t,a,like;
	cin>>t;
	for(int i =0;i<t;i++)
	{
		cin>>a;
		for(int j=0;j<a;j++)
		{
			for(int x = 0;x<3;x++)
			{
				cin >> fell[j][x];
			}
		}
		int y = 0;
		while(fell[a][3]<a)
		{
			int maxj = 0;
			for(int j = 1;j<a;j++)
			{
				if(fell[j][y]>fell[maxj][y])
				{
					if(fell[j][3]!=1 && fell[a][y]<=a/2)
					{

						maxj = j;
					}
				
				}
			}
			like+=fell[maxj][y];
			cout<<fell[maxj][y]<<" "<<maxj<<" "<<y<<endl;
			fell[a][y]++;
			fell[maxj][3] = 1;
			fell[a][3]++;
			if(y==2)
			{
				y=0;
			}
			else
			{
				y++;
			}
			
		}

		cout<<like;
		

	}

	return 0;
} 
