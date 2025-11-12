#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=200005,maxm=5000005;
int N,Q;
string a[maxn],b[maxn],c[maxn],d[maxn];
vector<int> S[maxm];
int trie[maxm][26],tot=1;
void ins(string s,int id){
    int x=1;
    for(char i:s){
        if(!trie[x][i-'a']) trie[x][i-'a']=++tot;
        x=trie[x][i-'a'];
    }
    S[x].pb(id);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>Q;
    for(int i=1;i<=N;i++) {
        string p,q;cin>>p>>q;
        int l=0,r=p.size()-1;
        while(p[l]==q[l]) l++;
        while(p[r]==q[r]) r--;
        string s;
        for(int j=l;j<=r;j++) s+=p[j],s+=q[j];
        for(int j=l-1;j>=0;j--) a[i]+=p[j];
        for(int j=r+1;j<p.size();j++) b[i]+=p[j];
        ins(s,i);
    }
    for(int i=1;i<=Q;i++) {
        string p,q;cin>>p>>q;
        if(p.size()!=q.size()){
            puts("0");
            continue;
        }
        int l=0,r=p.size()-1;
        while(p[l]==q[l]) l++;
        while(p[r]==q[r]) r--;
        int x=1;
        for(int j=l;j<=r;j++){
            x=trie[x][p[j]-'a'];
            x=trie[x][q[j]-'a'];
        }
        if(!x){puts("0");continue;}
        for(int j=l-1;j>=0;j--) c[i]+=p[j];
        for(int j=r+1;j<p.size();j++) d[i]+=q[j];
        int ans=0;
        for(int p:S[x]){
            bool flg=1;
            if(c[i].size()<a[p].size()) flg=0;
            if(d[i].size()<b[p].size()) flg=0;
            if(flg){
                for(int j=0;j<a[p].size();j++) flg&=(a[p][j]==c[i][j]);
                for(int j=0;j<b[p].size();j++) flg&=(b[p][j]==d[i][j]);
            }
            if(flg) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}