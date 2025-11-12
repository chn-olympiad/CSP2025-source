#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PLL;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
const ll BASE=211;
const ll N=2e5+5,L=5e6+5;

int n,q;
string s[N][2],t[N][2];

ll pw[N];
vector<ll> Hash[N][2],Hash2[2];

map<ll,ll> mp1,mp2;

void inith(vector<ll> &v,string s){
    int l=s.size()-1; v={0};
    for(int i=1;i<=l;i++) v.push_back((v[i-1]*BASE+s[i])%MOD);
}

ll geth(vector<ll> v,int l,int r){
    return (v[r]-v[l-1]*pw[r-l]%MOD+MOD)%MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
    }
    for(int i=1;i<=q;i++){
        int ans=0;
        cin>>t[i][1]>>t[i][2];
        for(int j=0;j<t[i][1].size();j++){
            for(int k=1;k<=n;k++){
                int l=s[k][1].size();
                if(t[i][1].substr(j,l)==s[k][1]&&t[i][2].substr(j,l)==s[k][2]){
                    if(t[i][1].substr(0,j)+s[k][2]+t[i][1].substr(j+l-1)==t[i][2]) ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
}