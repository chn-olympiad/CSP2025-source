#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat,out","w",stdout);
	int n,m,t=1,z,ben,h,g=0,mi=1,ni=1;
	int a[]={};
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(t==1)
		{
			ben=z;
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		for(int o=1;o<=n*m;o++)
		{
			if(a[i]>a[o])
			{
				h=a[o];
				a[o]=a[i];
				a[i]=h;
        	}	
    	}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(ben!=a[i])
		{
			g++;
		}
		else
		{
			break;
		}
	}
	for(int u=0;u<g;u++){
	
		if(mi%2==0)
		{
			ni+=1;
			if(ni==n)
			{
				m+=1;
			}
		}
		if(mi%2==1)
		{
			ni-=1;
			if(ni==1)
			{
				mi+=1;
			}
		}
		
	}
	cout<<ni<<mi;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
