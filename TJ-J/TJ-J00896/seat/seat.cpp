#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;


int mp[12][12];
int vis[11][11];
int cj[101];
int fx[10][10]={{0,1},{1,0},{0,-1}};
int xr;
int sum=1;
bool tmp=false;
bool cmp(int a,int b)
{
    return a>b;
}
int n,m;
void func(int rix,int riy)
{
    int ssx,ssy;
    vis[rix][riy]=1;
    mp[1][1]=cj[1];
    if(cj[sum]==xr)
    {
   		cout<<ssx<<" "<<ssy;
   		tmp=true;
	}
	if(tmp=true)
	{
		return ;
	}
    for(int i=0;i<3;i++)
    {
        ssx=rix+fx[i][0];
        ssy=riy+fx[i][1];
        if(ssx>0&&ssx<=m&&ssy>0&&ssy<=n&&vis[ssx][ssy]!=1)
        {   
		    sum++;
            vis[ssx][ssy]=1;
            mp[ssx][ssy]=cj[sum];
            func(ssx,ssy);
        }
    }

    
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m*n;i++)
    {
        cin>>cj[i];
    }
    xr=cj[1];
    sort(cj+1,cj+(m*n)+1,cmp);
    func(1,1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

