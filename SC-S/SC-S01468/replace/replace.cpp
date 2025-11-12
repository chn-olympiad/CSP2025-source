#include<bits/stdc++.h>
#define int long long
#define lop(i,a,b) for(int i=a;i<=b;i++)
#define pol(i,a,b) for(int i=a;i>=b;i--)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout),ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define mset(a,v) memset(a,v,sizeof a)
#define pb push_back
#define umap unordered_map
using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long ull;
bool c1;
int n,q;
const int NN=2e5+5,Base=13331,SS=5e6+5;
umap<ull,umap<ull,int> >mp;
int cnt,rt[NN],ans[NN];
struct Node{
    string s;
    int id;
};
vector<Node> vr[NN],vq[NN];
Node Deal(string s1,string s2){
    int m=s1.size();
    int L=m+1,R=-1;
    lop(j,0,m-1){
        if(s1[j]!=s2[j]){
            L=j;
            break;
        }
    }
    pol(j,m-1,0){
        if(s1[j]!=s2[j]){
            R=j;
            break;
        }
    }
    ull hsh1=0,hsh2=0;
    lop(i,L,R){
        hsh1=hsh1*Base+s1[i];
        hsh2=hsh2*Base+s2[i];
    }
    if(!mp[hsh1][hsh2])mp[hsh1][hsh2]=++cnt;
    string X;
    if(R<L){
        X=s1;
    }else{
        lop(i,0,L-1)X+=s1[i];
        X+='z'+1;
        lop(i,R+1,m-1)X+=s1[i];
    }
    
    return {X,mp[hsh1][hsh2]};
}
struct ACAM{
    signed trie[SS][27];
    int res[SS],fail[SS];
    int tot;
    void Clear(){
        lop(i,0,tot){
            res[i]=0,fail[i]=0;
            lop(j,0,26)trie[i][j]=0;
        }
        tot=0;
        return;
    }
    void Insert(string s){
        // cout<<s<<"\n";
        int p=0;
        // assert(s.size());
        for(char ch:s){
            int o=ch-'a';
            if(!trie[p][o])trie[p][o]=++tot;
            // cout<<p<<"---"<<o<<"-->"<<trie[p][o]<<"@@\n";
            p=trie[p][o];
        }
            res[p]++;
        return;
    }
    void Build(){
        queue<int> q;
        lop(i,0,26)if(trie[0][i])q.push(trie[0][i]),fail[trie[0][i]]=0;
        while(!q.empty()){
            int f=q.front();q.pop();
            assert(f);
            // cerr<<f<<"@";
            res[f]+=res[fail[f]];
            lop(i,0,26){
                if(trie[f][i]){
                    fail[trie[f][i]]=trie[fail[f]][i];
                    q.push(trie[f][i]);
                }else{
                    trie[f][i]=trie[fail[f]][i];
                }
            }
        }
        return;
    }
    int Query(string s){
        int p=0,ans=0;
        for(char ch:s){
            ans+=res[p];
            // cout<<res[p]<<" ";
            p=trie[p][ch-'a'];
        }
        // cout<<res[p]<<"\n";
        ans+=res[p];
        return ans;
    }
}acam;
int qid;
void Work(){
    cin>>n>>q;
    lop(i,1,n){
        string s1,s2;cin>>s1>>s2;
        Node o=Deal(s1,s2);
        // cout<<o.id<<"######%%\n";
        vr[o.id].pb({o.s,0});
    }
    lop(i,1,q){
        string t1,t2;cin>>t1>>t2;
        Node o=Deal(t1,t2);
        vq[o.id].pb({o.s,i});
    }
    lop(i,1,cnt){
        acam.Clear();
        for(Node o:vr[i]){
            acam.Insert(o.s);
        }
        acam.Build();
        // if(i==10824){
        //     cout<<acam.tot<<"#\n";
        //     lop(i,0,acam.tot){
        //         lop(j,0,26){
        //             if(acam.trie[i][j])cout<<i<<"--"<<(char)(j+'a')<<"-->"<<acam.trie[i][j]<<"\n";
        //         }
        //     }
        // }
        for(Node o:vq[i]){
            ans[o.id]=acam.Query(o.s);
        }
    }
    lop(i,1,q){
        cout<<ans[i]<<"\n";
    }
    return;
}
bool c2;
signed main(){
    // int Time=clock();
    // cerr<<abs(&c1-&c2)/1024.0/1024<<"\n";
    file("replace");
    Work();
    // cerr<<"\n"<<1.0*(clock()-Time)/CLOCKS_PER_SEC;
    return 0;
}