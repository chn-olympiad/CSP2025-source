#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int nmax = 1159764;

int n,m,mp[114][514];
int Rp_add;
int sc[114];
int main(){
 freopen("seat.in","r",stdin);
 freopen("seat.out","w",stdout);
 ios::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);
 cin>>n>>m;
 cin>>Rp_add;sc[1]=Rp_add;
 for(int rp=2;rp<=n*m;rp++){
  cin>>sc[rp];
 }
 sort(sc+1,sc+1+n*m);
 int lie=1,hang=1;int op=1;
 int now=n*m;
 for(int j=1;j<=m;j++){
  if(j&1){
   for(int i=1;i<=n;i++){
   	mp[i][j]=sc[now];now--;
   }
  }else{
   for(int i=n;i;i--){
   	mp[i][j]=sc[now];now--;
   }
  }
 }
 for(int i=1;i<=m;i++){
  for(int j=1;j<=n;j++){
   if(mp[j][i]==Rp_add){
   	cout<<i<<" "<<j;
   	return 0;
   }
  }
 }
 return 0;
}