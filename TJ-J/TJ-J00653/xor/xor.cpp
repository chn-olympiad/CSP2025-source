#include<bits/stdc++.h>
using namespace std;
int n,k;
int xorr[1005];
int a[1005];
int l,r;
vector<pair<int,int> > v;
bool cmp(pair<int,int> x,pair<int,int> y)
{
    return x.second<y.second;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        xorr[i]=xorr[i-1]^a[i];
    }
    //for(int i=1;i<=n;i++) cout<<xorr[i]<<" ";
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            /*
            cout<<i<<" "<<j<<" ";
            cout<<(xorr[j]^xorr[i-1]);
            cout<<endl;*/
            if ((xorr[j]^xorr[i-1])==k) v.push_back(make_pair(i,j));
        }
    }

    sort(v.begin(),v.end(),cmp);
    //for(int i=0;i<v.size();i++) cout<<v[i].first<<" "<<v[i].second<<endl;
    int r=v[0].second;
    int cnt=1;
    for(int i=1;i<v.size();i++)
    {
        if (v[i].first<=r) continue;
        cnt++;
        r=v[i].second;
    }
    cout<<cnt;
    return 0;
}
