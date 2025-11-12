#include<bits/stdc++.h>
using namespace std;
int T,n,m=3;
long long int a[100005][4],ans;
struct S{
    int a,c;
    long long int b,d;
};
vector<S>t[4];
inline void swap(S &A,S &B)
{
    swap(A.a,B.a);
    swap(A.b,B.b);
    swap(A.c,B.c);
    swap(A.d,B.d);
}
inline void PUSH(int b,long long int x)
{
    S c[4];
    for(int j=1;j<=m;j++)
    {
        c[j].b=a[b][j];
        c[j].a=j;
        c[j].c=0;
        c[j].d=0;
    }
    if(c[1].b<c[2].b){swap(c[1],c[2]);}if(c[1].b<c[3].b){swap(c[1],c[3]);}if(c[2].b<c[3].b){swap(c[2],c[3]);}
    S d=c[x];
    d.d=c[x].b-c[x+1].b;
    long long int l=0,r=t[d.a].size();
    while(l<r)
    {
        long long int mid=l+r>>1;
        if(t[d.a][mid].d>d.d)
            l=mid+1;
        else
            r=mid;
    }
    S p;
    p.a=b;
    p.b=d.b;
    p.c=x;
    p.d=d.d;
    t[d.a].insert(t[d.a].begin()+l,p);
    if(t[d.a].size()>n/2)
    {
        S s=t[d.a][t[d.a].size()-1];
        t[d.a].pop_back();
        PUSH(s.a,s.c+1);
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        ans=0;
        for(int j=1;j<=m;j++)
            t[j].clear();
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        for(int i=1;i<=n;i++)
        {
            PUSH(i,1);
        }
        for(int j=1;j<=m;j++)
        {
            for(int i=0;i<t[j].size();i++)
            {
                ans+=t[j][i].b;
            }
        }
        cout<<ans<<"\n";
    }
	return 0;
}