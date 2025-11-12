#include<bits/stdc++.h>
using namespace std;
struct f
{
    int a,b;
};
int n,m,k,a[1111111],d,a,b,l[1111111];
vector<f> c[1111111];
priority_queue<int> p;
void dis(int x)
{
    p.push(x);
    while(p.size()!=0)
    {
        int y=p.top();
        p.pop();
        for(int i=0;i<v[y].size();i++)
        {
            int z=v[y][i].a,zz=v[y][i].b;
            if(l[z]>l[y]+zz)
            {
                l[z]=l[y]+zz;
                p.push(z);
            }
        }
    }
}
int tj()
{

}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>d>>a>>b;
        c[d].push_back((f){a,b});
        c[a].push_back((f){d,b});
    }
    for(int i=1;i<=k;i++)
    {
        cin>>d;
        for(int j=1;j<=n;j++)
        {
            if(j==i)
                continue;
            cin>>a;
            c[i].push_back((f){j,a});
            c[j].push_back((f){i,a});
        }
    }
    memset(l,0x3f,sizeof(l));
    l[1]=0;
    dis(1);
    return 0;
}
