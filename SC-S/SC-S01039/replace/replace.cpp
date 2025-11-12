#include<bits/stdc++.h>
using namespace std;
bool Mbe;
const int N=5e6+7;
#define pii pair<int,int>
int n,m,vis[N];//,ans[N]
struct trie{
    int ch[N][26],idcnt,fail[N],dep[N];
    vector<int>cnt[N];
    void insert(string &s,int id){
        int len=s.length(),u=0;
        //cout<<"insert "<<s<<' '<<id<<'\n';
        for(int i=0;i<len;i++){
            int v=s[i]-'a';//cout<<u<<'\n';
            if(!ch[u][v])ch[u][v]=++idcnt,dep[ch[u][v]]=dep[u]+1;
            u=ch[u][v];
        }
        cnt[u].push_back(id);//cout<<"ineset fine "<<u<<'\n';
    }
    void build(){
        queue <int> q;for(int i=0;i<26;i++)if(ch[0][i])q.push(ch[0][i]),fail[ch[0][i]]=0;
        while(!q.empty()){
            int u=q.front();q.pop();sort(cnt[u].begin(),cnt[u].end());
            for(int v=0;v<26;v++){
                if(ch[u][v])fail[ch[u][v]]=ch[fail[u]][v],q.push(ch[u][v]);
                else ch[u][v]=ch[fail[u]][v];
            }
        }
    }
}S,T;
// vector<pii>ans[N];
// int loc[N];
int query(string &s,string &t,int l,int r){
    int u1=0,u2=0,len=s.length(),ans=0;
    vector<int>stk;
    for(int i=0;i<r;i++){
        int v1=s[i]-'a',v2=t[i]-'a';
        u1=S.ch[u1][v1],u2=T.ch[u2][v2];
    }
    vector<pii> que;
    for(int i=r;i<len;i++){
        int v1=s[i]-'a',v2=t[i]-'a';
        u1=S.ch[u1][v1],u2=T.ch[u2][v2];
        int tmp1=u1,tmp2=u2;
        while(tmp1&&tmp2){//&&!(vis[tmp1]&&vis[tmp2]&&tmp1==tmp2)
//        	cout<<"* "<<tmp1<<' '<<tmp2<<'\n';
        	if(S.dep[tmp1]<i-l+1||T.dep[tmp2]<i-l+1)break;
            if(S.dep[tmp1]>T.dep[tmp2]){tmp1=S.fail[tmp1];continue;}
            if(S.dep[tmp1]<T.dep[tmp2]){tmp2=T.fail[tmp2];continue;}
            que.push_back({tmp1,tmp2});tmp1=S.fail[tmp1],tmp2=T.fail[tmp2];
        }
        for(int j=0;j<(int)que.size();j++){
            int lt=0,x=que[j].first,y=que[j].second;
//            cout<<"S ";for(int w:S.cnt[x]) couOt<<w<<' ';
//            cout<<"\nT ";for(int w:T.cnt[y])cout<<w<<' ';
//            cout<<'\n';
            for(int ls=0;ls<(int)S.cnt[x].size();ls++){
                while(lt<(int)T.cnt[y].size()&&T.cnt[y][lt]<S.cnt[x][ls]){lt++;}
                if(S.cnt[x][ls]==T.cnt[y][lt])ans++;
            }
        }
        vector<pii>().swap(que);
    }
    return ans;
}
const int M=2e5+7;
// string a[M];
bool Med;
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
   freopen("replace.in","r",stdin);
   freopen("replace.out","w",stdout);
    cin>>n>>m;
    string s,t;
    for(int i=1;i<=n;i++){
        cin>>s>>t;
        // for(int j=0;j<len;j++)a[i]+=s[j],a[i]+=t[j];
        S.insert(s,i),T.insert(t,i);
    }
    S.build();T.build();
    for(int i=1;i<=m;i++){
        cin>>s>>t;int l=N,r=0,len=s.length();//string tmp;
        for(int j=0;j<len;j++){
            if(s[j]!=t[j])l=min(l,j),r=max(r,j);
        }
        // for(int j=l;j<=r;j++)tmp+=s[j],tmp+=t[j];
        cout<<query(s,t,l,r)<<'\n';
    }
    
    // for(int i=1;i<=n;i++)query(a[i]);
    // for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
    cerr<<fabs(&Mbe-&Med)/1048576.0<<"Mb\n";
    return 0;
}
/*
1 1
aaa aaa
a a

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/