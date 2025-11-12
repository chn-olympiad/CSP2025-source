#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,cont[4],a[100005],b[100005],c[100005],cnt;
void dfs(int x,int tal)
{
	if(x>n)
	{
		cnt=max(cnt,tal);
		return;
	}
	if(cont[1]<n/2)
	{
		cont[1]++;
		dfs(x+1,tal+a[x+1]);
		cont[1]--;
	}
	if(cont[2]<n/2)
	{
		cont[2]++;
		dfs(x+1,tal+b[x+1]);
		cont[2]--;
	}
	if(cont[3]<n/2)
	{
		cont[3]++;
		dfs(x+1,tal+c[x+1]);
		cont[3]--;
	}
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
    while(t--)
    {
        cin>>n;
        cnt=0;
        memset(cont,0,sizeof(cont));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        dfs(0,0);
        cout<<cnt<<endl;
    }
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
