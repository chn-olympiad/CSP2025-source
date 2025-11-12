#include<bits/stdc++.h>
using namespace std;
int arr[150];
int zw[15][15];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

	int n,m,xr;//ÐÐ¡¢ÁÐ
	int sum=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>arr[i];
	}
	xr=arr[0];
	sort(arr,arr+n*m);
	for(int i=n*m;i>0;i--)
	{
		sum++;
		if(arr[i]==xr)
		{
			sum--;
			break;
		}
	}
	int i,j,x=0;
	bool flag=false;
	for(i=1;i<m;i++)//lie
	{
		if(i%2!=0)
		{
			for(j=1;j<n;j++)//hang
			{	
				x++;
				if(x==sum)
				{
					flag=true;
					break;
				}
			}
		}
		else
		{
			for(j=n;j>1;j--)//hang
			{
				x++;
				if(x==sum)
				{
					flag=true;
					break;
				}
			}
		}
	}
	cout<<ceil(sum*1.0/n)<<" "<<j;
	
    fclose(stdin);
    fclose(stdout);
    return 0;
}
