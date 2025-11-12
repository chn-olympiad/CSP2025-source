#include<bits/stdc++.h>
using namespace std;
struct jc{
	long long d1,d2,d3,he;
};
long long a,b,dd[10],sum=0,c[100][100];
bool cmp(jc x,jc y)
{
	return x.d1>y.d1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	cin>>a;
	for(int i=0;i<a;i++)
	{
		sum=0;
		int aa=0,bb=0,cc=0;
		jc jb[10005];
		cin>>b;
		if(b==2)
		{
			for(int j=0;j<2;j++)
			{
				cin>>c[j][0]>>c[j][1]>>c[j][2];
			}
			int ji=-1;
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<3;k++)
				{
					if(j==k) continue;
					if(c[0][j]+c[1][k]>=ji)
					{
						ji=c[0][j]+c[1][k];
					}
				}
			}
			cout<<ji<<endl;
		}
		else if(b==100000)
		{
			long long aaa[100005];
			for(int j=0;j<100000;j++)
			{
				cin>>dd[0]>>dd[1]>>dd[2];
				if(dd[0]!=0) aaa[j]=dd[0];
				else if(dd[1]!=0) aaa[j]=dd[1];
				else if(dd[2]!=0) aaa[j]=dd[2];
			}
			sort(aaa,aaa+100000);
			for(int j=100000-1;j>=50000;j++)
			{
				sum+=aaa[j];
			}
			cout<<sum<<endl;
		}
	}
	
	return 0;
}
