#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
using namespace std;
template<typename T>inline void read(T&x){
  x=0;bool f=0;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
  while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
  if(f)x=~x+1;
}
#define ll long long
const int N=2e6+5;
#define PII pair<int,int>
#define mp make_pair
#define fi first
#define se second
//int head[N],to[N],nxt[N],Cnt,in[N];
//void add(int u,int v){
//  nxt[++Cnt]=head[u];
//  to[Cnt]=v,head[u]=Cnt,in[v]++;
//}
//struct node{
//  int son[26],num,fail;
//}t[N];
//int cnt;
//void insert(string s){
////  cout<<' '<<s<<' '<<'\n';
//  int len=s.length(),now=0;
//  for(int i=0;i<len;++i){
//    int ch=s[i]-'a';
//    if(!t[now].son[ch])t[now].son[ch]=++cnt;
//    now=t[now].son[ch];
//  }
//  t[now].num++;
//}
//void build(){
//  queue<int>q;
//  for(int i=0;i<26;++i)
//    if(t[0].son[i])q.push(t[0].son[i]);
//  while(!q.empty()){
//    int u=q.front();q.pop();
//    for(int i=0;i<26;++i){
//      if(t[u].son[i]){
//        t[t[u].son[i]].fail=t[t[u].fail].son[i];
//        add(t[t[u].son[i]].fail,t[u].son[i]);
//        q.push(t[u].son[i]);
//      }else
//        t[u].son[i]=t[t[u].fail].son[i];
//    }
//  }
//  for(int i=1;i<=cnt;++i)add(0,i);
//}
//void topo(){
//  queue<int>q;
//  for(int i=0;i<=cnt;++i)if(!in[i])q.push(i);
//  while(!q.empty()){
//    int u=q.front();q.pop();
//    for(int i=head[u];i;i=nxt[i]){
//      int v=to[i];
//      t[v].num+=t[u].num;
//      in[v]--;if(!in[v])q.push(v);
//    }
//  }
//}
//ll query(string s){
//  int len=s.length(),now=0;ll res=0;
//  for(int i=0;i<len;++i){
//    int ch=s[i]-'a';
//    now=t[now].son[ch];
//    res+=t[now].num;
//  }
//  return res;
//}
int n,q;
string str,s1,s2;
map<pair<string,string>,int>m;
int main(){
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);
  cin>>n>>q;
  for(int i=1;i<=n;++i){
    cin>>s1;cin>>s2;
//    cout<<' '<<s1<<' '<<s2<<'\n';
    str="";int len=s1.length();
    m[mp(s1,s2)]++;
//    for(int j=0;j<len;++j)str=str+s1[j]+s2[j];
//    insert(str);
  }
//  build();topo();
//  printf("cnt:%d\n",cnt);
  while(q--){
    cin>>s1;cin>>s2;int len=s1.length();
    for(int j=0;j<len;++j)str=str+s1[j]+s2[j];
    string x="";ll ret=0;
    int l=0,r=0;
    for(int i=0;i<len;++i)
      if(s1[i]!=s2[i]){l=i;break;}
    for(int i=len-1;i>=0;--i)
      if(s1[i]!=s2[i]){r=i;break;}
    for(int i=0;i<=l;++i){
      for(int j=r;j<len;++j){
        string x="",y="";
        for(int k=i;k<=j;++k)x+=s1[k],y+=s2[k];
        ret+=m[mp(x,y)];
      }
    }
    cout<<ret<<'\n';
  }
  return 0;
}

// dw uv
