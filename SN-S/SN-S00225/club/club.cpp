#include <bits/stdc++.h>
using namespace std;
int x[100005],y[100005],z[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int sum=0,x1=0,y1=0,z1=0;
		cin>>m;
		for(int j=1;j<=m;j++)
		{
			cin>>x[j]>>y[j]>>z[j];
		}
		for(int j=1;j<=m;j++)
		{
			if(x1*2>=m)
			{
				x[j]=-1;
			}
			if(y1*2>=m)
			{
				y[j]=-1;
			}
			if(z1*2>=m)
			{
				z[j]=-1;
			}
			int a1=max(x[j],y[j]);
			sum+=max(a1,z[j]);
			if(x[j]>y[j]&&x[j]>z[j])
			{
				x1++;
			}
			if(y[j]>x[j]&&y[j]>z[j])
			{
				y1++;
			}
			if(z[j]>y[j]&&z[j]>x[j])
			{
				z1++;
			}
//			cout<<sum<<endl;
//			cout<<x1<<" "<<y1<<" "<<z1<<endl;
		}
		cout<<sum;
	}
	return 0;
}
//#include <bits/stdc++.h>
//using namespace std;
//int x[100005],y[100005],z[100005];
//int main()
//{
////	freopen(".in","r",stdin);
////	freopen(".out","w",stdout);
//	int n,m;
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{
//		int sum=0,x1=0,y1=0,z1=0;
//		cin>>m;
//		for(int j=0;j<m;j++)
//		{
//			cin>>x[j]>>y[j]>>z[j];
//		}
//		for(int j=m;j>=0;j--)
//		{
//			for(int k=m;k>0;k--)
//			{
//				if(x[k]>x[k-1])
//				{
//					swap(x[k],x[k-1]);
//				}
//			}
//		}
//		for(int j=m;j>=0;j--)
//		{
//			for(int k=m;k>0;k--)
//			{
//				if(y[k]>y[k-1])
//				{
//					swap(y[k],y[k-1]);
//				}
//			}
//		}
//		for(int j=m;j>=0;j--)
//		{
//			for(int k=m;k>0;k--)
//			{
//				if(z[k]>z[k-1])
//				{
//					swap(z[k],z[k-1]);
//				}
//			}
//		}
//		for(int j=0;j<m;j++)
//		{
//			if(j%3==1)
//			{
//				sum+=y[j];
//			}
//			if(j%3==2)
//			{
//				sum+=z[j];
//			}
//			if(j%3==0)
//			{
//				sum+=x[j];
//			}
//			cout<<x[j]<<" "<<y[j]<<" "<<z[j]<<endl;
//		}
////			cout<<sum<<endl;
////			cout<<x1<<" "<<y1<<" "<<z1<<endl;
//		cout<<sum;
//	}
//	return 0;
//}

