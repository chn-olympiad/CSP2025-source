#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int max=0,index=0;
	int cheng_ji[n*m+5],cheng_ji2[n*m+5];
	for(int i=1;i<=n*m;i++)
		cin >> cheng_ji[i];
		int xr=cheng_ji[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
			if(cheng_ji[j]>max)
			{
				max=cheng_ji[j];
			    index=j;	
			}
		}
		cheng_ji2[i]=max;
		max=0;
		cheng_ji[index]=-1;
	}
	int yushu=0,shang=0;
	for(int i=1;i<=n*m;i++)
	{
		if(cheng_ji[i]==xr)
		{
			shang=i/n;
			yushu=i%n;
			if(shang!=0&&yushu==0)
			{
				cout<< n << " " << shang <<endl;
				return 0;
			}
			else if(shang!=0&&yushu!=0&&shang%2==1)
			{
				cout<< yushu << " " << shang+1 <<endl;
				return 0;
			}
			else if(shang!=0&&yushu!=0&&shang%2==0)
			{
				cout<< abs(yushu-5) << " " << shang+1 <<endl;
				return 0;
			}
			else if(shang==0&&yushu==0)
			{
				cout<< 1 << " " << 1 <<endl;
				return 0;
			}
			else if(shang==0&&yushu!=0)
			{
				cout<< yushu << " " << 1 <<endl;
				return 0;
			}
		}
		else
			continue;
	}
	cout << 2 << 1 <<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
