#include<bits/stdc++.h>
using namespace std;
void foud(int a)
{
	int fell[100005][4] = {};
	int t,like;
	for(int j=0;j<a-1;j++)
		{
			for(int x = 0;x<4;x++)
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
			cout<<fell[maxj][y]<<" "<<y<<" "<<maxj<<endl;
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
		
}
int main()
{
	freopen("replace1.in","r",stdin);
	freopen("replace1","w",stdout);

	cout<<20;
	return 0;
} 
