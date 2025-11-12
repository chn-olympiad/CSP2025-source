//王瑞泽 SN-S00514 西安铁一中滨河高级中学 
#include<bits/stdc++.h>
using namespace std;
int t;
int a[3][100100];
pair<int,int>  th[3],q[3][100100];
bool cmp(pair<int,int> l, pair<int,int> r){
	return l.first>r.first;
}
int main(){
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
 	cin>>t;
 	for(int k=1;k<=t;k++){
	    int n,ans=0,d[3]={0};
 		cin>>n;
 		for(int i=1;i<=n;i++)
 		{
		  for(int j=0;j<3;j++)
		  {
		  	int x;
		  	cin>>x;
			a[j][i]=x;
		   }  
		}
		for(int i=1;i<=n;i++)
		{
			int x=max(a[0][i],max(a[1][i],a[2][i])),y,uny[2]={0,0};
			if(a[0][i]==x)
			{
				y=0;
				uny[0]=1;
				uny[1]=2;
			 } 
			if(a[1][i]==x)
			{ 
			 	y=1;
				uny[0]=0;
				uny[1]=2;
			 }
			if(a[2][i]==x)
			{
				y=2;
				uny[0]=0;
				uny[1]=1;
			 } 
			ans+=x;
			d[y]++;
    		for(int j=0;j<=2;j++)
    		{
				if(j!=y)
				{
				q[j][i]={a[j][i],i};
				sort(q[j]+1,q[j]+i+1,cmp);
				}	
			}
    		if(d[y]>n/2){
    			ans-=x;
    			d[y]--;
    			for(int j=0;j<=2;j++)
    			{
					if(j!=y&&q[j][1].first+x>a[y][q[j][1].second])
					{
					    th[j+1]={q[j][1].first+x,j};
					    
					    
					}	
				}
				sort(th+1,th+4,cmp);
				if(th[1].first>0)
				{
				    ans-=a[y][q[th[1].second][1].second];
					q[y][i]={a[y][q[th[1].second][1].second],q[th[1].second][1].second};
					d[th[1].second]++;
				    ans+=th[1].first;
				    q[th[1].second][1]={0,0};
				}
				else
				{
					int xx=max(a[uny[0]][i],a[uny[1]][i]),yy,yyy;
					ans+=xx;
					for(int j=0;i<=2;j++) 
					{
						if(a[j][i]==xx&&j!=y) yy=j;
					}
					for(int j=0;i<=2;j++) 
					{
						if(j!=yy&&j!=y) yyy=j;
					}
					q[y][i]={a[y][i],i};
					q[yyy][i]={a[yyy][i],i};
					d[yy]++;
				}	    
				sort(q[0]+1,q[0]+i+1,cmp);
				sort(q[1]+1,q[1]+i+1,cmp);
				sort(q[2]+1,q[2]+i+1,cmp);
			}	
		}
		cout<<ans<<endl;
	}
 	return 0;
} 
