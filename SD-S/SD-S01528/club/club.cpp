#include<bits/stdc++.h>


using namespace std;
int cmp(int aaa,int bbb)
{
	return aaa<bbb;
}
int mx[100010],mx2[100010],mx3[100010];
int bj[10],bj2[10];
int bjcha[10];
int a[100010][10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	
	while(t--)
	{
		
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				mx[i]=max(a[i][j],mx[i]); 
				
			}
			if(mx[i]==a[i][1] && bj2[i]==0)
			{
				bj[1]++;
				//bj2[i]=1;
				a[i][1]=0;
				//cout<<"1"<<'\n';
			}
			if(mx[i]==a[i][2] && bj2[i]==0) 
			{
				bj[2]++;
				//bj2[i]=1;
				a[i][2]=0;
			}
			if(mx[i]==a[i][3] && bj2[i]==0) 
			{
				bj[3]++;
				//bj2[i]=1;
				a[i][3]=0;
			}
				
		}
		//for(int i=1;i<=3;i++) cout<<bj[i]<<" ";
		
		
		for(int i=1;i<=n;i++)
		{
			ans+=mx[i];
		}
		//cout<<ans<<'\n'; 
		int yu;
		for(int i=1;i<=3;i++)
		{
			if(bj[i]>n/2)
			{
				yu=i;
				cout<<bj[i]<<'\n';
				
			}
		}
		//cout<<yu<<'\n';
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(a[i][yu]==0)
				{
					mx2[i]=max(mx2[i],a[i][j]);
					//cout<<mx2[i]<<'\n'; 
				}
				
			}
			mx3[i]=mx[i]-mx2[i];
		}
		sort(mx3+1,mx3+n+1,cmp);
//		for(int i=1;i<=n;i++) 
//		{
//			
//			cout<<mx3[i]<<" ";
//		}
		int yi=0;
		if(yu!=0)
		for(int j=1;j<=n;j++)
		{
			if(mx3[j]!=0 && yi<bj[yu]-(n/2))
			{
				yi++;
				ans-=mx3[j];
				//cout<<mx3[j]<<"\n";
			}
		}
			
		cout<<ans<<'\n';
		//
		for(int i=1;i<=n;i++) 
		{
			mx[i]=0;
			mx2[i]=0;
			mx3[i]=0;
			
		}
		for(int i=1;i<=4;i++)
		{
			bj[i]=0;
			bj2[i]=0;
		}
	}

	return 0;
}

