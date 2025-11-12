#include<bits/stdc++.h>
using namespace std;
#define F(i,l,r) for(int i=(l);i<=(r);i++)
#define pb push_back
const int num=7e5;
int n,q,tot;
string a,b;
int c[1000005];
struct node{
    int cnt;
    int ch[625];
    int f;
    bool ha[625];
    int tag;
    int len;
}e;
vector<node>t;
void ins(int x){
    int j=0;
    F(i,0,x-1){
        int p=c[i];
        t[j].ha[p]=1;
        if(!t[j].ch[p]){
            t[j].ch[p]=++tot,t.pb(e);
            t[tot].len=t[j].len+1;
        }
        j=t[j].ch[p];
        if(i==x-1)t[j].cnt++;
    }
}
void getfail(){
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int p=q.front();q.pop();
        int fai=t[p].f;
        F(i,0,624)if(!t[p].ha[i])t[p].ch[i]=t[fai].ch[i];
        else {
            t[t[p].ch[i]].f=p==0?0:t[fai].ch[i];
            q.push(t[p].ch[i]);
        }
    }
}
bool ckp[num],cks[num];
int gets(){
    cin>>a>>b;
    int l=a.size();
    F(i,0,l-1)c[i]=(a[i]-'a')*26+(b[i]-'a');
    if(a[0]==b[0])ckp[0]=1;
    F(i,1,l-1)ckp[i]=ckp[i-1]&(a[i]==b[i]);
    if(a[l-1]==b[l-1])cks[l-1]=1;
    for(int i=l-2;i>=0;i--)cks[i]=cks[i+1]&(a[i]==b[i]);
  
    return l;
}
int tp=0;
int find(int x){
    int j=0;
    int ans=0;
    tp++;
    F(i,0,x-1){
        int p=c[i];
        if(!t[j].ha[p])j=t[j].f;
        else j=t[j].ch[p];
        int dp=t[j].len;
        if((i-t[j].len+1==0||ckp[i-t[j].len])&&(i==x-1||cks[i+1])){
            if(t[j].tag!=tp){
            t[j].tag=tp;
            ans+=t[j].cnt;
            }
        }
    }
    int i=x-1;
    while(j){
        j=t[j].f;
        int dp=t[j].len;
        if((i-t[j].len+1==0||ckp[i-t[j].len])&&(i==x-1||cks[i+1])){
            if(t[j].tag!=tp){
            t[j].tag=tp;
            ans+=t[j].cnt;
            }
        }
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    t.pb(e);
    F(i,1,n){
        ins(gets());
    }
   
    getfail();
    F(i,1,q){
        cout<<find(gets())<<'\n';
    }
}