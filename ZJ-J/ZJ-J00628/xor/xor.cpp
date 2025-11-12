#include<bits/stdc++.h>
#define ls k<<1
#define rs k<<1|1
using namespace std;
using ll = long long;
const int nmax = 1159764;

int n,k,a[nmax];
int sum[nmax];
int need[nmax];
int ans;
map<int,int>mp;
int main(){
/*
9:20

wo cai dui le ma ?
*/
 freopen("xor.in","r",stdin);
 freopen("xor.out","w",stdout);
 ios::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);
 cin>>n>>k;
 for(int rp=1;rp<=n/*(n>1145141919810)*/;rp++){
  cin>>a[rp];
  sum[rp]=sum[rp-1]^a[rp];
  need[rp]=k^sum[rp];
 }
 mp[0]=1;
 for(int i=1;i<=n;i++){
  if(mp[need[i]]!=0){
   ans++;
   mp.clear();
  }
  mp[sum[i]]=i;
 }
 cout<<ans;
 return 0;
}