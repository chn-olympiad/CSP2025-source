#include<bits/stdc++.h>
bool MED;
using namespace std;
#define ll long long
const int N=1e5+5;
ll a[N][4],n,s[4],w[4],b[N];
struct node{int p;};
bool operator>(node x,node y){
  return a[x.p][1]-a[x.p][2]>a[y.p][1]-a[y.p][2];
}
priority_queue<node,vector<node>,greater<node>> pq;
void solve(){
  cin>>n;memset(b,0,sizeof b),memset(w,0,sizeof w);
  for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)cin>>a[i][j];
  while(!pq.empty())pq.pop();ll res=0;
  for(int i=1;i<=n;i++){
    memset(s,0,sizeof s);
    for(int j=1;j<=3;j++)s[j]=j;
    sort(s+1,s+4,[&](int x,int y){return a[i][x]>a[i][y];});
    w[s[1]]++;swap(a[i][s[1]],a[i][1]);b[i]=s[1];res+=a[i][1];
    if(a[i][2]<a[i][3])swap(a[i][2],a[i][3]);
  }
  if(w[1]<=n/2&&w[2]<=n/2&&w[3]<=n/2){cout<<res<<"\n";return ;}
  int c=0;for(int i=1;i<=3;i++)if(w[i]>w[c])c=i;
  for(int i=1;i<=n;i++)if(b[i]==c)pq.push({i});int k=w[c]-n/2;
  while(k--){
    auto u=pq.top();pq.pop();
    res-=a[u.p][1]-a[u.p][2];
  }cout<<res<<"\n";
}
bool MST;
int main(){
  //fprintf(stderr,"%.3lf MB\n",(&MED-&MST)/1048576.0);
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);
  int TC;cin>>TC;while(TC--){solve();}
  return 0;
}
