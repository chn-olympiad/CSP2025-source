#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    // cerr<<"!";
    ios::sync_with_stdio(0),cin.tie(0);
    int n,q; cin>>n>>q;
    pair<string,string>chan[maxn];
    for(int i=1;i<=n;++i)
    {
        cin>>chan[i].first>>chan[i].second;
        // cerr<<"!";
    }
    while(q--)
    {
        long long cnt=0;
        string s1,s2; cin>>s1>>s2;
        if(s1.size()!=s2.size())
        {
            cout<<"0\n";
            continue;
        }
        for(int i=1;i<=n;++i)
        {
            auto&cp=chan[i];
            // cerr<<"!";
            for(int j=0;j+cp.first.size()-1<s1.size();++j)
            {
                if(s1.substr(j,cp.first.size())==cp.first)
                {
                    string ns1=s1.substr(0,j)+cp.second+s1.substr(j+cp.first.size());
                    if(ns1==s2)
                    cnt++;
                }
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}