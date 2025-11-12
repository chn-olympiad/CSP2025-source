#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int score[n*m];
	int sp[n*m];
	int seatx[n*m];
	int seaty[n*m];
	for(int i=0;i<=n*m-1;i++)
	{
		cin>>score[i];
	} 
	int Rs=score[0];
	 for(int j=0;j<=n*m-1;j++)
        {	
        	int lt;
            for(int z=0;z<=n*m-1;z++)
            {
                lt=0;
                lt=max(lt,score[z]);
            }
            sp[j]=lt;
            for(int y=0;y<=n*m-1;y++)
			{
				if(score[y]==lt)
				{
					score[y]-=lt;
				}
			}
		}
	 for(int i=0;i<=n*m-1;i++)
	 {
	 	if(sp[i]==Rs)
	 	{
	 		Rs=i;	
		}
	 }
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2!=0)
		{	
			for(int j=1;j<=m;j++)
			{
				seaty[cnt]=j;
				seatx[cnt]=i;
				cnt++;
			}
		} 
		else
		{
			for(int j=m;j>=1;j--)
			{
				seaty[cnt]=j;
				seatx[cnt]=i;
				cnt++;
			}
		}
	}
	cout<<seaty[Rs]<<' '<<seatx[Rs];
    return 0;
} 
