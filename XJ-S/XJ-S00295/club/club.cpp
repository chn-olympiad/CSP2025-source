#include<bits/stdc++.h>
using namespace std;
bool sid(int n,int m)
{
	return m<n;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a;
	cin>>a;
	int b[101][101]={0};
	for(int i=0;i<a;i++)
	{
		int z;
		cin>>z;
		for(int j=0;j<z;j++)
		{
			cin>>b[j][0];
			cin>>b[j][1];
			cin>>b[j][2];
		}
		int ha[10001]={0};
		int hb[10001]={0};
		int hc[10001]={0};
		for(int j=0;j<z;j++)
		{
			ha[j]=b[j][0];
			hb[j]=b[j][1];
			hc[j]=b[j][2];
		}
		int zz=z%3;
		if(zz==1)
		{
			int a2=z/3;
			int a3=z/3+1;
			int sum1=0;
			int sum2=0;
			int sum3=0;
			sort(ha,ha+z,sid);
			sort(hb,hb+z,sid);
			sort(hc,hc+z,sid);
			for(int f=0;f<a3;f++)
			{
				sum1+=ha[f];
			}
			for(int f=0;f<a2;f++)
			{
				sum1+=hb[f];
			}
			for(int f=0;f<a2;f++)
			{
				sum1+=hc[f];
			}
			for(int f=0;f<a2;f++)
			{
				sum2+=ha[f];
			}
			for(int f=0;f<a3;f++)
			{
				sum2+=hb[f];
			}
			for(int f=0;f<a2;f++)
			{
				sum2+=hc[f];
			}
			for(int f=0;f<a2;f++)
			{
				sum3+=ha[f];
			}
			for(int f=0;f<a2;f++)
			{
				sum3+=hb[f];
			}
			for(int f=0;f<a3;f++)
			{
				sum3+=hc[f];
			}
			int max=sum1;
			if(sum2>max)
			{
				max=sum2;
			}
			if(sum3>max)
			{
				max=sum3;
			}
			cout<<max<<endl;
		}
		else if(zz==2)
		{
			int a2=z/3;
			int a3=z/3+1;
			int sum1=0;
			int sum2=0;
			int sum3=0;
			sort(ha,ha+z,sid);
			sort(hb,hb+z,sid);
			sort(hc,hc+z,sid);
			for(int f=0;f<a3;f++)
			{
				sum1+=ha[f];
			}
			for(int f=0;f<a3;f++)
			{
				sum1+=hb[f];
			}
			for(int f=0;f<a2;f++)
			{
				sum1+=hc[f];
			}
			for(int f=0;f<a2;f++)
			{
				sum2+=ha[f];
			}
			for(int f=0;f<a3;f++)
			{
				sum2+=hb[f];
			}
			for(int f=0;f<a2;f++)
			{
				sum2+=hc[f];
			}
			for(int f=0;f<a3;f++)
			{
				sum3+=ha[f];
			}
			for(int f=0;f<a2;f++)
			{
				sum3+=hb[f];
			}
			for(int f=0;f<a2;f++)
			{
				sum3+=hc[f];
			}
			int max=sum1;
			if(sum2>max)
			{
				max=sum2;
			}
			if(sum3>max)
			{
				max=sum3;
			}
			cout<<max<<endl;
		}
		else if(zz==0)
		{
			int a2=z/3;
			int sum1=0;
			int sum2=0;
			int sum3=0;
			sort(ha,ha+z,sid);
			sort(hb,hb+z,sid);
			sort(hc,hc+z,sid);
			for(int f=0;f<a2;f++)
			{
				sum1+=ha[f];
			}
			for(int f=0;f<a2;f++)
			{
				sum1+=hb[f];
			}
			for(int f=0;f<a2;f++)
			{
				sum1+=hc[f];
			}
			
			for(int f=0;f<a2;f++)
			{
				sum2+=ha[f];
			}
			for(int f=0;f<a2;f++)
			{
				sum2+=hb[f];
			}
			for(int f=0;f<a2;f++)
			{
				sum2+=hc[f];
			}
			
			for(int f=0;f<a2;f++)
			{
				sum3+=ha[f];
			}
			for(int f=0;f<a2;f++)
			{
				sum3+=hb[f];
			}
			for(int f=0;f<a2;f++)
			{
				sum3+=hc[f];
			}
			int max=sum1;
			if(sum2>max)
			{
				max=sum2;
			}
			if(sum3>max)
			{
				max=sum3;
			}
			cout<<max<<endl;
		}
	}
	return 0;
} 
