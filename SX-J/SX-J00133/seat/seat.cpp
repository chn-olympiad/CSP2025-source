#include<bits/stdc++.h>
using namespace std;
int n,m;
int lxy[121],cmy[11][11],e=1;
bool xy(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=n*m;
    for(int i=1;i<=num;i++) cin>>lxy[i];
    int fo=lxy[1];
    sort(lxy+1,lxy+1+num,xy);
    for(int i=1;i<=m;i++)
    {
    	if(i%2==0)
    	{
    		for(int j=n;j>=1;j--)
			{
               cmy[i][j]=lxy[e];
               e++;
			   if(cmy[i][j]==fo)
               {
                 cout<<i<<" "<<j<<" ";
                  return 0;
               }
			}
		}
		else
		{
           for(int j=1;j<=n;j++)
		    {
               cmy[i][j]=lxy[e];
               e++;
               if(cmy[i][j]==fo)
               {
                 cout<<i<<" "<<j<<" ";
                 return 0;
	           }
            }
		}

	}

     return 0;
}