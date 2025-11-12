#include<bits/stdc++.h>
using namespace std;
const int N=200005;
string str[N][2],Q[N][2];
int n,q;
namespace baoli{
    const int base1=131,mod1=998244353,base2=2011,mod2=1000000007;
    typedef pair<int,int> HS;
    HS gethash(const string& s){
        int hash1=0,hash2=0;
        for(char c:s){
            hash1=(1ll*hash1*base1%mod1+c-'a'+1)%mod1;
            hash2=(1ll*hash2*base2%mod2+c-'a'+1)%mod2;
        }
        return make_pair(hash1,hash2);
    }
    int main(){
        map<pair<HS,HS>,int> mm;
        for(int i=0;i<n;++i) ++mm[make_pair(gethash(str[i][0]),gethash(str[i][1]))];
        for(int i=0;i<q;++i){
            const string s=Q[i][0],t=Q[i][1];
            if((int)s.size()!=(int)t.size()){
                cout << "0\n";
                continue;
            }
            const int m=(int)s.size();
            int L=0,R=m;
            while(L<m && s[L]==t[L]) ++L;
            while(R>0 && s[R-1]==t[R-1]) --R;
            long long ans=0;
            for(int l=0;l<=L;++l){
                int hash1=0,hash2=0,Hash1=0,Hash2=0;
                for(int r=l+1;r<=m;++r){
                    hash1=(1ll*hash1*base1%mod1+s[r-1]-'a'+1)%mod1;
                    hash2=(1ll*hash2*base2%mod2+s[r-1]-'a'+1)%mod2;
                    Hash1=(1ll*Hash1*base1%mod1+t[r-1]-'a'+1)%mod1;
                    Hash2=(1ll*Hash2*base2%mod2+t[r-1]-'a'+1)%mod2;
                    if(R<=r) ans+=mm[make_pair(make_pair(hash1,hash2),make_pair(Hash1,Hash2))];
                }
            }
            cout << ans << '\n';
        }
        return 0;
    }
}
namespace B{
    int pos[N][2];
    vector<int> vec[N];
    vector<pair<int,pair<int,int>>> vev[N];
    long long ans[N];
    int main(){
        map<pair<int,int>,int> mm;
        for(int i=0;i<n;++i){
            pos[i][0]=int(find(str[i][0].begin(),str[i][0].end(),'b')-str[i][0].begin());
            pos[i][1]=int(find(str[i][1].begin(),str[i][1].end(),'b')-str[i][1].begin());
            vec[pos[i][0]].push_back(i);
        }
        for(int i=0;i<q;++i){
            const int s=int(find(Q[i][0].begin(),Q[i][0].end(),'b')-Q[i][0].begin()),t=int(find(Q[i][1].begin(),Q[i][1].end(),'b')-Q[i][1].begin()),m=(int)Q[i][0].size();
            if((int)Q[i][1].size()!=m) ans[i]=0;
            else vev[s].push_back(make_pair(i,make_pair(s-t,m-s)));
        }
        for(int s=0;s<=n;++s){
            for(int i:vec[s]) ++mm[make_pair(pos[i][0]-pos[i][1],(int)str[i][0].size()-pos[i][0])];
            for(auto P:vev[s]){
                for(int j=0;j<=P.second.second;++j) ans[P.first]+=mm[make_pair(P.second.first,j)];
            }
        }
        for(int i=0;i<q;++i) cout << ans[i] << '\n';
        return 0;
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    int L1=0,L2=0;
    for(int i=0;i<n;++i){
        cin >> str[i][0] >> str[i][1];
        L1+=(int)str[i][0].size()+(int)str[i][1].size();
    }
    for(int i=0;i<q;++i){
        cin >> Q[i][0] >> Q[i][1];
        L2+=(int)Q[i][0].size()+(int)Q[i][1].size();
    }
    if(L1<=2000 && L2<=2000) return baoli::main();
    return B::main();
}