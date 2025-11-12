#include<bits/stdc++.h>
using namespace std;
int n,m;
string o="",g="";
struct point
{
    string q;
    string p;
};
vector<point>A;
vector<bool>visited;
vector<point>B;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    A.resize(n);
    for(int i=0;i<n;i++)
        cin>>A[i].q>>A[i].p;
    while(m--)
    {
        int num=0;
        visited.resize(n,false);
        B.resize(0);
        string a,b;cin>>a>>b;
        if(a.size()!=b.size())
        {
            cout<<0;
            continue;
        }
        for(int i=0;i<n;i++)
        {
            if(a==A[i].q && A[i].p==b)
            {
                visited[i]=true;
                num++;
            }
        }
        int x=0,y=a.size()-1;
        for(;x<a.size();x++)
        {
            if(a[x]!=b[x])
            {
                break;
            }
        }
        for(;y>=0;y--)
        {
            if(a[y]!=b[y])
            {
                break;
            }
        }
        if(x==0 && y==a.size()-1)
        {
            cout<<num;
            continue;
        }
        for(int i=1;i<a.size();i++)
        {
            for(int j=0;j<a.size()-i;j++)
            {
                if(j>x && x<=y) break;
                for(int l=0;l<i;l++)
                {
                    o+=a[j+l];
                    g+=b[j+l];
                }
                B.push_back({o,g});
                o="";
                g="";
            }
        }
        for(point k:B)
        {
            for(int i=0;i<n;i++)
            {
                if(k.q==A[i].q && k.p==A[i].p) num++;
            }
        }
        cout<<num<<endl;
    }
    return 0;
}