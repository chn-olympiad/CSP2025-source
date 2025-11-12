//SN-S00776 马启源 西安市曲江第一中学

#include<bits/stdc++.h>

using namespace std;

int t;
int q1[100005]={},q2[100005]={},q3[100005]={};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	
	for(int i=0;i<t;i++)
	{
		int n;
		int u1,u2,u3;
		cin>>n;
		
		int a[100005][3]={0};
		for(int z=0;z<n;z++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[z][j];
			}
		}
		sort(q2,q2+n,greater<int>());
		sort(q1,q1+n,greater<int>());
		sort(q3,q3+n,greater<int>());
		for(int k=0;k<n;k++)
		{
			q1[k]=a[k][0];
			q2[k]=a[k][1];
			q3[k]=a[k][2];
		}
		for(int z=0;z<n/2;z++)
		{
			u1+=q1[z];
			u2+=q2[z];
			u3+=q3[z];
		}
		int xxx=max(u1,u2);
		int yyy=max(u3,u2);
		int zzz=max(xxx,yyy);
		if(zzz==u1)
		{
			cout<<zzz+q2[0]+q3[0]<<endl;
		}
		else if(zzz==u2)
		{
			cout<<zzz+q1[0]+q3[0]<<endl;
		}
		else
		{
			cout<<zzz+q2[0]+q1[0]<<endl;
		}
	}
	
	return 0;
 } 
