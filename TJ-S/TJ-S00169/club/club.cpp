//n,t,i,d1,d2,d3,number,q,num1,m1,num2,m2,num3,m3,pj1,pj2,pj3,c1,c2,c3 
//a[100010],b[100010],c[100010],d[100010]  
#include<bits/stdc++.h>
using namespace std;
int t,n,ans;//数据组数，新成员的数量 
struct student
{
	int number,d1,d2,d3;//学生编号，学生对1,2,3各部门的满意度	
	bool q;//学生的状态(已加入、未加入) 
	int max1=0;
} a[100010];
struct one//第一部门
{
	int num1,m1; 
}b[100010];
struct two//第二部门
{
	int num2,m2; 
}c[100010];
struct three//第三部门
{
	int num3,m3; 
}d[100010];
int cmp1(one aa,one bb)
{
	return aa.m1>bb.m1;	
} 
int cmp2(two aa,two bb)
{
	return aa.m2>bb.m2;	
} 
int cmp3(three aa,three bb)
{
	return aa.m3>bb.m3;	
} 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int pj1=0,pj2=0,pj3=0;
	while(t--)//执行t次 
	{
		ans=0;
		cin>>n;
		int num=n/2;//每个部门最多能去num个人
		for(int i=1,z=1;i<=n;i++,z++)//输入满意度 
		{
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			a[i].max1=max(a[i].d1,max(a[i].d2,a[i].d3));		
			a[i].number=i;
			b[z].m1=a[i].d1,b[z].num1=i,pj1+=a[i].d1;
			c[z].m2=a[i].d2,c[z].num2=i,pj2+=a[i].d2;
			d[z].m3=a[i].d3,d[z].num3=i,pj3+=a[i].d3;
		}
		pj1/=n,pj2/=n,pj3/=n;
		sort(b+1,b+1+n,cmp1);//各部门分别排序	
		sort(c+1,c+1+n,cmp2);
		sort(d+1,d+1+n,cmp3);
		/*int c1=0,c2=0,c3=0;
		if(max(pj1,max(pj2,pj3))==pj1)//从1开始 
		{
			for(int i=1;i<=n/2;i++) c1+=b[i];
			if(pj2>pj3)
			{
				for(int j=1,j2=0;;j++)
				{
					if(a[c[i].num2]==0)
					{
						j2++;
						c2+=c[i];
					}
				}
			}
		}
		if(max(pj1,max(pj2,pj3))==pj2)//从2开始 
		{
			
		}
		if(max(pj1,max(pj2,pj3))==pj3)//从3开始 
		{
			
		}*/
		for(int i=1;i<=n;i++)
		{
			ans+=a[i].max1;
		}
		cout<<ans<<endl;
	} 
	
	return 0;
}
