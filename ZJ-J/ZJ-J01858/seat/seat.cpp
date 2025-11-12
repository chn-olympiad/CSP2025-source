#include<bits/stdc++.h>
using namespace std;
int n,m;
int x,ans;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<=n*m-1;i++)
	{
		int y;
		cin>>y;
		if(y>x)ans++;
	}
	if(n==1)
	{
		cout<<ans+1<<" "<<1;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	int ax=1,ay=1;
	for(int i=1;i<=ans;i++)
	{
		if(ax==n)
		{
			if(ay%2==1)
			ay++;
			else ax--;
		}
		else 
		{
			if(ax==1)
			{
				if(ay%2==0)
				ay++;
				else ax++;
			}
			else
			{
				if(ay%2==1)
				ax++;
				else ax--;
			}
		}
	}
	cout<<ay<<" "<<ax;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//#Shang4Shan3Ruo6Shui4
