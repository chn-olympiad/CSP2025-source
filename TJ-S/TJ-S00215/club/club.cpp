#include <iostream>
using namespace std;
int n,t,x[1000005][5];
int xa,xb,xc,answ;
int pd()
{
	int moss=0,poss=0;
	int xm=0;
	int xz,yz;
	for (int i=1;i<=t;i++)
	{
		for (int j=1;j<=3;j++)
		{
			if (x[i][j]>=moss)
			{
				moss=x[i][j];
				xz=i;
				yz=j;	
		    }
	    }
	}
	if (yz==1)
	{
    	if (xa<t/2)
		{
			answ+=moss;
			xa++;
			for (int z=1;z<=3;z++)
			{
				x[xz][z]=0;
			}
			return 0;
		}
	    else
	    {
		    x[xz][yz]=0;
		    pd();
	    }
	}
	else if (yz==2)
	{
	    if (xb<t/2)
	    {
			answ+=moss;
			xb++;
			for (int z=1;z<=3;z++)
			{
				x[xz][z]=0;
			}
			return 0;
		}
	    else
	    {
		    x[xz][yz]=0;
			pd();
		}
	}
	else
	{
		if (xc<t/2)
		{
			answ+=moss;
		    xc++;
			for (int z=1;z<=3;z++)
			{
				x[xz][z]=0;
			}
			return 0;
		}
		else
		{
			x[xz][yz]=0;
			pd();
		}
	}
}


int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout) ;
	cin>>n;
	for (int q=1;q<=n;q++)
	{
		cin>>t;
		for (int i=1;i<=t;i++)
		{
			cin>>x[i][1]>>x[i][2]>>x[i][3];	
		}
	    for (int i=1;i<=t;i++)
	    {
	    	pd();
		}
		cout<<answ<<endl;
		xa=0,xb=0,xc=0,answ=0;
		
		
	}
	
	return 0;
}
