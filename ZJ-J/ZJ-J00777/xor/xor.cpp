#include<bits/stdc++.h>
const int slen=2e5+10;
using namespace std;
int a[slen],res[slen];
struct info{
  int st,end;
};info t[slen];
int l=1;
bool cmp(info x,info y){
  if(x.end!=y.end)return x.end<y.end;
  return x.st<y.st;
}
int main(){
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  int n,k,ans=0;
  cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>a[i];
  if(k==1){
  	for(int i=1;i<=n;i++){
  	  if(a[i]==1)ans++;
	}
  }
  else if(k==0){
  	for(int i=1;i<=n;i++){
  	  if(a[i]==0)ans++;
  	  if(a[i]==1&&a[i+1]==1){
  	    ans++;
  	    i++;
	  }
	}
  }
  else{
  	for(int i=1;i<=n;i++)res[i]=res[i-1]^a[i];
  	for(int i=1;i<=n;i++){
  	  for(int j=i;j>=1;j--){
  	    int d=res[i]^res[j];
  	  	if(d==k){
  	  	  t[l].st=j;t[l].end=i;
  	  	  l++;
  	  	  break;
  	  	  //cout<<j<<' '<<i<<' '<<d<<endl;
		}
	  }
	}
	sort(t+1,t+l,cmp);
	int time=t[1].end;ans=1;
	for(int i=2;i<=l;i++){
	  if(t[i].st>=time){
	  	ans++;
	  	time=t[i].end;
	  }
	}
  }
  cout<<ans;
  return 0;
}