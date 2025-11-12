//胡浩然SN-S00598西安市曲江第一中学
#include<bits/stdc++.h>
using namespace std;
int t,n,a[10086][5],ans,e[10086],zy[10086][5],ls,c[5];;
void jc(int d)
{
	int cs=d;
	if(c[cs]>n/2)
	{
		int min=1;
	for(int i=2;i<=n;i++)
		{
			if(zy[i][1]==d&&a[i][cs]<a[min][cs])
			{
				min=i;
			}
		}
	zy[min][1]=zy[min][2];
	zy[min][2]=zy[min][3];
	zy[min][3]=cs;
		e[min]=zy[min][1];
		c[cs]--;
		jc(cs);
	}
		if(cs>=3&&c[cs]<=n/2)
	return ;
	cs++;
	jc(cs);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		c[5]={ };
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		for(int j=1;j<=n;j++){
			zy[j][1]=1;
			zy[j][2]=2;
			zy[j][3]=3;
		}
				for(int j=1;j<=n;j++)
			{
					for(int k=1;k<=2;k++)
		{
				if(a[j][zy[j][1]]<a[j][zy[j][2]])
		{	ls=zy[j][1];
			zy[j][1]=zy[j][2];
			zy[j][2]=ls;
		}
			if(a[j][zy[j][2]]<a[j][zy[j][3]])
		{	ls=zy[j][2];
			zy[j][2]=zy[j][3];
			zy[j][3]=ls;
		}		
}	}
			
			for(int j=1;j<=n;j++){
				e[j]=zy[j][1];
				c[zy[j][1]]++;
			}
			jc(0);
				for(int j=1;j<=n;j++){
				ans=ans+a[j][zy[j][1]];
			}
			cout<<ans<<endl;
	}
	return 0;
} 
