#include<bits/stdc++.h>
using namespace std;
int n,k;
long long ans;
int a[500005];
struct node
{
    int l,r;
};
bool cmp(node x,node y)
{
    return x.r<y.r;
}
vector<node> p;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    bool flag=1;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)flag=0;
        a[i]^=a[i-1];
    }
    if(k==1&&flag)
    {
        cout<<n;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if((a[j]^a[i-1])==k)
            {
                //cout<<i<<" "<<j<<" "<<(a[j]^a[i-1])<<endl;
                p.push_back({i,j});
            }
        }
    }
    sort(p.begin(),p.end(),cmp);
    int last=0;
    for(int i=0;i<p.size();i++)
    {
        if(p[i].l>last)
        {
            ans++;
            last=p[i].r;
        }
    }
    cout<<ans;
    return 0;
}
