#include <bits/stdc++.h>
using namespace std;
constexpr int N=2e5+5,M=5e6+6;
int n,m,cnt;
map<string,int>id;
struct ACAM{
    int trie[M][27],fail[M],cnt,rt[N],f[M];
    void insert(int id,string s){
        if(!rt[id])rt[id]=++cnt;
        int p=rt[id];
        for(char c:s){
            if(!trie[p][c-'a'])trie[p][c-'a']=++cnt;
            p=trie[p][c-'a'];
        }
        f[p]++;
    }
    void build(int id){
        queue<int>q;
        fail[rt[id]]=rt[id];
        for(int i=0;i<=26;i++){
            if(!trie[rt[id]][i])trie[rt[id]][i]=rt[id];
            else fail[trie[rt[id]][i]]=rt[id],q.push(trie[rt[id]][i]);
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            f[x]+=f[fail[x]];
            for(int i=0;i<=26;i++){
                if(!trie[x][i])trie[x][i]=trie[fail[x]][i];
                else fail[trie[x][i]]=trie[fail[x]][i],q.push(trie[x][i]);
            }
        }
    }
    int query(int id,string s){
        int ans=0,p=rt[id];
        for(char c:s){
            if(!p)break;
            p=trie[p][c-'a'];
            ans+=f[p];
        }
        return ans;
    }
}acam;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s1,s2;cin>>s1>>s2;
        if(s1==s2)continue;
        int st=-1,ed=s1.size();
        while(s1[st+1]==s2[st+1])st++;
        while(s1[ed-1]==s2[ed-1])ed--;
        string s,s0;
        for(int j=0;j<=st;j++)s.push_back(s1[j]);
        s.push_back('z'+1);
        for(int j=ed;j<s1.size();j++)s.push_back(s1[j]);
        for(int j=st+1;j<ed;j++)s0.push_back(s1[j]);
        for(int j=st+1;j<ed;j++)s0.push_back(s2[j]);
        if(!id[s0])id[s0]=++cnt;
        acam.insert(id[s0],s);
    }
    for(int i=1;i<=cnt;i++)acam.build(i);
    for(int i=1;i<=m;i++){
        string s1,s2;cin>>s1>>s2;
        if(s1.size()!=s2.size()){cout<<"0\n";continue;}
        int st=-1,ed=s1.size();
        while(s1[st+1]==s2[st+1])st++;
        while(s1[ed-1]==s2[ed-1])ed--;
        string s,s0;
        for(int j=0;j<=st;j++)s.push_back(s1[j]);
        s.push_back('z'+1);
        for(int j=ed;j<s1.size();j++)s.push_back(s1[j]);
        for(int j=st+1;j<ed;j++)s0.push_back(s1[j]);
        for(int j=st+1;j<ed;j++)s0.push_back(s2[j]);
        cout<<acam.query(id[s0],s)<<'\n';
    }
    return 0;
}