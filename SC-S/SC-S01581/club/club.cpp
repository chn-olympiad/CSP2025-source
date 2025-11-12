#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100005;
int T;
int n,ans=0,cnt=0;
int f[2][3000][3000];
int club[5]={0};
struct node
{
	int a,b,c;
}p[N];
void dfs(int k,int len)
{
	//cout<<k<<" "<<club[1]<<endl;
	if(k>len)
	{
		ans=max(ans,cnt);
		return ;
	}
	if(club[1]+1<=len/2)
	{
		club[1]+=1;
		cnt+=p[k].a;
	    dfs(k+1,len);
	    cnt-=p[k].a;
	    club[1]-=1;
	}
	if(club[2]+1<=len/2)
	{
		club[2]+=1;
		cnt+=p[k].b;
	    dfs(k+1,len);
	    cnt-=p[k].b;
	    club[2]-=1;
	}
	if(club[3]+1<=len/2)
	{
		club[3]+=1;
		cnt+=p[k].c;
	    dfs(k+1,len);
	    cnt-=p[k].c;
	    club[3]-=1;
	}
	return ;
}
bool cmp(node x,node y)
{
	return x.a>y.a;
}
int main()
{    
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
    	ans=0;
    	cnt=0;
    	club[1]=0;club[2]=0;club[3]=0;
    	int a=0,b=0,c=0,f1=0,f2=0;
    	cin>>n;
    	for(int i=1;i<=n;i++)
    	{
    		cin>>p[i].a>>p[i].b>>p[i].c;
    		if(p[i].b!=0||p[i].c!=0) f1=1; 
		}
		if(n<=10)
		{
			dfs(1,n);
	        cout<<ans<<"\n";
		}
		else if(f1==0)
		{
			sort(p+1,p+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=p[i].a;
			}
			cout<<ans<<"\n";
		}
		else if(f2==0)
		{
			//sort(p+1,p+n+1,cmp2);
		}
		else
		{
			memset(f,0,sizeof(f));
			for(int l=1;l<=n;l++)
			{
				for(int i=0;i<=min(l,n/2);i++)
				{
					for(int j=0;j<=min(l,n/2)&&(i+j)<=n;j++)
					{
						if(n-i-j>n/2) continue;
						if(i!=0) f[1][i][j]=max(f[1][i][j],f[0][i-1][j]+p[i].a);
						if(j!=0) f[1][i][j]=max(f[1][i][j],f[0][i][j-1]+p[i].b);
						f[1][i][j]=max(f[1][i][j],f[0][i][j]+p[i].c);
					}
				}
				for(int i=0;i<=min(l,n/2);i++)
				{
					for(int j=0;j<=min(l,n/2)&&i+j<=n;j++)
					{
						if(n-i-j>n/2) continue;
						f[0][i][j]=f[1][i][j];
					}
				}
			}
			for(int i=0;i<=n/2;i++)
			{
				for(int j=0;j<=n/2&&i+j<=n;j++)
				{
					if(n-i-j>n/2) continue;
					ans=max(ans,f[0][i][j]);
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
} 