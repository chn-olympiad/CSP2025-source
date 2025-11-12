#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0;
    char ch=getchar();
    while(!isdigit(ch))
    {
        ch=getchar();
    }
    while(isdigit(ch))
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
int t,n;
int a[100005][3];
vector<int> vec[3];
int main ()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=read();
    while(t--)
    {
        n=read();
        for(int i=1;i<=n;i++)
        {
            a[i][0]=read();a[i][1]=read();a[i][2]=read();
        }
        int s=0;
        vec[0].clear();vec[1].clear();vec[2].clear();
        for(int i=1;i<=n;i++)
        {
            if((a[i][0]>=a[i][1])&&(a[i][0]>=a[i][2]))
            {
                s+=a[i][0];
                vec[0].push_back(min(a[i][0]-a[i][1],a[i][0]-a[i][2]));
            }
            else if((a[i][1]>=a[i][0])&&(a[i][1]>=a[i][2]))
            {
                s+=a[i][1];
                vec[1].push_back(min(a[i][1]-a[i][0],a[i][1]-a[i][2]));
            }
            else
            {
                s+=a[i][2];
                vec[2].push_back(min(a[i][2]-a[i][0],a[i][2]-a[i][1]));
            }
        }
        if(vec[0].size()>n/2)
        {
            sort(vec[0].begin(),vec[0].end());
            for(int i=0;i<vec[0].size()-n/2;i++)
            {
                s-=vec[0][i];
            }
        }
        if(vec[1].size()>n/2)
        {
            sort(vec[1].begin(),vec[1].end());
            for(int i=0;i<vec[1].size()-n/2;i++)
            {
                s-=vec[1][i];
            }
        }
        if(vec[2].size()>n/2)
        {
            sort(vec[2].begin(),vec[2].end());
            for(int i=0;i<vec[2].size()-n/2;i++)
            {
                s-=vec[2][i];
            }
        }
        printf("%d\n",s);
    }
}