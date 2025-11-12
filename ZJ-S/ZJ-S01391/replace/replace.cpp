#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
#define fi first
#define se second
#define mp make_pair
#define vector basic_string
#define debug1(x) cerr<<(#x)<<"="<<(x)<<" "
#define debug2(x) cerr<<(#x)<<"="<<(x)<<"\n"
constexpr int maxn=5e6+10;
namespace exstd{
    struct ACM{
        int tree[maxn][26],tot=0,fail[maxn],len[maxn];
        vector<int>v[maxn];
        void insert(string &s,int id){
            int pos=0;
            for(char c:s){
                int ch=c-'a';
                if(!tree[pos][ch])tree[pos][ch]=++tot;
                pos=tree[pos][ch];
            }
            v[pos]+=id;
            // debug1(pos);debug2(id);
            len[id]=(int)s.length();
        }
        queue<int>q;
        void getfail(){
            for(int i=0;i<26;i++){
                if(tree[0][i])q.push(tree[0][i]);
            }
            while(q.size()){
                int x=q.front();q.pop();
                for(int i=0;i<26;i++){
                    int &y=tree[x][i];
                    if(y)fail[y]=tree[fail[x]][i],q.push(y);
                    else y=tree[fail[x]][i];
                }
            }
        }
    };
}
exstd::ACM t1,t2;
// vector<int>tp1,tp2;
bool vis[maxn];
int check(string &s1,string &s2,int l,int r){
    int ans=0;
    int pos1=0,pos2=0,n=(int)s1.length();
    for(int i=0;i<n;i++){
        int ch1=s1[i]-'a',ch2=s2[i]-'a';
        pos1=t1.tree[pos1][ch1];
        pos2=t2.tree[pos2][ch2];
        // debug1(pos1);debug2(pos2);
        if(i>=r){
            // t1.clear(),t2.clear();
            int j1=pos1,j2=pos2;
            while(j1){
                for(int pos:t1.v[j1])vis[pos]=1;
                j1=t1.fail[j1];
            }
            while(j2){
                for(int pos:t2.v[j2]){
                    if(i-t2.len[pos]+1<=l)ans+=vis[pos];
                }
                j2=t2.fail[j2];
            }
            j1=pos1;
            while(j1){
                for(int pos:t1.v[j1])vis[pos]=0;
                j1=t1.fail[j1];
            }
        }
    }
    return ans;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        string a,b;cin>>a>>b;
        t1.insert(a,i);
        t2.insert(b,i);
    }
    t1.getfail();
    t2.getfail();
    while(q--){
        string s1,s2;cin>>s1>>s2;
        if((int)s1.length()!=(int)s2.length()){
            cout<<"0\n";
            continue;
        }
        int n=(int)s1.length();
        int l=-1,r=-1;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                r=i;
                if(l==-1)l=i;
            }
        }
        cout<<check(s1,s2,l,r)<<"\n";
    }
    return 0;
}
/*
g++ -std=c++14 -Wall -Wextra -Wshadow -Wconversion -fsanitize=address,undefined
*/