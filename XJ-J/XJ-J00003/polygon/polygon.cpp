#include<bits/stdc++.h>
using namespace std;
int a[5005]={0};
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	if(n==1||n==2)
	{
		cout<<0;
		return 0;
	}
	
	
	if(n==3)
	{
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	int m=0;
	if(n==4)
	{
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2)
		{
			m++;
		}
		for(int i=1;i<=2;i++)
		{
			for(int j=i+1;j<=3;j++)
			{
				for(int p=j+1;p<=4;p++)
				{
					if(a[i]+a[j]+a[p]>a[p]*2)
					{
						m++;
					}
				}
			}
		}
		cout<<m;
		return 0;
	}
	
	if(n==5)
	{
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[5]*2)
		{
			m++;
		}
		for(int i=1;i<=3;i++)
		{
			for(int j=i+1;j<=4;j++)
			{
				for(int p=j+1;p<=5;p++)
				{
					if(a[i]+a[j]+a[p]>a[p]*2)
					{
						m++;
					}
				}
			}
		}
		for(int i=1;i<=2;i++)
		{
			for(int j=i+1;j<=3;j++)
			{
				for(int p=j+1;p<=4;p++)
				{
					for(int o=p+1;o<=5;o++)
					{
						if(a[i]+a[j]+a[p]+a[o]>a[o]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		cout<<m;
		return 0;
	}
		if(n==6)
	{
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>a[6]*2)
		{
			m++;
		}
		for(int i=1;i<=4;i++)
		{
			for(int j=i+1;j<=5;j++)
			{
				for(int p=j+1;p<=6;p++)
				{
					if(a[i]+a[j]+a[p]>a[p]*2)
					{
						m++;
					}
				}
			}
		}
		for(int i=1;i<=3;i++)
		{
			for(int j=i+1;j<=4;j++)
			{
				for(int p=j+1;p<=5;p++)
				{
					for(int o=p+1;o<=6;o++)
					{
						if(a[i]+a[j]+a[p]+a[o]>a[o]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		for(int i=1;i<=2;i++)
		{
			for(int j=i+1;j<=3;j++)
			{
				for(int p=j+1;p<=4;p++)
				{
					for(int o=p+1;o<=5;o++)
					{
						for(int k=o+1;k<=6;k++)
						if(a[i]+a[j]+a[p]+a[o]+a[k]>a[k]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		cout<<m;
		return 0;
	}
	if(n==7)
	{
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>a[7]*2)
		{
			m++;
		}
		for(int i=1;i<=5;i++)
		{
			for(int j=i+1;j<=6;j++)
			{
				for(int p=j+1;p<=7;p++)
				{
					if(a[i]+a[j]+a[p]>a[p]*2)
					{
						m++;
					}
				}
			}
		}
		for(int i=1;i<=4;i++)
		{
			for(int j=i+1;j<=5;j++)
			{
				for(int p=j+1;p<=6;p++)
				{
					for(int o=p+1;o<=7;o++)
					{
						if(a[i]+a[j]+a[p]+a[o]>a[o]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		for(int i=1;i<=3;i++)
		{
			for(int j=i+1;j<=4;j++)
			{
				for(int p=j+1;p<=5;p++)
				{
					for(int o=p+1;o<=6;o++)
					{
						for(int k=o+1;k<=7;k++)
						if(a[i]+a[j]+a[p]+a[o]+a[k]>a[k]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		for(int i=1;i<=2;i++)
		{
			for(int j=i+1;j<=3;j++)
			{
				for(int p=j+1;p<=4;p++)
				{
					for(int o=p+1;o<=5;o++)
					{
						for(int k=o+1;k<=6;k++)
						for(int q=k+1;q<=7;q++)
						if(a[i]+a[j]+a[p]+a[o]+a[k]+a[q]>a[q]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		cout<<m;
		return 0;
	}
	if(n==8)
	{
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>a[8]*2)
		{
			m++;
		}
		for(int i=1;i<=6;i++)
		{
			for(int j=i+1;j<=7;j++)
			{
				for(int p=j+1;p<=8;p++)
				{
					if(a[i]+a[j]+a[p]>a[p]*2)
					{
						m++;
					}
				}
			}
		}
		for(int i=1;i<=5;i++)
		{
			for(int j=i+1;j<=6;j++)
			{
				for(int p=j+1;p<=7;p++)
				{
					for(int o=p+1;o<=8;o++)
					{
						if(a[i]+a[j]+a[p]+a[o]>a[o]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		for(int i=1;i<=4;i++)
		{
			for(int j=i+1;j<=5;j++)
			{
				for(int p=j+1;p<=6;p++)
				{
					for(int o=p+1;o<=7;o++)
					{
						for(int k=o+1;k<=8;k++)
						if(a[i]+a[j]+a[p]+a[o]+a[k]>a[k]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		for(int i=1;i<=3;i++)
		{
			for(int j=i+1;j<=4;j++)
			{
				for(int p=j+1;p<=5;p++)
				{
					for(int o=p+1;o<=6;o++)
					{
						for(int k=o+1;k<=7;k++)
						for(int q=k+1;q<=8;q++)
						if(a[i]+a[j]+a[p]+a[o]+a[k]+a[q]>a[q]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		for(int i=1;i<=2;i++)
		{
			for(int j=i+1;j<=3;j++)
			{
				for(int p=j+1;p<=4;p++)
				{
					for(int o=p+1;o<=5;o++)
					{
						for(int k=o+1;k<=6;k++)
						for(int q=k+1;q<=7;q++)
						for(int w=q+1;w<=8;w++)
						if(a[i]+a[j]+a[p]+a[o]+a[k]+a[q]+a[w]>a[w]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		cout<<m;
		return 0;
	}
	if(n==9)
	{
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>a[9]*2)
		{
			m++;
		}
		for(int i=1;i<=7;i++)
		{
			for(int j=i+1;j<=8;j++)
			{
				for(int p=j+1;p<=9;p++)
				{
					if(a[i]+a[j]+a[p]>a[p]*2)
					{
						m++;
					}
				}
			}
		}
		for(int i=1;i<=6;i++)
		{
			for(int j=i+1;j<=7;j++)
			{
				for(int p=j+1;p<=8;p++)
				{
					for(int o=p+1;o<=9;o++)
					{
						if(a[i]+a[j]+a[p]+a[o]>a[o]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		for(int i=1;i<=5;i++)
		{
			for(int j=i+1;j<=6;j++)
			{
				for(int p=j+1;p<=7;p++)
				{
					for(int o=p+1;o<=8;o++)
					{
						for(int k=o+1;k<=9;k++)
						if(a[i]+a[j]+a[p]+a[o]+a[k]>a[k]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		for(int i=1;i<=4;i++)
		{
			for(int j=i+1;j<=5;j++)
			{
				for(int p=j+1;p<=6;p++)
				{
					for(int o=p+1;o<=7;o++)
					{
						for(int k=o+1;k<=8;k++)
						for(int q=k+1;q<=9;q++)
						if(a[i]+a[j]+a[p]+a[o]+a[k]+a[q]>a[q]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		for(int i=1;i<=3;i++)
		{
			for(int j=i+1;j<=4;j++)
			{
				for(int p=j+1;p<=5;p++)
				{
					for(int o=p+1;o<=6;o++)
					{
						for(int k=o+1;k<=7;k++)
						for(int q=k+1;q<=8;q++)
						for(int w=q+1;w<=9;w++)
						if(a[i]+a[j]+a[p]+a[o]+a[k]+a[q]+a[w]>a[w]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		for(int i=1;i<=2;i++)
		{
			for(int j=i+1;j<=3;j++)
			{
				for(int p=j+1;p<=4;p++)
				{
					for(int o=p+1;o<=5;o++)
					{
						for(int k=o+1;k<=6;k++)
						for(int q=k+1;q<=7;q++)
						for(int w=q+1;w<=8;w++)
						for(int e=w+1;e<=9;e++)
						if(a[i]+a[j]+a[p]+a[o]+a[k]+a[q]+a[w]+a[e]>a[e]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		cout<<m;
		return 0;
	}
	if(n==10)
	{
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>a[10]*2)
		{
			m++;
		}
		for(int i=1;i<=8;i++)
		{
			for(int j=i+1;j<=9;j++)
			{
				for(int p=j+1;p<=10;p++)
				{
					if(a[i]+a[j]+a[p]>a[p]*2)
					{
						m++;
					}
				}
			}
		}
		for(int i=1;i<=7;i++)
		{
			for(int j=i+1;j<=8;j++)
			{
				for(int p=j+1;p<=9;p++)
				{
					for(int o=p+1;o<=10;o++)
					{
						if(a[i]+a[j]+a[p]+a[o]>a[o]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		for(int i=1;i<=6;i++)
		{
			for(int j=i+1;j<=7;j++)
			{
				for(int p=j+1;p<=8;p++)
				{
					for(int o=p+1;o<=9;o++)
					{
						for(int k=o+1;k<=10;k++)
						if(a[i]+a[j]+a[p]+a[o]+a[k]>a[k]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		for(int i=1;i<=5;i++)
		{
			for(int j=i+1;j<=6;j++)
			{
				for(int p=j+1;p<=7;p++)
				{
					for(int o=p+1;o<=8;o++)
					{
						for(int k=o+1;k<=9;k++)
						for(int q=k+1;q<=10;q++)
						if(a[i]+a[j]+a[p]+a[o]+a[k]+a[q]>a[q]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		for(int i=1;i<=4;i++)
		{
			for(int j=i+1;j<=5;j++)
			{
				for(int p=j+1;p<=6;p++)
				{
					for(int o=p+1;o<=7;o++)
					{
						for(int k=o+1;k<=8;k++)
						for(int q=k+1;q<=9;q++)
						for(int w=q+1;w<=10;w++)
						if(a[i]+a[j]+a[p]+a[o]+a[k]+a[q]+a[w]>a[w]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		for(int i=1;i<=3;i++)
		{
			for(int j=i+1;j<=4;j++)
			{
				for(int p=j+1;p<=5;p++)
				{
					for(int o=p+1;o<=6;o++)
					{
						for(int k=o+1;k<=7;k++)
						for(int q=k+1;q<=8;q++)
						for(int w=q+1;w<=9;w++)
						for(int e=w+1;e<=10;e++)
						if(a[i]+a[j]+a[p]+a[o]+a[k]+a[q]+a[w]+a[e]>a[e]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		for(int i=1;i<=2;i++)
		{
			for(int j=i+1;j<=3;j++)
			{
				for(int p=j+1;p<=4;p++)
				{
					for(int o=p+1;o<=5;o++)
					{
						for(int k=o+1;k<=6;k++)
						for(int q=k+1;q<=7;q++)
						for(int w=q+1;w<=8;w++)
						for(int e=w+1;e<=9;e++)
						for(int r=e+1;r<=10;r++)
						if(a[i]+a[j]+a[p]+a[o]+a[k]+a[q]+a[w]+a[e]+a[r]>a[r]*2)
						{
							m++;
						}
					}
					
				}
			}
		}
		cout<<m;
		return 0;
	}
}
