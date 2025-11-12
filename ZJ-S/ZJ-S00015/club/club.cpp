#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
int a[maxn],b[maxn],c[maxn];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        long long ans=0;
        int ca=0,cb=0,cc=0;
        vector<int>ofa,ofb,ofc;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i]>>b[i]>>c[i];
            if(a[i]>=b[i]&&a[i]>=c[i])
            {
                ca++;
                ans+=a[i];
                if(b[i]>=c[i])
                {
                    ofa.push_back(a[i]-b[i]);
                }
                else
                {
                    ofa.push_back(a[i]-c[i]);
                }
            }
            else if(b[i]>=a[i]&&b[i]>=c[i])
            {
                cb++;
                ans+=b[i];
                if(a[i]>=c[i])
                {
                    ofb.push_back(b[i]-a[i]);
                }
                else
                {
                    ofb.push_back(b[i]-c[i]);
                }
            }
            else
            {
                cc++;
                ans+=c[i];
                if(a[i]>=b[i])
                {
                    ofc.push_back(c[i]-a[i]);
                }
                else
                {
                    ofc.push_back(c[i]-b[i]);
                }
            }
        }
        // cerr<<ca<<' '<<cb<<' '<<cc<<'\n';
        // for(auto A:ofa)
        // cerr<<A<<' ';cerr<<'\n';
        // for(auto B:ofb)
        // cerr<<B<<' ';cerr<<'\n';
        // for(auto C:ofc)
        // cerr<<C<<' ';cerr<<'\n';
        int n2=n/2;
        if(ca<=n2&&cb<=n2&&cc<=n2)
        {
            cout<<ans<<'\n';
        }
        else
        {
            if(ca>n2)
            {
                sort(ofa.begin(),ofa.end());
                for(int i=0;i<ca-n2;++i)
                ans-=ofa[i];
                cout<<ans<<'\n';
            }
            else if(cb>n2)
            {
                sort(ofb.begin(),ofb.end());
                for(int i=0;i<cb-n2;++i)
                ans-=ofb[i];
                cout<<ans<<'\n';
            }
            else if(cc>n2)
            {
                sort(ofc.begin(),ofc.end());
                for(int i=0;i<cc-n2;++i)
                ans-=ofc[i];
                cout<<ans<<'\n';
            }
        }
    }
    return 0;
}