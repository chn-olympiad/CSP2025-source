#include <bits/stdc++.h>
using namespace std;
const long long N=2e5+10,L=1e7+10;
long long n,q,l[N],r[N];
string s[N][2],t[N][2];
int pi1[L],pi2[L];
void px(string &s,int *pi){
    pi[0]=0;
    for(int i=1;i<(int)s.size();i++){
        long long p=i-1;
        while(s[pi[p]]!=s[i] && pi[p]){
            p=pi[p]-1;
            //cout<<p<<'\n';
        }
        if(s[pi[p]]==s[i]){
            pi[i]=pi[p]+1;
        }else{
            pi[i]=0;
        }
    }
}
long long KMP(long long i,long long j){
    if(s[i][0].size()<r[j]-l[j]+1){
        return 0;
    }
    if(s[i][0]==t[j][0] && s[i][1]==t[j][1]){
        return 1;
    }
    string s1=s[i][0]+'#'+t[j][0];
    px(s1,pi1);
    string s2=s[i][1]+'#'+t[j][1];
    px(s2,pi2);
    long long res=0;
    for(int k=r[j];k<=t[j][0].size() && k-s[i][0].size()<=l[j];k++){
        if(pi1[s[i][0].size()+k]==s[i][0].size() && pi2[s[i][1].size()+k]==s[i][1].size()){
            res++;
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(int i=1;i<=q;i++){
        cin>>t[i][0]>>t[i][1];
        if(t[i][0].size()!=t[i][1].size()){
            cout<<0<<'\n';
            continue;
        }
        l[i]=r[i]=-1;
        for(int j=0;j<(int)(t[i][0].size());j++){
            if(t[i][0][j]!=t[i][1][j]){
                if(l[i]==-1){
                    l[i]=r[i]=j;
                }else{
                    r[i]=j;
                }
            }
            
        }
        long long res=0;
        for(int k=1;k<=n;k++){
            res+=KMP(k,i);
            //cout<<k<<' '<<i<<' '<<KMP(k,i)<<'\n';
        }
        cout<<res<<'\n';
    }
    return 0;
}