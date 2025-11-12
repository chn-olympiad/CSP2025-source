#include<bits/stdc++.h>
const int slen=1e4+10,mod=998244353;
using namespace std;
int a[slen],ans=0,n;
void dfs(int maxx,int sum,int deep,int res,bool f){
  if(deep>n+1)return;
  if(sum>maxx*2&&res>=3&&f==0){
  	f=1;
  	ans=(ans+1)%mod;
  	//cout<<maxx<<' '<<sum<<' '<<deep<<endl;
  }
  dfs(maxx,sum,deep+1,res,f);
  dfs(max(maxx,a[deep]),sum+a[deep],deep+1,res+1,0);
}
int main(){
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  bool f1=0;
  cin>>n;
  for(int i=1;i<=n;i++){
  	cin>>a[i];
  	if(a[i]!=1)f1=1;
  }
  if(f1==0){
  	for(int i=3;i<=n;i++){
  	  int res1=1,res2=1;
  	  for(int j=n;j>=i;j--)res1=(res1*j)%mod;
  	  for(int j=i;j>=1;j--)res2=(res2*j)%mod;
  	  cout<<res1/res2;
  	  return 0;
	}
  }
  dfs(0,0,1,0,0);
  cout<<ans;
  return 0;
}