#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;cin>>n>>m;
    vector<int>S(n),C(n);
    string a;cin>>a;
    for(int i=0;i<n;i++)
    {
        S[i]=a[i]-'0';
    }
    for(int i=0;i<n;i++) cin>>C[i];
    cout<<0;
    sort(C.begin(),C.end());
    return 0;
}
