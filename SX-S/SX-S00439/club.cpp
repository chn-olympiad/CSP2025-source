#include <bits/stdc++.h>
using namespace std;

int t;
int a[11][2];
int x[11];

void kk()
{
	int n=0;
	int ans=0;
	int tmp=0;
	cin>>n;
	if(n<=10)
	{
		
	for(int i=0;i<n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	for(int p=0;;p++)
	{
		for(int i=0;i<n;i++)
		{
			tmp=tmp+a[i][x[i]];
		}
		if(tmp>ans)
		{
			ans=tmp;
		}
		tmp=0;
		if(x[0]==2)
		{
			x[0]+=1;
			for(int i=0;i<=n;i++)
			{
				
				if(x[i]==3)
				{
					x[i]=0;
					x[i+1]+=1;
				}
			}
		}
		else
		{
			x[0]+=1;
		}
		if(x[n]==1)
			break;
	}
	cout<<ans<<'\n';
	ans=0;
		for(int i=0;i<=n;i++)
			{
				a[i][1]=0;
				x[i]=0;
			}
			for(int i=0;i<n;i++)
			{
				a[i][2]=0;
			}
			for(int i=0;i<n;i++)
			{
				a[i][3]=0;
			}
	
	
	}
	else
	{
		cout<<1<<'\n';
	}
}



int main() 
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(1)
	{
		if(t==0)
		{
			break;
		}
		else
		{
			kk();
			t--;
		
		}
	}
	return 0;
}
