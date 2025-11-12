#include<bits/stdc++.h>
using namespace std;
int n,ans;
struct node
{
	int m1,m2,m3;
}a[100010];
vector<int>club1,club2,club3;
int chg[100010];
struct node2
{
	int id,x;
}wr[100010];
bool cmp(node2 x,node2 y)
{
	if(x.x>y.x)return 1;
	return 0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;cin>>t;
	while(t--)
	{
		club1.clear();club2.clear();club3.clear();
		for(int i=1;i<=n;i++){chg[i]=0;wr[i-1]={0,0};a[i]={0,0,0};}
		
		ans=0;
		//
		cin>>n;
		int half=n/2;
		for(int i=1;i<=n;i++)cin>>a[i].m1>>a[i].m2>>a[i].m3;
		for(int i=1;i<=n;i++)
		{
			if(a[i].m1>=a[i].m2&&a[i].m1>=a[i].m3)
			{
				club1.push_back(i);
				ans+=a[i].m1;
				chg[i]=max(a[i].m2-a[i].m1,a[i].m3-a[i].m1);
			}
			else if(a[i].m2>=a[i].m3)
			{
				club2.push_back(i);
				ans+=a[i].m2;
				chg[i]=max(a[i].m1-a[i].m2,a[i].m3-a[i].m2);
			}
			else 
			{
				club3.push_back(i);
				ans+=a[i].m3;
				chg[i]=max(a[i].m1-a[i].m3,a[i].m2-a[i].m3);
			}
			
		}
		/*
		for(int i=0;i<club1.size();i++)cout<<club1[i]<<" ";
		cout<<endl;
		for(int i=0;i<club2.size();i++)cout<<club2[i]<<" ";
		cout<<endl;
		for(int i=0;i<club3.size();i++)cout<<club3[i]<<" ";
		cout<<endl;
		for(int i=1;i<=n;i++)cout<<chg[i]<<" ";
		cout<<endl;
		*/
		if(club1.size()>half)//club为编号数组 
		{
			for(int i=0;i<club1.size();i++)
			{
				wr[i].id=club1[i];
				wr[i].x=chg[club1[i]];
				//printf("%d %d\n",wr[i].id,wr[i].x);
			}
			 
			sort(wr,wr+club1.size(),cmp);
			//for(int i=0;i<club1.size();i++)printf("%d %d\n",wr[i].id,wr[i].x);
			for(int i=0;i<club1.size()-half;i++)
				ans+=wr[i].x;
		}
		if(club2.size()>half)//club为编号数组 
		{
			for(int i=0;i<club2.size();i++)
			{
				wr[i].id=club2[i];
				wr[i].x=chg[club2[i]];
				//printf("%d %d\n",wr[i].id,wr[i].x);
			}
			 
			sort(wr,wr+club2.size(),cmp);
			//for(int i=0;i<club2.size();i++)printf("%d %d\n",wr[i].id,wr[i].x);
			for(int i=0;i<club2.size()-half;i++)
				ans+=wr[i].x;
		}
		if(club3.size()>half)//club为编号数组 
		{
			for(int i=0;i<club3.size();i++)
			{
				wr[i].id=club3[i];
				wr[i].x=chg[club3[i]];
				//printf("%d %d\n",wr[i].id,wr[i].x);
			}
			 
			sort(wr,wr+club3.size(),cmp);
			//for(int i=0;i<club3.size();i++)printf("%d %d\n",wr[i].id,wr[i].x);
			for(int i=0;i<club3.size()-half;i++)
				ans+=wr[i].x;
		}
		cout<<ans<<endl;
	}
	return 0;
}
