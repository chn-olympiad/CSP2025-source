#include<bits/stdc++.h>
using namespace std;
const int slen=1e6+10;
int ans[slen],n=0;
bool cmp(int a,int b){
  return a>b;
}
int main(){
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  string str;
  cin>>str;
  for(int i=0;i<str.size();i++){
  	if(str[i]>='0'&&str[i]<='9'){
  	  n++;
  	  ans[n]=str[i]-'0';
	}
  }
  sort(ans+1,ans+n+1,cmp);
  for(int i=1;i<=n;i++)printf("%d",ans[i]);
  return 0;
}