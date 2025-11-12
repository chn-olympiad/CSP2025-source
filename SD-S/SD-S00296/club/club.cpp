#include<bits/stdc++.h>
using namespace std;
int t,n,a[153][33];//定义t组数据，n为每组中的人数，a为满意度数组 
int h,x,y,z,sum,m1,m2;//h是每h个（30行）存一组数据，sum计满意和，m1为满意度最大的组号 ,m2第二大 
int m[32];//存储每个n的值 
int zuida(int u,int v,int w)//求一人在三个组中的最大满意度的组 
{
	if((u==max(u,v))&&(u==max(u,w)))
	{
		return 1;
	}
	else if((v==max(u,v))&&(v==max(v,w)))
	{
		return 2;
	}
	else
	{
		return 3;
	}
}
int dierda(int e,int f,int g)//求一人在三个组中的第二满意度的组 
{
	if(((e>f)&&(f>g))||((g>f)&&(f>e)))
	{
		return 2;
	}
	else if(((f>e)&&(e>=g))||((g>e)&&(e>f)))
	{
		return 1;
	}
	else if(((e>g)&&(g>f))||((f>g)&&(g>e)))
	{
		return 3;
	}
	else if((e>f)&&(f==g))
	{
		return 2;
	}
	else if((f>e)&&(e==g))
	{
		return 1;
	}
	else if((g>e)&&(e==f))
	{
		return 1;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)//输入，因为只要n<=30的点， 
	{
		cin>>n;
		m[k]=n;
		for(int i=1;i<=n;i++)//所以 每完成一组输入将h+30，继续存 
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i+h][j];
			}
		}
		h+=30;
	}
	int zu[4];//记录这个人对于3个组满意度最大是哪个，决定分派到哪个组 
	int erzu[4];
	h=0;
	for(int j=1;j<=t;j++)
	{
		sum=0;
		for(int ii=0;ii<=3;ii++)
		{
			zu[ii]=0;
		}
		for(int iii=0;iii<=3;iii++)
		{
			erzu[iii]=0;
		}
		for(int i=1;i<=m[j];i++)
		{
			x=a[i+h][1];
			y=a[i+h][2];
			z=a[i+h][3];
			m1=zuida(x,y,z);//最大满意度的组号  
			zu[m1]+=1;//当组人数+ 
			sum+=a[i+h][m1];//满意度之和+
		}
		if((zu[1]<=m[j]/2)&&(zu[2]<=m[j]/2)&&(zu[3]<=m[j]/2))//判断人数是否符合要求 
		{
			cout<<sum<<endl;//输出 
		}
		else
		{
			int p=0,cha[102]={0};//p为多出来的人数，cha数组存储每人最大和第二的差值 
			if(zu[1]>m[j]/2)//1组多 
			{
				p=zu[1]-m[j]/2;//多出来的人 
				for(int o=1;o<=m[j];o++)//m[j]为该组数据的人数n 
				{
					x=a[o+h][1];
					y=a[o+h][2];
					z=a[o+h][3];
					m1=zuida(x,y,z);//最大满意度的组号
					m2=dierda(x,y,z);//第二大组号
					cha[o]=a[o+h][1]-a[o+h][m2];
				}
				int aaa=99999,bbb;//aaa为最小差，(bbb为最小差的组第二大所对应的组号?)
				for(int r=1;r<=n;r++)
				{
					if((cha[r]<aaa)&&(cha[r]>=0))
					{
						aaa=cha[r];
						bbb=m2;
					}
				}
				sum-=aaa;
				zu[1]--;
				zu[m2]++;
				p--;
				if(p<=0)
				{
					cout<<sum<<endl;
				}
			}
			else if(zu[2]>m[j]/2)
			{
				p=zu[2]-m[j]/2;//多出来的人 
				for(int o=1;o<=m[j];o++)//m[j]为该组数据的人数n 
				{
					x=a[o+h][1];
					y=a[o+h][2];
					z=a[o+h][3];
					m1=zuida(x,y,z);//最大满意度的组号
					m2=dierda(x,y,z);//第二大组号
					cha[o]=a[o+h][2]-a[o+h][m2];
				}
				int aaa=99999,bbb;//aaa为最小差，(bbb为最小差的组第二大所对应的组号)
				for(int r=1;r<=n;r++)
				{
					if((cha[r]<aaa)&&(cha[r]>=0))
					{
						aaa=cha[r];
						bbb=m2;
					}
				}
				sum-=aaa;
				zu[2]--;
				zu[m2]++;
				p--;
				if(p<=0)
				{
					cout<<sum<<endl;
				}
			}
			else if(zu[3]>m[j]/2)
			{
				p=zu[3]-m[j]/2;//多出来的人 
				for(int o=1;o<=m[j];o++)//m[j]为该组数据的人数n 
				{
					x=a[o+h][1];
					y=a[o+h][2];
					z=a[o+h][3];
					m1=zuida(x,y,z);//最大满意度的组号
					m2=dierda(x,y,z);//第二大组号
					cha[o]=a[o+h][3]-a[o+h][m2];
				}
				int aaa=99999,bbb;//aaa为最小差，(bbb为最小差的组第二大所对应的组号?)
				for(int r=1;r<=n;r++)
				{
					if((cha[r]<aaa)&&(cha[r]>=0))
					{
						aaa=cha[r];
						bbb=m2;
					}
				}
				sum-=aaa;
				zu[3]--;
				zu[m2]++;
				p--;
				if(p<=0)
				{
					cout<<sum<<endl;
				}
			}
		}
		h+=30;
	}
	return 0;
}
