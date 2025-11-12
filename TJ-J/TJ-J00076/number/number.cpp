#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  string s;
  cin>>s;
  int a=0;
  char c[s.size()+1]={ };
  vector<int> k(s.size()+1);
  for(int i=0;i<s.size();i++){
  c[i]=s[i];
  }
  for(int i=0;i<s.size();i++){
  if(char(c[i])=='0' or char(c[i])=='1' or char(c[i])=='2' or char(c[i])=='3' or char(c[i])=='4' or char(c[i])=='5' or char(c[i])=='6' or char(c[i])=='7' or char(c[i])=='8' or char(c[i])=='9') {
  k[a]=c[i]-48;
  a++;
  }
  }
  sort(k.begin(),k.end());
  for(int i=k.size()-1;i>s.size()-a;i--){
  	cout<<k[i];
  }
return 0;
}
