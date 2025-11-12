#include<bits/stdc++.h>
// #define int long long
#define pii pair<int,int>
using namespace std;
const int N=2e6+5;
int n,q;
string S1,S2;
int len;
int root1[N],root2[N];
int totnd;
int ch[N][26];
vector<int> ed[N];
void insert1(int &p,int p1,int id){
    if(!p)p=++totnd;
    int cur=p;
    for(int i=p1-1;i>=0;i--){
        int c=S1[i]-'a';
        if(!ch[cur][c])ch[cur][c]=++totnd;
        cur=ch[cur][c];
    }
    ed[cur].push_back(id);
}
void insert2(int &p,int p2,int id){
    if(!p)p=++totnd;
    int cur=p;
    for(int i=p2+1;i<len;++i){
        int c=S1[i]-'a';
        if(!ch[cur][c])ch[cur][c]=++totnd;
        cur=ch[cur][c];
    }
    ed[cur].push_back(id);
}
const int M=2e5+1;
bitset<M> bs1,bs2;
void query1(int p,int p1){
    int cur=p;
    for(int i=p1-1;i>=0;i--){
        int c=S1[i]-'a';
        for(auto tt:ed[cur])bs1[tt]=1;
        if(!ch[cur][c])return;
        cur=ch[cur][c];
    }
    for(auto tt:ed[cur])bs1[tt]=1;
}
void query2(int p,int p2){
    int cur=p;
    for(int i=p2+1;i<len;++i){
        int c=S1[i]-'a';
        for(auto tt:ed[cur])bs2[tt]=1;
        if(!ch[cur][c])return;
        cur=ch[cur][c];
    }
    for(auto tt:ed[cur])bs2[tt]=1;
}
unordered_map<string,int> mp;
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    int tot=0;
    for(int i=1;i<=n;++i){
        cin>>S1>>S2;
        if(S1==S2)continue;
        len=S1.length();
        string dif;
        int p1=len,p2=0;
        for(int i=0;i<len;++i){
            if(S1[i]!=S2[i]){
                p1=i;
                break;
            }
        }
        for(int i=len-1;i>=0;i--){
            if(S1[i]!=S2[i]){
                p2=i;
                break;
            }
        }
        for(int i=p1;i<=p2;++i)dif+=S1[i],dif+=S2[i];
        if(!mp.count(dif))mp[dif]=++tot;
        int id=mp[dif];
        insert1(root1[id],p1,i);
        insert2(root2[id],p2,i);
    }
    for(int i=1;i<=q;++i){
        cin>>S1>>S2;
        if(S1.length()!=S2.length()){
            cout<<"0\n";
            continue;
        }
        len=S1.length();
        string dif;
        int p1=len,p2=0;
        for(int i=0;i<len;++i){
            if(S1[i]!=S2[i]){
                p1=i;
                break;
            }
        }
        for(int i=len-1;i>=0;i--){
            if(S1[i]!=S2[i]){
                p2=i;
                break;
            }
        }
        for(int i=p1;i<=p2;++i)dif=dif+S1[i],dif=dif+S2[i];
        if(!mp.count(dif)){
            cout<<"0\n";
            continue;
        }
        int id=mp[dif];
        bs1.reset(),bs2.reset();
        query1(root1[id],p1);
        query2(root2[id],p2);
        cout<<(bs1&bs2).count()<<"\n";
    }
}
