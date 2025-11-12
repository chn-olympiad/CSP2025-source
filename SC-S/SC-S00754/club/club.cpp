#include<bits/stdc++.h>
using namespace std;
int n,q,w,e,num,max_num=0;
struct point
{
    int x;
    int y;
    int z;
};
vector<point>A;
void dfs(int k)
{
    if(q>n/2 || w>n/2 || e>n/2) return;
    else if(k==n)
    {
        max_num=max(max_num,num);
        return;
    }
    for(int j=0;j<3;j++)
    {
        if(j==0)
        {
            q++;
            num+=A[k].x;
            dfs(k+1);
            q--;
            num-=A[k].x;
        }
        else if(j==1)
        {
            w++;
            num+=A[k].y;
            dfs(k+1);
            w--;
            num-=A[k].y;
        }
        else if(j==2)
        {
            e++;
            num+=A[k].z;
            dfs(k+1);
            e--;
            num-=A[k].z;
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--)
    {
        cin>>n;
        max_num=0;
        A.resize(n);
        for(int i=0;i<n;i++) cin>>A[i].x>>A[i].y>>A[i].z;
        q=0;
        w=0;
        e=0;
        num=0;
        dfs(0);
        cout<<max_num<<endl;
    }
    return 0;
}